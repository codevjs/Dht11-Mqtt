const mosca   = require("mosca");
const broker  = new mosca.Server({
    port : 1883,
    http: {
        port: 1884,
        bundle: true,
        static: './'
    },
});

broker.on("ready", () => {

    console.log("Broker Ready");
})

// broker.on("published", (packet) => {
//
//     console.log(packet);
// })