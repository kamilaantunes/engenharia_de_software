import { Veiculos } from "./Veiculos";

export class Carro implements Veiculos{
    constructor(private nome: string){}
    
    pickUp(customerNome: string): void {
        console.log(`${this.nome} está buscando ${customerNome}`);
    }

    stop(): void {
        console.log(`${this.nome} parou`);
    }
}