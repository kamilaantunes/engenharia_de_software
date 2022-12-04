import express from 'express';

import {index, store, show, destroy, update} from '../controlers/produtos.controler.js'

const produtosRoutes = express.Router();

produtosRoutes.post('/', store);
produtosRoutes.get('/', index);
produtosRoutes.get('/:id', show);
produtosRoutes.put('/:id', update);
produtosRoutes.delete('/:id', destroy);

export default produtosRoutes;