class SuperPoderes{
    dispararTeias(){
        console.log("Spider-Man está disparando teias!");
    }

    escolarParedes(){
        console.log("Spider-Man está escalando paredes!");
    }
}

// Abstração
class SuperHeroi{
    constructor(superPoderes){
        this.superPoderes = superPoderes;
    }

    usarSuperPoderes(){
        throw new Error("Método usarSuperPoderes() deve ser implementado!");
    }
}

// Implementação concreta do Spider-Man
class SpiderMan extends SuperHeroi{
    usarSuperPoderes(){
        this.superPoderes.dispararTeias();
        this.superPoderes.escolarParedes();
    }
}

// Utilização
const superPoderesSpiderMan = new SuperPoderes();
const spiderMan = new SpiderMan(superPoderesSpiderMan);
spiderMan.usarSuperPoderes();