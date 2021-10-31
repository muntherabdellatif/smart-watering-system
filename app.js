const express = require("express");
const app = express();
const https =require("https");
const request =require("request");
const bodyParser =require ("body-parser");
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));
app.get ("/",function(req,res) {
    res.sendFile(__dirname + "/index.html")
})
app.post("/",function(req,res) {
   
})
app.listen(process.env.PORT || 3000,"127.0.0.1", function() {
    console.log("running");
})