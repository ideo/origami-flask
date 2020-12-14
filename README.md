# origami-flask

A starter template for connecting Origami apps with other stuff (e.g. other Origami apps or physical input).

# How To Use

Look at [this deck](https://docs.google.com/presentation/d/1RW_LN8S06jPru6YspLcxXklOUCpzLr3LcyONFlEe5Sg/edit#slide=id.gb13376cec8_1_211) for a detailed walkthrough.

### Connecting Origami apps to other Origami apps

1. Start the Flask server with `python app.py`.
2. Open `receiver.origami` and `sender.origami`.
3. Click on any colored button in `sender.origami`, and the background color of `receiver.origami` will change accordingly.

### Connecting Oriigami apps to physical controllers

1. If you have an ESP8266 board, open `sender_ESP8266.ino` and replace the SSID and password to you WiFi credentials.
2. The code is set to read 4 switch inputs as arrow keys. Update the pin numbers for the arrow keys as necessary and write it to your board.
3. Open `receiver.origami`.
4. Push the switches, and and the background color of `receiver.origami` will change accordingly.
