#include <iostream>
#include <string>
using namespace std;

#include "esp_http_client.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_event.h"

class cHttpClient{
    private:
        string url_post_;
        string url_get_;
    public:
        cHttpClient(string url_post, string url_get);
        ~cHttpClient();
};