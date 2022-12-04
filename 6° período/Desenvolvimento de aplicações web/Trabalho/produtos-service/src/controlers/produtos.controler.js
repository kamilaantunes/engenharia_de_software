import { Produto } from '../models/produto.models.js'

// GET
async function index(req, res){
    // res.json({mensagem: "OK!"})
    const produtos = await Produto.findAll();
    res.json(produtos);
}

// GET/:id
async function show(req, res){
    const produto = await Produto.findByPk(req.params.id);
    res.json(produto);
}

// POST
async function store(req, res){
    // res.json(req.body)
    const produto = await Produto.create(req.body);
    res.json(produto);
}

// Delete
async function destroy(req, res){
    const produto = await Produto.findByPk(req.params.id);
    await produto.destroy();
    res.send(produto);
}

// PUT
async function update(req, res){
    const produto = await Produto.findByPk(req.params.id);
    produto.nome = req.body.nome;
    produto.preco = req.body.preco;
    produto.imagem = req.body.imagem;

    await produto.save();
    res.send(produto);
}

export {index, store, show, destroy, update};