import { useEffect, useState } from "react";
import Produto from "../components/Produto";
import {getProdutos} from '../service/ProdutoServices'

export default function Produtos(){
    const [produtos, setProdutos] = useState([]);

    useEffect(() => {
        getProdutos().then((produtos) => {
            setProdutos(produtos);
            // console.log(produtos);
        });
    }, []);
    
    return (
        <div>
            <h1> Produtos </h1>

            {/* {produtos.length ? ( */}
                <div className="row row-cols-1 row-cols-md-3 g-4">
                    {
                        produtos.map((produto) => (
                            <Produto dadosProduto={produto} />
                        )) 
                    }
                </div>
            {/* ) : (
                <h3> Sem produtos a serem visualizados! </h3> */}
            {/* )} */}
        </div>
    )
}