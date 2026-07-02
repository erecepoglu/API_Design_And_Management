const protobuffer = require("protobufjs");
const size_of = require("object-sizeof");

async function run(){
    const root = protobuffer.load('./resources/player.proto');
    const player_message = (await root).lookupType("PlayerMessage");

    const obj = {
        id : 1,
        fisrt_name: "Mohamed",
        last_name: "Ali",
        email: "mohamedali12345678912@gmail.com"
    }
    //playload contains the plain fields
    const payload = player_message.create(obj);
    console.log(`Size of payload is ${size_of(payload)}`);

    //Turning the payload to binary as buffer
    const buffer = player_message.encode(payload).finish();
    console.log(`Size of buffer is ${size_of(buffer)}`);


    console.log(`Serialized data ${buffer}`);

    const decoded_buff = player_message.decode(buffer);
    console.log(`\nDeserialized buffer ${JSON.stringify(decoded_buff)}`);
    console.log(`Size of Deserialized buffer is ${size_of(decoded_buff)}`);

}

run();