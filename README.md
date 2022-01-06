# origami-flask

A starter template for connecting Origami apps with other stuff (e.g. other Origami apps or physical input).

# How To Use

Look at [this deck](https://docs.google.com/presentation/d/1RW_LN8S06jPru6YspLcxXklOUCpzLr3LcyONFlEe5Sg/edit#slide=id.gb13376cec8_1_211) for a detailed walkthrough.

### Connecting Origami apps to other Origami apps

1. Go to `01_origami-origami` directory
2. Start the Flask server with `python app.py` (requires python3).
3. Open `receiver.origami` and `sender.origami` on Origami.
4. Click on any colored button in `sender.origami`, and the background color of `receiver.origami` will change accordingly.

### Connecting Origami apps to physical controllers

1. Go to `02_origami-Airtable` directory
2. This template requires you to have an ESP8266 board. Make sure you have one, then open `sender_ESP8266.ino`
3. In the code, replace the SSID and password to you WiFi credentials, and set `serverIp` to your server's IP address (i.e. your computer's IP address)
4. The code is set to read 4 switch inputs as arrow keys. Update the pin numbers for the arrow keys as necessary and upload the code to your board.
5. Open `receiver.origami`.
6. Push the switches, and and the background color of `receiver.origami` will change accordingly.

### Connecting Origami apps to Airtable API

1. Go to `03_origami-Airtable` directory
2. Open `receiver_Airtable.origami` and `sender_Airtable.origami`
3. Go to [this Airtable base](https://airtable.com/invite/l?inviteId=invmnKvhMrhVAqE4Q&inviteToken=08895cbdb2b5f238c943c41ccbe6a7f1ce379e656913814735a68bd5e84972ea&utm_source=email) (only allows IDEO email address)
4. `receiver_Airtable.origami` will load the `my-data` table on load, and `sender_Airtable.origami` will add a new record. Currently the photo attachment is just a non-working dummy, but technically you can take a photo with Origami, upload it to an external server then pass that URL to Airtable and it will work.
5. See the [Airtable API Reference for this base](https://airtable.com/appF7iNDb2CFyyRpO/api/docs#curl/introduction) for more detailed info on the API (yes, Airtable's API is very generously documented.)
