// O objetivo deste código é demonstrar a aplicação do padrão de projeto Builder para criar objetos do Spider-Man em JavaScript.

class spiderManBuilder{
    constructor(){
        this.spiderMan = new SpiderMan();
    }

    setSuitColor(color){
        this.spiderMan.suitColor = color;

        return this;
    }

    setWebShooters(webShooters){
        this.spiderMan.webShooters = webShooters;

        return this;
    }

    setSuperStrength(superStrength){
        this.spiderMan.superStrength = superStrength;

        return this;
    }

    build(){
        return this.spiderMan;
    }
}

class SpiderMan{
    constructor(){
        this.suitColor = '';
        this.webShooters = false;
        this.superStrength = false;
    }

    useWebShooters(){
        console.log("Spider-Man soltando teia!");
    }

    useSuperStrength(){
        console.log("Spider-Man usando força!")
    }

    displayInfo(){
        console.log(`Spider-Man cor da roupa: ${this.suitColor}`);
        console.log(`Atirando teria: ${this.webShooters}`);
        console.log(`Usando força: ${this.superStrength}`);
    }
}

// Exemplo de uso o padrão Builder para criar um objeto Spider-Man
const spiderMan = new spiderManBuilder()
    .setSuitColor('Vermelho e azul')
    .setWebShooters(true)
    .setSuperStrength(true)
    .build();

spiderMan.displayInfo();
spiderMan.useWebShooters();
spiderMan.useSuperStrength();