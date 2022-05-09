const { request } = require('express');
const express = require('express')
const Sequelize = require('sequelize')

const settings = require('./settings.json')

const app = express();

app.listen(settings.server_settings.port);

app.get("/", (request, response) => {
    email.findAll().then((result) => {
        response.send(result)
    }).catch((err) => {
        response.send("Error DB request")
    })
});

const sequelize = new Sequelize(settings.db_settings.db_name,
    settings.db_settings.db_user,
    settings.db_settings.db_pass,
    {
        dialect: settings.db_settings.db_type, pool: {
            max: 10, min: 0, acquire: 30000,
            idle: 10000
        }
    });

const email = sequelize.define("email_list", {
    id: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        primaryKey: true,
        allowNull: false
    },
    address: {
        type: Sequelize.STRING
    }
}, {
    freezeTableName: true,
    timestamps: false
});

(async () => {
    console.log("Server was starting!")
})()