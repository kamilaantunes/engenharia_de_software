import express from 'express';

import produtosRoutes from './src/routes/produtos.routes.js';

const port = 3001;

const app = express();

// Interpretação de respostas
app.use(express.json());

app.get('/', (req, res) => {
    res.send('Fufando!')
});

app.use('/produtos', produtosRoutes)

app.listen(port, () => {
    console.log('Servidor iniciado!');
});

/*
    • GET /produtos -> lista de produtos
    • GET /produtos/:id -> retorna dados de um produto específico
    • POST /produtos -> cria novo produto
    • PUT /produtos/:id -> atualiza um produto específico
    • DELETE /produtos/:id -> exclui um produto específico
*/