import api from './Api'

async function getProdutos(){
    const response = await fetch('/produtos');
    // console.log(response);
    const produtos = await response.json();
    // console.log(produtos);

    return produtos;
}

export {getProdutos};