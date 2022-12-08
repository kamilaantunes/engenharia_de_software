import express from 'express';
import usuariosRoutes from './src/routes/usuarios.route.js';

const port = 3002;


const app = express();

app.use(express.json());

app.get('/', (req, res) => {
    res.send('Fufando!')
});

app.use('/usuarios', usuariosRoutes);

app.listen(port, () => {
    console.log('Servidor de users foi iniciado!');
});