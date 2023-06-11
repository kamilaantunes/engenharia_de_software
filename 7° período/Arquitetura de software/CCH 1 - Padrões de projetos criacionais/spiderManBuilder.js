// O objetivo deste código é demonstrar a aplicação do padrão de projeto Builder para criar objetos do Spider-Man em JavaScript.

class spiderManBuilder{
    constructor(){
        this.spiderMan = new SpiderMan();
    }

    setCorTraje(cor){
        this.spiderMan.corTraje = cor;

        return this;
    }

    setDisparadorTeias(disparadorTeias){
        this.spiderMan.disparadorTeias = disparadorTeias;

        return this;
    }

    setSuperForca(superForca){
        this.spiderMan.superForca = superForca;

        return this;
    }

    build(){
        return this.spiderMan;
    }
}

class SpiderMan{
    constructor(){
        this.corTraje = '';
        this.disparadorTeias = false;
        this.superForca = false;
    }

    useDisparadorTeias(){
        console.log("Spider-Man soltando teia!");
    }

    useSuperForca(){
        console.log("Spider-Man usando força!")
    }

    displayInfo(){
        console.log(`Spider-Man cor da roupa: ${this.corTraje}`);
        console.log(`Atirando teia: ${this.disparadorTeias}`);
        console.log(`Usando força: ${this.superForca}`);
    }
}

// Exemplo de uso o padrão Builder para criar um objeto Spider-Man
const spiderMan = new spiderManBuilder()
    .setCorTraje('Vermelho e azul')
    .setDisparadorTeias(true)
    .setSuperForca(true)
    .build();

spiderMan.displayInfo();
spiderMan.useDisparadorTeias();
spiderMan.useSuperForca();