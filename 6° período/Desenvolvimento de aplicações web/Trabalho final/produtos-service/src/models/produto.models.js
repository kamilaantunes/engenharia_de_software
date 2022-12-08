import { sequelize } from "../services/db.services.js";
import { DataTypes } from "sequelize";

// Tabela do produto no db
const Produto = sequelize.define("produto", {
    nome: {
        type: DataTypes.STRING,
        allowNull: false
    },
    preco: {
        type: DataTypes.FLOAT,
        allowNull: false
    },
    imagem: {
        type: DataTypes.STRING
    }
});

Produto.sync();

export {Produto};