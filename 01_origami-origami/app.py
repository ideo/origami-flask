from flask import Flask, request, jsonify
import json

app = Flask(__name__)

screenMode = ""

@app.route('/api/request-screen', methods=['GET', "POST"])
def return_screen_color():
    global screenMode
    if request.method == "GET":
        values = {
            'screenMode': screenMode
        }
        return jsonify({'values': values})
    else:
        content = request.json
        if 'color' in content:
            screenMode = content['color']
        return 'OK'

if __name__ == "__main__":
    app.run()
