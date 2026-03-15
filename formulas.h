// bytebeat formulas
// swap out which one is active by changing the #define FORMULA line
// t is the sample counter (goes up by 1 each sample at 8khz)

#ifndef FORMULAS_H
#define FORMULAS_H

// change this to switch formulas
#define FORMULA(t) FORMULA1(t)

// these all sound different, experiment

#define FORMULA1(t) ( (t) * ((t)>>5 | (t)>>8) )           // classic, sounds melodic
#define FORMULA2(t) ( (t) * (((t)>>9|(t)>>13) & 25 & (t)>>6) )  // glitchy
#define FORMULA3(t) ( ((t)>>6|((t)>>9)) * (((t)>>4)&63) ) // arpeggio-ish
#define FORMULA4(t) ( (t) | ((t)>>3) | ((t)>>5) )          // bass-y
#define FORMULA5(t) ( (t)*(t>>11&(t)>>8&123&(t)>>3) )     // chaotic, dont use at night

// TODO: figure out how to switch formulas at runtime over serial

#endif
