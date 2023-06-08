import { CarroFactory } from "./Factories/Carro-Factory";
import { randomCarro } from "./Main/Random-Veiculos";
import { randomNumeros } from "./Utils/Random-Numeros";

const carroFactory = new CarroFactory();
const customerNomes = ['Marjorie', 'Benjamin', 'Joaquim'];

for (let i = 0; i < 10; i++){
    const veiculo = randomCarro();
    const nome = customerNomes[randomNumeros(customerNomes.length)]

    veiculo.pickUp(nome);
    veiculo.stop();

    const newCarro = carroFactory.pickUp(nome, `Novo carro - ${randomNumeros(100)}`);
    
    newCarro.stop();
    console.log('----')
}

// import { CarroFactory } from "./Factories/Carro-Factory";

// const carroFactory = new CarroFactory();
// const fusca = carroFactory.getVeiculo('Fusca');
// fusca.pickUp('Joana');
// fusca.stop();