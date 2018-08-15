#include <ESP8266WiFi.h>
#include <time.h>

//const char* WIFI_SSID = "6021607";             // SSID is set
//const char* WIFI_PASSWORD = "17401449";     // Password is set

#define WIFI_SSID  "6021607"
#define WIFI_PASSWORD "17401449"

char ntp_server1[20] = "pool.ntp.org";
char ntp_server2[20] = "time.nist.gov";
char ntp_server3[20] = "time.uni.net.th";

int timezone = 7 * 3600;
int dst = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Connecting to %s\n" , WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  Serial.println("");

  configTime(timezone, dst, ntp_server1, ntp_server2, ntp_server3);
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
}
void loop() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  Serial.print(p_tm->tm_hour); Serial.print(":");
  Serial.print(p_tm->tm_min); Serial.print(":");
  Serial.println(p_tm->tm_sec);
  Serial.println(ctime(&now));
  delay(1000);
}