const net = require('net');
const server = net.createServer(socket => {
    console.log("Client connected!");
    socket.on('data', data => {
        console.log(data.toString());
    })
});
server.listen(3000, "localhost");