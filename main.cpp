#include "mbed.h"

// LED pins
DigitalOut led1(LED1);
DigitalOut led2(LED2);

// Intervals
#define LED1_TOGGLE_INTERVAL 2000 // 2 seconds
#define LED2_TOGGLE_INTERVAL 5000 // 5 seconds

// LED1
void toggle_led1() {
    while (true) {
        led1 = !led1; // Toggle LED1
        ThisThread::sleep_for(LED1_TOGGLE_INTERVAL);
    }
}

// LED2
void toggle_led2() {
    while (true) {
        led2 = !led2; // Toggle LED2
        ThisThread::sleep_for(LED2_TOGGLE_INTERVAL);
    }
}

int main() {
    // LED toggle threads 
    Thread thread1;
    Thread thread2;

    // Threads
    thread1.start(toggle_led1);
    thread2.start(toggle_led2);

    // Main thread waits
    while (true) {
        // Do nothing
        ThisThread::sleep_for(1000); // Sleep
    }
}