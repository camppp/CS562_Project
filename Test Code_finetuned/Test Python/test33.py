import http.server
import socketserver
import json

class JsonEncoder:
    def encode(self, data):
        return json.dumps(data)

    def content_type(self):
        return 'application/json'

class MyHandler(http.server.SimpleHTTPRequestHandler):
    def respond(self, content, code=200):
        self.send_response(code)
        self.send_header('Content-type', self.encoder.content_type())
        self.end_headers()
        self.wfile.write(self.encoder.encode(content).encode())

def run_server(info, port, encoder=JsonEncoder(), response_cache={}):
    class CustomHandler(MyHandler):
        def do_GET(self):
            if self.path in response_cache:
                self.respond(response_cache[self.path])
            else:
                super().do_GET()
                response_cache[self.path] = self.path

    httpd = socketserver.TCPServer(("", port), CustomHandler)
    print(f"{info} is running on port {port}")
    httpd.serve_forever()

# Usage
run_server("My Server", 8000)