import { Veiculos } from "../Veículos/Veiculos";

export abstract class VeiculosFactory{

    // Factory method
    abstract getVeiculo(veiculoNome: string): Veiculos;

    pickUp(customerNome: string, veiculoNome: string): Veiculos{
        const carro = this.getVeiculo(veiculoNome);
        carro.pickUp(customerNome);

        return carro 
    }
}