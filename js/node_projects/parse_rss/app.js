const Parser = require('rss-parser');
const https = require('https');
const fs = require('fs');

const parser = new Parser();

let url = './rss';

(async () => {
    let rss_file = fs.readFileSync(url)
    let feed = await parser.parseString(rss_file)
    let index = 0
    feed.items.forEach(item => {
        console.log(`${++index} ${item.title} : ${item.content}`)
        console.log(`------------`)
    })
    
    console.log(feed.items.length)
})()
