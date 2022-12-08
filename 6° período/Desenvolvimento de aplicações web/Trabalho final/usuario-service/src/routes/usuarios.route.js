import express from 'express';

import {store, auth, yo} from '../controllers/usuarios.controller.js';
import authorize from '../middleware/authorize.js'

const usuariosRoutes = express.Router();

usuariosRoutes.post('/', store);
usuariosRoutes.get('/yo', authorize, yo);
usuariosRoutes.post('/auth', auth);

export default usuariosRoutes;