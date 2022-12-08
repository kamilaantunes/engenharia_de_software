import './Produto.css'
import {NavLink} from 'react-router-dom'
// import Produtos from '../pages/Produtos'

export default function Produto({dadosProduto}){
    return (
        <div className='col'>
            <div className="card">
                <img 
                    src={dadosProduto.imagem}
                    className="card-img-top"
                    alt=""
                />
            
                <div className="card-body">
                    <h5 className="card-title"> {dadosProduto.nome} </h5>
                    <p className="card-text"> R$ {dadosProduto.preco} </p>
                    <NavLink href="#" className="btn btn-primary"> Comprar </NavLink>
                </div>
            </div>
        </div>
    )
}