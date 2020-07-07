#include <iostream>
using namespace std;

#include "mbed.h"
#include "stats_report.h"
#include "Adafruit_SGP30.h"
#include "BME280.h"

DigitalOut led1(LED1);

#define SLEEP_TIME                  500 // (msec)
#define PRINT_AFTER_N_LOOPS         20

// main() runs in its own thread in the OS
int main()
{
    Adafruit_SGP30 
    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);
    printf("Hello World!\n\r");
    int count = 0;
    while (true) {
        // Blink LED and wait 0.5 seconds
        led1 = !led1;
        wait_ms(SLEEP_TIME);
        cout << "TVOC " << "ppb " << "eCO2 " << "ppm" << endl;
        if ((0 == count) || (PRINT_AFTER_N_LOOPS == count)) {
            // Following the main thread wait, report on the current system status
            sys_state.report_state();
            count = 0;
        }
        ++count;
    }
}