#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define WIFI_SSID "Universitas Mulawarman"
#define WIFI_PASSWORD ""

#define BOT_TOKEN "6058473086:AAGGgZwyMUIhE4ZrLz7IyxX_zGq8Dd2pO4g"

const unsigned long BOT_MTBS = 1000;  // mean time between scan messages

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;  // last time messages' scan has been done

const int led = D1;
const int buz = D0;

int unit_delay = 250;


void handleNewMessages(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
    String from_name = bot.messages[i].from_name;
    if (from_name == "")
      from_name = "Guest";
    
    if (text == "/A") {
      A();
      bot.sendMessage(chat_id, "Ini Kode Morse A");
    }
    if (text == "/B") {
      B();
      bot.sendMessage(chat_id, "Ini Kode Morse B");
    }
    if (text == "/C") {
      C();
      bot.sendMessage(chat_id, "Ini Kode Morse C");
    }
    if (text == "/D") {
      D();
      bot.sendMessage(chat_id, "Ini Kode Morse D");
    }
    if (text == "/E") {
      E();
      bot.sendMessage(chat_id, "Ini Kode Morse E");
    }
    if (text == "/F") {
      f();
      bot.sendMessage(chat_id, "Ini Kode Morse F");
    }
    if (text == "/G") {
      G();
      bot.sendMessage(chat_id, "Ini Kode Morse G");
    }
    if (text == "/H") {
      H();
      bot.sendMessage(chat_id, "Ini Kode Morse H");
    }
    if (text == "/I") {
      I();
      bot.sendMessage(chat_id, "Ini Kode Morse I");
    }
    if (text == "/J") {
      J();
      bot.sendMessage(chat_id, "Ini Kode Morse J");
    }
    if (text == "/K") {
      K();
      bot.sendMessage(chat_id, "Ini Kode Morse K");
    }
    if (text == "/L") {
      L();
      bot.sendMessage(chat_id, "Ini Kode Morse L");
    }
    if (text == "/M") {
      M();
      bot.sendMessage(chat_id, "Ini Kode Morse M");
    }
    if (text == "/N") {
      N();
      bot.sendMessage(chat_id, "Ini Kode Morse N");
    }
    if (text == "/O") {
      O();
      bot.sendMessage(chat_id, "Ini Kode Morse O");
    }
    if (text == "/P") {
      P();
      bot.sendMessage(chat_id, "Ini Kode Morse P");
    }
    if (text == "/Q") {
      Q();
      bot.sendMessage(chat_id, "Ini Kode Morse Q");
    }
    if (text == "/R") {
      R();
      bot.sendMessage(chat_id, "Ini Kode Morse R");
    }
    if (text == "/S") {
      S();
      bot.sendMessage(chat_id, "Ini Kode Morse S");
    }
    if (text == "/T") {
      T();
      bot.sendMessage(chat_id, "Ini Kode Morse T");
    }
    if (text == "/U") {
      U();
      bot.sendMessage(chat_id, "Ini Kode Morse U");
    }
    if (text == "/V") {
      V();
      bot.sendMessage(chat_id, "Ini Kode Morse V");
    }
    if (text == "/W") {
      W();
      bot.sendMessage(chat_id, "Ini Kode Morse W");
    }
    if (text == "/X") {
      X();
      bot.sendMessage(chat_id, "Ini Kode Morse X");
    }
    if (text == "/Y") {
      Y();
      bot.sendMessage(chat_id, "Ini Kode Morse Y");
    }
    if (text == "/Z") {
      Z();
      bot.sendMessage(chat_id, "Ini Kode Morse Z");
    }
    if (text == "/1") {
      one();
      bot.sendMessage(chat_id, "Ini Kode Morse 1");
    }
    if (text == "/2") {
      two();
      bot.sendMessage(chat_id, "Ini Kode Morse 2");
    }    
    if (text == "/3") {
      three();
      bot.sendMessage(chat_id, "Ini Kode Morse 3");
    }
    if (text == "/4") {
      four();
      bot.sendMessage(chat_id, "Ini Kode Morse 4");
    }
    if (text == "/5") {
      five();
      bot.sendMessage(chat_id, "Ini Kode Morse 5");
    }
    if (text == "/6") {
      six();
      bot.sendMessage(chat_id, "Ini Kode Morse 6");
    }
    if (text == "/7") {
      seven();
      bot.sendMessage(chat_id, "Ini Kode Morse 7");
    }
    if (text == "/8") {
      eight();
      bot.sendMessage(chat_id, "Ini Kode Morse 8");
    }
    if (text == "/9") {
      nine();
      bot.sendMessage(chat_id, "Ini Kode Morse 9");
    }
    if (text == "/0") {
      zero();
      bot.sendMessage(chat_id, "Ini Kode Morse 0");
    }
    if (text == "/start") {
      String welcome = "Welcome to IoT Telegram Bot, " + from_name + ".\n";
      welcome += "Silahkan Masukkan Kode Morse yang anda inginkan:";
      welcome += "Contoh /A";
      bot.sendMessage(chat_id, welcome);
    }
  }
}

void dot() {
  Serial.print(".");
  digitalWrite(led, HIGH);
  digitalWrite(buz, HIGH);
  delay(unit_delay);
  digitalWrite(led, LOW);
  digitalWrite(buz, LOW);
  delay(unit_delay);
}
void dash() {
  Serial.print("-");
  digitalWrite(led, HIGH);
  digitalWrite(buz, HIGH);
  delay(unit_delay * 3);
  digitalWrite(led, LOW);
  digitalWrite(buz, LOW);
  delay(unit_delay);
}
void A() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void B() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void C() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void D() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void E() {
  dot();
  delay(unit_delay);
}
void f() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void G() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void H() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void I() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void J() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void K() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void L() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void M() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void N() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void O() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void P() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
}
void Q() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void R() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void S() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void T() {
  dash();
  delay(unit_delay);
}
void U() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void V() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void W() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void X() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Y() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Z() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void one() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void two() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void three() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void four() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void five() {
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void six() {
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}

void seven() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void eight() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void nine() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void zero() {
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);

  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Check NTP/Time, usually it is instantaneous and you can delete the code below.
  Serial.print("Retrieving time: ");
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
}

void loop() {
  if (millis() - bot_lasttime > BOT_MTBS) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    
    while (numNewMessages) {
      Serial.println("Got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
  delay(1000);
}