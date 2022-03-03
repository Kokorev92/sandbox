const { response } = require('express')
const express = require('express')
const req = require('express/lib/request')
const sqlite3 = require('sqlite3')

const app = express()
const db = new sqlite3.Database('db.sqlite')

// Обработка статических файлов
app.use(express.static(__dirname + "/public"))

// Запускаем сервер
app.listen(8000)

app.post('/get_products', (request, response) => {
    get_data((json) => { response.send(json) })
})

function get_data(send_response) {
    db.all('SELECT name,desc,cost,img_src FROM products', [], (err, rows) => {
        if (err) {
            throw err
        }
        console.log(rows.length)
        rows.forEach((row) => {
            console.log(row.name)
        })

        let resp = JSON.stringify(rows)
        send_response(resp)
    })
}