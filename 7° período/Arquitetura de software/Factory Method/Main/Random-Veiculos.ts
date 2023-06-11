import { BicicletaFactory } from "../Factories/Bicicleta-Factory";
import { CarroFactory } from "../Factories/Carro-Factory";
import { randomNumeros } from "../Utils/Random-Numeros";
import { Veiculos } from "../Veículos/Veiculos";

export function randomCarro(): Veiculos{
    const carroFactory = new CarroFactory();
    const bicicletaFactory = new BicicletaFactory();

    const carro1 = carroFactory.getVeiculo('Fusca');
    const carro2 = carroFactory.getVeiculo('HB20');

    const bicicleta = bicicletaFactory.getVeiculo('GTS');

    const carros = [carro1, carro2, bicicleta];
    
    return carros[randomNumeros(carros.length)];
}