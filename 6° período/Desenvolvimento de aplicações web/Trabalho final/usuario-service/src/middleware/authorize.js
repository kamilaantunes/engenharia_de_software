import jwt from 'jsonwebtoken';
import { Usuario } from '../models/usuario.model.js';

function authorize(req, res, next){
    const token = req.headers['token'];

    // console.log(token);

    if (!token){
        return res.status(401).json({
            message: 'Token não informado!'
        });
    }

    jwt.verify(token, 'SECRET', async (err, decoded) => {
        if (err){
            return res.status(500)
                .json({message: 'Falha ao autenticar o token!'})
        }

        const usuario = await Usuario.findByPk(decoded.idUsuario);

        if (usuario){
            req.usuario = usuario.get();
        }

        next();
    });
}

export default authorize;