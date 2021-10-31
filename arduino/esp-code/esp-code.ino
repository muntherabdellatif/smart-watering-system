#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80); // 80 is port number
#define led D1
String msg;
const int analogInPin = A0;
bool ledStatus = 0;
void root_page()
{
  int sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  sensorValue /= 10.2;
  // Serial.println(to_string(sensorValue));

  msg = R"***(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>smart-watering-system</title>
    <script src="https://kit.fontawesome.com/0f3736a9ac.js" crossorigin="anonymous"></script>
    <style>
        * {
  --color1: #125c13;
  --color2: #3e7c17;
  --color3: #f4a442;
  --color4: #e8e1d9;
}
body {
  background-color: var(--color2);
  transition: 1s;
  -webkit-transition: 1s;
  -moz-transition: 1s;
  -ms-transition: 1s;
  -o-transition: 1s;
}
h1 {
  text-align: center;
  font-size: 5rem;
  color: var(--color4);
  margin: 27px;
}
.btn:hover {
  background-color: var(--color4);
  color: var(--color2);
  transition: 1s;
  -webkit-transition: 1s;
  -moz-transition: 1s;
  -ms-transition: 1s;
  -o-transition: 1s;
}
.plants-container {
  display: flex;
  flex-wrap: wrap;
  width: 80%;
  margin: auto;
  justify-content: space-around;
  align-items: center;
}
.plants-container .plant {
  position: relative;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  width: 20%;
  height: 400px;
  background-color: var(--color3);
  border-radius: 5px;
  -webkit-border-radius: 5px;
  -moz-border-radius: 5px;
  -ms-border-radius: 5px;
  -o-border-radius: 5px;
}
.plants-container .plant i:first-child {
  color: var(--color1);
  font-size: 200px;
}
.plants-container .plant .water-level {
  overflow: hidden;
  width: 80%;
  background-color: var(--color4);
  height: 30px;
  border-radius: 5px;
  -webkit-border-radius: 5px;
  -moz-border-radius: 5px;
  -ms-border-radius: 5px;
  -o-border-radius: 5px;
}
.plants-container .plant .water-level span {
  display: block;
  height: 100%;
  position: relative;
  background-color: blue;
}
.plants-container .plant .pump {
  display: flex;
  justify-content: center;
  width: 63px;
  cursor: pointer;
  background-color: var(--color4);
  border: var(--color3);
  padding: 10px 15px;
  margin-top: 20px;
  border-radius: 5px;
  -webkit-border-radius: 5px;
  -moz-border-radius: 5px;
  -ms-border-radius: 5px;
  -o-border-radius: 5px;
}
.plants-container .plant .pump:hover {
  background-color: var(--color2);
}
.plants-container .plant .pump:hover i {
  color: var(--color4);
}
.plants-container .plant .pump i {
  color: var(--color2);
  font-size: 50px;
}
    </style>
    <!-- <link rel="stylesheet" href="CSS/all.min.css"> -->
</head>
<body>
    <h1>Smart watering System</h1>
    <div class="plants-container">
        <div class="plant">
            <i class="fas fa-seedling"></i>
            <br>
            <div class="water-level">
                <span style="width:)***";
  msg += sensorValue;
  msg += R"***(%" data-progress="90%"></span>
            </div>
            <div class="pump active">)***";
  if (ledStatus == 1)
  {
    msg += R"***(<a href="/ledoff"><i class="fas fa-tint"></i></a>)***";
  }
  else
  {
    msg += R"***(<a href="/ledon"><i class="fas fa-tint-slash"></i></a>)***";
  }

  msg += R"***(</div>
        </div>
        <div class="plant">
            <i class="fas fa-seedling"></i>
            <br>
            <div class="water-level">
                <span style="width: 50%" data-progress="50%"></span>
            </div>
            <div class="pump ">
                <i class="fas fa-tint-slash"></i>
            </div>
        </div>
        <div class="plant">
            <i class="fas fa-seedling"></i>
            <br>
            <div class="water-level">
                <span style="width: 70%" data-progress="70%"></span>
            </div>
            <div class="pump active">
                <i class="fas fa-tint"></i>
            </div>
        </div>
        <div class="plant">
            <i class="fas fa-seedling"></i>
            <br>
            <div class="water-level">
                <span style="width: 30%" data-progress="30%"></span>
            </div>
            <div class="pump">
                <i class="fas fa-tint-slash"></i>
            </div>
        </div>
    </div>
    <!-- <Script src="JS/main.js"></Script> -->
    <script>
    let timer =setInterval (()=> {
        window.location = window.location.href;
    },5000) ;
    </script>
</body>
</html>)***";
  server.send(200, "text/html", msg);
  //server.send(200, "text/plain", "Hello world!");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}
void ledON()
{
  ledStatus = 1;
  root_page();
  digitalWrite(led, 1);
}
void ledOFF()
{
  ledStatus = 0;
  root_page();
  digitalWrite(led, 0);
}
void setup()
{
  pinMode(led, OUTPUT);
  WiFi.mode(WIFI_STA);
  //WiFi.begin("Umniah-evo-Home-AACD","HQ3MFF0T45G"); // net work password
  //WiFi.begin("moaed","32660055"); // net work password
  WiFi.begin("HUAWEI Y9 2018", "esraa123"); // net work password
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n connected ");
  Serial.print("IP adderess:");
  Serial.print(WiFi.localIP());
  server.on("/", root_page);
  server.on("/ledon", ledON);
  server.on("/ledoff", ledOFF);
  server.begin();
  MDNS.begin("myesp");
}

void loop()
{
  server.handleClient();
  MDNS.update();
}