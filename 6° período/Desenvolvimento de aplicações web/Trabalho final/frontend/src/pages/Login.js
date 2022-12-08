import { useState } from "react"
import { useNavigate } from "react-router-dom";
import {createUsuario, auth} from "../service/UsuarioService.js"

import './Login.css';

export default function Login(){
    const [usuario, setUsuario] = useState({email: '', senha: ''});
    // const [email, setEmail] = useState('');
    const navigate = useNavigate();

    async function autenticarUsuario(event){
        event.preventDefault();
        // console.log(usuario);
        await auth(usuario);

        navigate('/');

        return false;
    }

    function handleInput(event){
        const target = event.target;
        const value = target.value;
        const name = target.name;

        setUsuario((inforAnteriores) => ({
            ...inforAnteriores,
            [name] : value,
        }));
    }

    async function Cadastrar(){
        await createUsuario(usuario);
        await auth(usuario);
        navigate('/');
    }

    return (
        <div className="d-flex align-items-center text-center form-container">
            <form className="form-signin" onSubmit={autenticarUsuario}>
                <img className="mb-4" src="https://th.bing.com/th/id/R.099753e0b751424202b5224d97df32d2?rik=v%2bKXDODFHAKo0A&riu=http%3a%2f%2fportal.utfpr.edu.br%2ficones%2fcabecalho%2flogo-utfpr%2f%40%40images%2fimage.png&ehk=DP3PsrmxZs5VJvQCLyLH1fFJp8mIopBDXMnw18eRh8Q%3d&risl=&pid=ImgRaw&r=0" alt="" height={120} />

                <h2 className="h3 mb-3 fw-normal"> Autenticação </h2>

                <div className="form-floating">
                    <input
                        type="text"
                        className="form-control" 
                        name="email"
                        id="floatingInput"
                        placeholder="E-mail"
                        onChange={handleInput}
                    />
                    <label htmlFor="floatingInputl">Email</label>
                </div>
                    
                <div className="form-floating">
                    <input
                            type="password"
                            className="form-control"
                            name='senha'
                            id="floatingPassword"
                            placeholder="Senha"
                            onChange={handleInput}
                    />
                    <label for="inputPassword" htmlFor="floatingPassword"> Senha </label>
                </div>

                <button type="submit" className="btn btn-primary">
                    Entrar
                </button>
                &nbsp;&nbsp;&nbsp;
                <button
                    type="button"
                    className="btn btn-secondary"
                    onClick={Cadastrar}
                >
                    Cadastrar
                </button>

                <p className="mt-5 mb-3 text-muted">&copy; Kamila Antunes</p>

            </form>
        </div>
    )
}