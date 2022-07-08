const mosca   = require("mosca");
const express = require("express");

const broker  = new mosca.Server({
    port : 1883,
    http: {
        port: 1884,
        bundle: true,
        static: './'
    },
});

const app = express();

broker.on("ready", () => {

    console.log("Broker Ready");
})

broker.on("published", (packet) => {

    console.log(packet);
})

app.get("/", (req, res) => {

    res.send("Hello mqtt");
})

app.listen(5000, () => {

    console.log("server run on port", 5000);
})