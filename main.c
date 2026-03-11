// bytebeat synth for atmega328p
// ansh
// 
// generates audio from math. timer2 fires at 8khz and evaluates
// a bytebeat formula each sample
//
// wiring: pin 3 (OC2B) -> 10k resistor -> speaker -> gnd
//         also put a 100nf cap from speaker to gnd as a low pass filter
//         or dont, it still works without it

#include <avr/io.h>
#include <avr/interrupt.h>
#include "formulas.h"

// the sample counter. bytebeat formulas use this as input
// called t because thats what all the bytebeat stuff online uses
volatile uint32_t t = 0;

// this runs at ~8000 times per second
ISR(TIMER2_COMPA_vect) {
    // evaluate formula and write to pwm
    // the & 0xFF keeps it 8 bit
    OCR2B = (uint8_t)(FORMULA(t) & 0xFF);
    t++;
    // NOTE: if t overflows (after like 6 days of running) it wraps to 0
    // the formula just starts from beginning, probably fine
}

void setup_timer() {
    // timer2 in CTC mode
    // clock is 16mhz, prescaler 8, OCR2A = 249
    // so ISR rate = 16000000 / 8 / 250 = 8000 hz
    // i think thats right
    TCCR2A = (1 << WGM21) | (1 << COM2B1);
    TCCR2B = (1 << CS21);
    OCR2A = 249;
    OCR2B = 0;
    TIMSK2 = (1 << OCIE2A);
}

int main() {
    // pin 3 is OC2B on atmega328p
    DDRD |= (1 << PD3);
    
    setup_timer();
    sei(); // enable interrupts
    
    // literally just wait forever, everything happens in the ISR
    while(1) {
        // do nothing
        // could add serial control here later to switch formulas
    }
    return 0; // never reaches here
}
