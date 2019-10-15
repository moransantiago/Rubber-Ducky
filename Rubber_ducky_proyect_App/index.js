const net = require('net');
const path = require('path');
const { readFileSync } = require('fs');
const jsdom = require("jsdom");
const { JSDOM } = jsdom;
const express = require('express');
const app = express();

const page = readFileSync('./public/index.html', 'utf-8');
const document = new JSDOM(page).window.document;
const logger = document.getElementById('logger');

app.use('/', express.static(path.join(__dirname + '/public')));

const server = net.createServer(socket => {
    console.log("Client connected!");
    socket.on('data', data => {
        logger.innerHTML = data.toString();
    })
});

app.listen(8080)
server.listen(3000);