const path = require('path');
const express = require('express');
const app = express();

// settings
app.set('port', process.env.PORT || 3000);

// static files
app.use(express.static(path.join(__dirname, 'public')));

// app.get("/", (req, res, next) => {
//     res.send('./');
// });

// start the server
const server = app.listen(app.get('port'), () => {
    console.log('server on port', app.get('port'));
});

// websockets
const SocketIO = require('socket.io');
const io = SocketIO(server);

io.on('connection', socket => {
    console.log('new connection', socket.id);

    socket.on('chat:message', data => {
        console.log(data);
    })
});

// const net = require('net');
// const server = net.createServer(socket => {
//     socket.write(
//         "Testing !" +
//             socket.remoteAddress +
//             ":" +
//             socket.remotePort +
//             "\n"
//     );
//     socket.pipe(socket);
//     console.log("Client connected!");
// });
// server.listen(3000, "localhost");