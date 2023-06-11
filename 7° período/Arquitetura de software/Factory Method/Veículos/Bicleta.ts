import { Veiculos } from "./Veiculos";

export class Bicicleta implements Veiculos{
    constructor(private nome: string){}

    pickUp(customerNome: string): void {
        console.log(`${this.nome} está buscando ${customerNome}`);
    }

    stop(): void {
        console.log(`${this.nome} parou`);
    }
}