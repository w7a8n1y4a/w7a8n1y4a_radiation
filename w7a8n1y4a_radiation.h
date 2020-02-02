#include <Arduino.h>

#define MINUTE 60000
#define TUBE_FACTOR 0.00812

class w7a8n1y4a_radiation{
public:

    w7a8n1y4a_radiation(){};

   void radiation_count();

    uint32_t radiation_count_all_time();
    float radiation_cpm();
    float radiation_uR();
    float radiation_uSv();

private:
    uint8_t _pin_radiation = 0;

    volatile uint32_t count = 0;
    volatile uint32_t counts = 0;
    unsigned long millis_radiation = 0;

    volatile uint32_t cpm;
};
