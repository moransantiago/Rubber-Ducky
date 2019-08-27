const socket = io();
const btn = document.getElementById('send');
const message = document.getElementById('inputMessage');

btn.addEventListener('click', _ => {
    socket.emit('chat:message', {
        message: message.value
    });
});