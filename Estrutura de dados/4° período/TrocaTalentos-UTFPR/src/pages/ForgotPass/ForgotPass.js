import './ForgotPass.css';

function ForgotPass() {
    function recuperarSenha(form) {
        //do something
    }

    return (
        <div className="container">
            <div className="quad">
                <div className='login-message'>
                    <b><h2 > Recuperar Senha </h2></b>
                </div>
                <form onSubmit={recuperarSenha} className="form-box">
                    <input className='input' type="text" placeholder='email' />
                    <input className='input' type="password" name="passoword" placeholder='password' />
                    <input className='input' type="password" name="passoword" placeholder='confirmar senha' />
                    <a className='forgot-password'>
                        <p> Esqueceu a senha? </p>
                    </a>
                    <button className="acess" type="submit">
                        Salvar
                    </button>
                </form>

                {/* <form className="box-password">

        </form> */}



            </div>
        </div>
    )
}

export default ForgotPass;