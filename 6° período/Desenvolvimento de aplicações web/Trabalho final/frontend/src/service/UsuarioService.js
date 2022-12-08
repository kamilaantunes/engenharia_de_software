import api from './Api'

async function createUsuario({email, senha}){
    const response = await api.post("/usuarios", {email, senha});
    
    return response.data;
}

async function auth({email, senha}){
    const response = await api.post('/usuarios/path', {email, senha});

    api.defaults.headers['token'] = response.data.token

    return response;
}

export {createUsuario, auth};