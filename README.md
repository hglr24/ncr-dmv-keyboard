# ncr-dmv-keyboard

## (README adapted from parent repo)

This is a pretty niche project, but I needed a way to type on the NCR Decision Mate V without the original proprietary keyboard. The NCR keyboard protocol uses a simple routine to poll the keyboard for new keypresses. The keypress output to the NCR is provided through events on the Arduino's D2 pin. These events are also used to provide the initialization byte expected by the NCR. 

This version of the project uses relies on the PlatformIO serial monitor to send inputs to the DMV, but the project could be iterated to have onboard USB support (I might have done this, but I didn't have the right hardware sitting around). This project is configured for the Nano atmega328 (new bootloader) board by default. You'll want to have a 5-pin DIN connector on-hand to ensure a solid connection (only 2 pins are actually used though).

Wiring diagram:


