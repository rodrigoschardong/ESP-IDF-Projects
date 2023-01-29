#include <iostream>
#include <string>
using namespace std;

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif.h"
//#include "esp_tls.h"

#include "lwip/err.h"
#include "lwip/sys.h"
#include "esp_wifi.h"
#include "esp_http_client.h"
#include "freertos/event_groups.h"

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

class cWiFi{
    private:
        string ssid_;
        string pass_;
        bool connected_;

        EventGroupHandle_t s_wifi_event_group_;

    public:
        cWiFi(string ssi, string password);
        ~cWiFi();
        void initStation();
};