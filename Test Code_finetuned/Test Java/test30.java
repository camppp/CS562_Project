from flask import Flask, jsonify

app = Flask(__name__)

class ErrorResponseHandler:
    def errorResponse(self, statusCode, message):
        if statusCode == 400:
            return jsonify({"error": message}), 400
        elif statusCode == 401:
            return jsonify({"error": message}), 401
        elif statusCode == 403:
            return jsonify({"error": message}), 403
        elif statusCode == 404:
            return jsonify({"error": message}), 404
        else:
            return jsonify({"error": message}), 500

@app.route('/error/<int:statusCode>/<string:message>')
def error(statusCode, message):
    errorHandler = ErrorResponseHandler()
    return errorHandler.errorResponse(statusCode, message)

if __name__ == '__main__':
    app.run(debug=True)