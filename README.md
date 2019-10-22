# ArduinoHashCrack
A basic Proof-of-Concept for cracking MD5 hashes with an Arduino board.

## Requirements:
* Any Arduino-compatible board (I used the MEGA2560)
* Python3
* The Arduino IDE
* The [MD5 Hashing Library](https://github.com/tzikis/ArduinoMD5) by [Tzikis](https://github.com/tzikis)

## Installation:
1. Open the Arduino IDE, upload the sketch to your Arduino board of choice.
2. Open the Python script in your favourite editor
3. Modify the COM port on line 6 for your Arduino board.
4. Modify line 8 for the MD5 hash you are attempting to crack.
5. Find a wordlist, name it `list.txt` and place it in the same folder as the Python script.
5.1. If you don't place the wordlist in the folder, update line 11 accordingly for the file path to the wordlist.
6. Run the Python script.
7. Hope for the best.

## License
GPLv2. Do what you will with it, and let me know if you make anything cool with it!

## Credz/Greetz
* Tzikis for the library
* My girlfriend for yelling at me to finally make something useful and original.
* Th3PonyWizard (please come back)
* 'The Brit' from HNKansai (Let's grab a few more drinks next time I'm down there.)
