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

app.use(express.static(__dirname + '/build'));

broker.on("ready", () => {

    console.log("Broker Ready");
});

broker.on("published", (packet) => {

    console.log(packet);
});

app.get("/", (req, res) => {

    res.render('index.html');
});

app.listen(8080, () => {

    console.log("Server run")
})