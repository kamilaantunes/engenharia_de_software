import { sequelize } from "../services/db.service.js";
import { DataTypes } from "sequelize";
import bcrypt from 'bcrypt';

const Usuario = sequelize.define('usuario', {
    email: {
        type: DataTypes.STRING,
        allowNull: true,
        unique: true,
    },
    senha: {
        type: DataTypes.STRING,
        allowNull: true,
    },
}, {
    hooks: {
        beforeCreate: async (usuario) => {
            if (usuario.senha){
                const salt = await bcrypt.genSaltSync(10);
                usuario.senha = bcrypt.hashSync(usuario.senha, salt);
            }
        }
    }
});

Usuario.sync();

export {Usuario};