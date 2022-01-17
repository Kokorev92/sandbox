const express = require('express')
const req = require('express/lib/request')
const sqlite3 = require('sqlite3')

// Обработка статических файлов
app.use(express.static(__dirname + "/public"))

// Запускаем сервер
app.listen(8000)