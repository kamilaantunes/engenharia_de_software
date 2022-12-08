import express from 'express';
import httpProxy from 'express-http-proxy';
import authorize from './src/middleware/authorize.js';

const port = 2999;

const app = express();

app.use(express.json());
app.use(authorize)

const SERVICES_API_URL = {
    USUARIOS: 'http://localhost:3002',
    PRODUTOS: 'http://localhost:3001',
}

function selecionarProxyHost(req){
    if (req.path.startWith('/produtos')){
        return SERVICES_API_URL.PRODUTOS;
    } else if (req.startWith('/usuarios')){
        return SERVICES_API_URL.USUARIOS;
    }
};

app.use((req, res, next) => {
    console.log(req.path, selecionarProxyHost(req));
    httpProxy(selecionarProxyHost)(req, res, next);
});

app.listen(port, () => {
    console.log('Serviço de API Gateway iniciado.')
})