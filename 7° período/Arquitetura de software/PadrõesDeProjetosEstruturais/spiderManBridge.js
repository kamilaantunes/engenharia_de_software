class DispadorTeia{
    usarDisparadorTeias(){
        console.log('Spider-Man está disparando teias!');
    }
}

class SuperForca{
    usarSuperForca(){
        console.log('Spider-Man está usando super força!');
    }
}

class spiderMan{
    constructor(habilidades){
        this.habilidades = habilidades;
    }

    usarHabilidades(){
        this.habilidades.usarHabilidades();
    }
}

const spiderManDisparadorTeias = new spiderMan(new DispadorTeia());
spiderManDisparadorTeias.usarHabilidades(); // Spider-Man está disparando teias

const spiderManSuperForca = new spiderMan(new SuperForca());
spiderManSuperForca.usarHabilidades(); // Spider-Man está usando a super força