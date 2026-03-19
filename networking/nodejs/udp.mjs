import dgram from 'dgram'

const socket = dgram.createSocket("udp4");
socket.bind("5000","172.17.0.1");
socket.on("message", (msg,info)=>{
    console.log(`My server got a message: ${msg}, from: ${info.address}:${info.port}`)
});