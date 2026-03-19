from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/api')
def hello_api_and_design_management():
    return jsonify({
        'data': 'Hola, API design and management!'
    })

if __name__ == '__main__':
    app.run(debug=True)
