# bytebeat synth

makes music (kind of) on an arduino using just math. no audio libraries

the idea is you have a counter t and you evaluate some math expression on it and output the result as audio through pwm. sounds weird but it actually works

## stuff needed
- arduino uno or nano
- speaker or just wire it to headphones (be careful it might be loud)
- a resistor maybe (i used 10k)

## to flash
open synth.ino in arduino ide and hit upload. thats it

## formulas to try
change the FORMULA line in formulas.h to switch between sounds

some of them sound like music some of them sound like a robot dying, both are valid

## known issues
- sometimes the audio cuts out after a few minutes, not sure why
- the pwm filter isnt great so it sounds a bit noisy
- havent tested on mega, probably works
