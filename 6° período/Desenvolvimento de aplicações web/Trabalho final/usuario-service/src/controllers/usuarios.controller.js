import {Usuario} from '../models/usuario.model.js';
import bcryp from 'bcrypt';
import jwt from 'jsonwebtoken';

async function store(req, res){
    // res.json(req.body)
    const usuario = await Usuario.create(req.body);
    res.json(usuario);
}

async function auth(req, res){
    const {email, senha} = req.body;

    if (!(email && senha)){
        return res.status(400).send("Informe o e-mail e a senha!");
    }

    const usuario = await Usuario.findOne({where: {email: email}})

    if (!(usuario || !(bcryp.compare(senha, usuario.senha)))){
        return res.status(400).send('Usuário ou senha incorretos!');
    }

    const token = jwt.sign({idUsuario: usuario.id}, 'SECRET', {
        expiresIn: '1d',
    });

    return res.status(200).json({
        token,
        ...usuario.get(),
    })

}

async function yo(req, res){
    return res.status(200).send("Hellooo!");
}

export {store, auth, yo};