class DisparadorTeias{
    usarDisparadorTeias(){
        console.log('Spider-Man está disparano teias!')
    }
}

class SuperForca{
    usarSuperForca(){
        console.log('Spider-Man está usando super força!')
    }
}

class Combate{
    iniciar(){
        this.preparar();
        this.executarTecnica();
        this.finalizar();
    }

    preparar(){
        console.log('Preparando para o combate...');
    }

    executarTecnica(){
        throw new Error('O método executarTecnica() deve ser implementado pelas subclasses.')
    }

    finalizar(){
        console.log('Combate finalizado!')
    }
}

class CombateDisparadorTeias extends Combate{
    constructor(disparadorTeias){
        super();
        this.disparadorTeias = disparadorTeias;
    }

    executarTecnica(){
        this.disparadorTeias.usarDisparadorTeias();
    }
}

class CombateSuperForca extends Combate{
    constructor(superForca){
        super();
        this.superForca = superForca;
    }

    executarTecnica(){
        this.superForca.usarSuperForca();
    }
}

// Exemplo de uso do padrão Template Method
const combateDisparadorTeias = new CombateDisparadorTeias(new DisparadorTeias());
combateDisparadorTeias.iniciar();
    /* Saída esperada:
     * Preparando para o combate...
     * Spider-Man está disparando teias!
     * Combate finalizado!
    */

const combateSuperForca = new CombateSuperForca(new SuperForca());
combateSuperForca.iniciar();
    /* Saída esperada:
     * Preparando para o combate...
     * Spider-Man está usando super força!
     * Combate finalizado!
    */