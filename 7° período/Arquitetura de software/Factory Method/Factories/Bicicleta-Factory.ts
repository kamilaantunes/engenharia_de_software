import { Bicicleta } from "../Veículos/Bicleta";
import { Veiculos } from "../Veículos/Veiculos";
import { VeiculosFactory } from "./Veiculos-Factory";

export class BicicletaFactory extends VeiculosFactory{
    getVeiculo(veiculoNome: string): Veiculos{
        return new Bicicleta(veiculoNome);
    }
}