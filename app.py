from flask import Flask, request, jsonify
import json

app = Flask(__name__)

screenMode = 1

@app.route('/api/request-screen', methods=['GET', "POST"])
def return_screen_mode():
    global screenMode
    if request.method == "GET":
        values = {
            'screenMode': screenMode
        }
        return jsonify({'values': values})
    else:
        content = request.json
        if 'color' in content:
            if content['color']=='red':
                screenMode = 1
            elif content['color']=='green':
                screenMode = 2
            elif content['color']=='blue':
                screenMode = 3
            else:
                screenMode = 4
        return 'OK'

if __name__ == "__main__":
    app.run(host='0.0.0.0') #remove parameter "host" to run in localhost
