// arduino ide version of the bytebeat synth
// easier to flash than using avrdude directly
// same thing as main.c basically

#include <avr/interrupt.h>

volatile uint32_t t = 0;

// change this to change the sound
// list of formulas in formulas.h but this is arduino so just paste one here
#define FORMULA(t) ((t) * ((t)>>5 | (t)>>8))

ISR(TIMER2_COMPA_vect) {
    OCR2B = (uint8_t)(FORMULA(t) & 0xFF);
    t++;
}

void setup() {
    pinMode(3, OUTPUT);
    
    TCCR2A = (1 << WGM21) | (1 << COM2B1);
    TCCR2B = (1 << CS21);
    OCR2A = 249;
    OCR2B = 0;
    TIMSK2 = (1 << OCIE2A);
    
    sei();
}

void loop() {
    // nothing here
    // i tried putting serial stuff here but it messed up the timing
}
