const logger = document.getElementById('logger');

fetchData = async _ => {
    const data = await fetch('localhost:8080/keylog', { method: 'GET' });
    const text = await data.text();
    logger.innerHTML = text;
}

setTimeout(_ => {
    fetchData();
}, 2500);