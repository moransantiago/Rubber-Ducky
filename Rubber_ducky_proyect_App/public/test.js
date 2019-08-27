const socket = io();
const btn = document.getElementById('send');
const message = document.getElementById('inputMessage');

btn.addEventListener('click', () => {
    socket.emit('chat:message', {
        message: message.value
    });
});