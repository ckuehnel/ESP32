// This file contains credentials to access several services

// WiFi
const char* mySSID = "<Your SSID>";
const char* myPW = "<Your Password>";

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define uS_TO_S_FACTOR 1000000

//maximum is 400 days
//uint64_t DEEPSLEEP_SECONDS = 1800; // 30 min
//uint64_t  DEEPSLEEP_SECONDS = 180; // 3 min
uint64_t  DEEPSLEEP_SECONDS = 3600; // 60 min number to big
// uint64_t  DEEPSLEEP_SECONDS = 3600*12; // twice a day
// uint64_t  DEEPSLEEP_SECONDS = 3600*24; // once a day


// MQTT (CloudMQTT)
const char* BROKER = "m20.cloudmqtt.com";
uint16_t    BRPORT = 12394;
const char* BRUSER = "<Your Username>";
const char* BRPWD  = "<Your Password>";
const char* CLIENTID = "HiGrow";

/* topics */
#define WOHNEN_BENJAMINI

#ifdef BUERO_BOGENHANF
  #define TEMP_TOPIC    "Büro/Bogenhanf/Temperatur"
  #define HUMI_TOPIC    "Büro/Bogenhanf/Luft_Feuchtigkeit"
  #define SOIL_TOPIC    "Büro/Bogenhanf/Boden_Feuchtigkeit"
  #define LIGHT_TOPIC   "Büro/Bogenhanf/Licht"

#elif defined WOHNEN_BENJAMINI
  #define TEMP_TOPIC    "Wohnen/Benjamini/Temperatur"
  #define HUMI_TOPIC    "Wohnen/Benjamini/Luft_Feuchtigkeit"
  #define SOIL_TOPIC    "Wohnen/Benjamini/Boden_Feuchtigkeit"
  #define LIGHT_TOPIC   "Wohnen/Benjamini/Licht"
//....
#endif
