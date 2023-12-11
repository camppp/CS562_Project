import http.server
import json
from urllib.parse import parse_qs

class JsonEncoder:
    def __init__(self):
        self.content_type = 'application/json'

    def encode(self, data):
        return json.dumps(data).encode()

class MyHandler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory='./', **kwargs)

    def respond(self, content, code=200):
        self.send_response(code)
        self.send_header('Content-Type', self.encoder.content_type)
        self.end_headers()
        self.wfile.write(self.encoder.encode(content))

def run_server(info, port, encoder=None, response_cache=None):
    if encoder is None:
        encoder = JsonEncoder()
    if response_cache is None:
        response_cache = {}