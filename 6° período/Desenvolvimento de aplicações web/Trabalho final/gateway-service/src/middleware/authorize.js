import axios from 'axios';

async function tokenValido(token){
    try {
        const result = await axios.get('http://localhost:3002/usuarios/yo', {
            headers: {
                token: token,
            },
        });

        return result.data.id;

    } catch(error){
        // console.error(error);

        return false;
    }
    
}

async function authorize(req, res, next){
    if (req.path.startWith('/usuario')){
        return next();
    }

    const token = req.headers['token'];

    if (!token || !(await tokenValido(token))){
        return res.status(401).json({
            message: 'Token inválido!'
        });
    }
    next();
}

export default authorize;