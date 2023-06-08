import { VeiculosFactory } from "./Veiculos-Factory";
import { Veiculos } from "../Veículos/Veiculos";
import { Carro } from "../Veículos/Carro";

export class CarroFactory extends VeiculosFactory{
    getVeiculo(veiculoNome: string): Veiculos {
        return new Carro(veiculoNome);
    }
}