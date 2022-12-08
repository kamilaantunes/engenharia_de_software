import './Sobre.css'

export default function Sobre(){
    return (
        <div>
            <h1> Sobre </h1>

            <p>
                Este trabalho foi desenvolvimento para fins de avaliação da disciplina de aplicação de desenvolvimento web,
                ministrado pelo professor Erivaldo da Silva, do curso de engenharia de software da Universidade Tecnólogica
                Federal do Paraná - Câmpus Dois Vizinhos. <br />
                A avaliação teve como método no desenvolvimento de uma aplicação web consistindo simular um e-commerce, possuindo
                a tela principal - home, dispondo dos produtos disponíveis na loja, login, verificando se o usuário está ou não logado
                para poder acessar os produtos da loja. Ainda, utilizou as seguintes tecnologias: 
                    <ul>
                        <li> React Js - para desenvolvimento front end; </li>
                        <li> Bootstrao - para estilização das páginas; </li>
                        <li> SQL Lite - para banco de dados; </li>
                        <li> Postman - para validação das requisições. </li>
                    </ul>
                Por fim, acredito que o desenvolvimento deste projeto e da disciplina no decorrer do semestre, foi de extrema importância e 
                conhecimento.

                Para funcionamento total do web-sistem é importante startar todos os projetos com npm start ou yarn star, a estrutura está organizada da seguinte forma:
                    <ul>
                        <li> Pasta front end: contém todo o front end da aplicação; </li>
                        <li> Pasta gateway-service: contém a integração e disponiblização da API criada para o projeto; </li>
                        <li> Pasta produtos-service: contém a estrutura do back end dos produtos listados e cadastrados na página; </li>
                        <li> Pasta usuario-service: estrutura do back end dos usuários cadastrados e que irão se cadastrar no sistema. </li>
                    </ul>

                <br /> Discente: Kamila Antunes de Souza Neves - 2204690 | kamilaneves@alunos.utfpr.edu.br
                <br />
                
                <img className="mb-4" src="https://th.bing.com/th/id/R.099753e0b751424202b5224d97df32d2?rik=v%2bKXDODFHAKo0A&riu=http%3a%2f%2fportal.utfpr.edu.br%2ficones%2fcabecalho%2flogo-utfpr%2f%40%40images%2fimage.png&ehk=DP3PsrmxZs5VJvQCLyLH1fFJp8mIopBDXMnw18eRh8Q%3d&risl=&pid=ImgRaw&r=0" alt="" height={120} />
                <img className='mb-4' src='https://coens.dv.utfpr.edu.br/site/wp-content/uploads/2018/08/logo-curso-fundo-transp.png' alt='' height={200} />
            </p>
        </div>
    )
}