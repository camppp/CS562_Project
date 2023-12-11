from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/create_route', methods=['POST'])
def create_route():
    data = request.get_json()
    if not data or 'name' not in data or 'route' not in data:
        return jsonify({
           'succ': False,
            'code': 501,
           'message': 'Lỗi param',
            'data': None
        }), 400

    # Process the input and create the new route
    # This is a placeholder for the actual route creation logic
    # For example, you can save the data to a database
    # Here, we'll just return the data as it is
    return jsonify({
       'succ': True,
        'code': 200,
       'message': 'Route created successfully',
        'data': data
    }), 200

if __name__ == '__main__':
    app.run(debug=True)