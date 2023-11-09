from http.server import BaseHTTPRequestHandler, HTTPServer

class HTTPRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Cache-Control", "no-cache")
        if self.path.endswith(".wasm"):
            self.send_header("Content-Type", "application/wasm")
        else:
            self.send_header("Content-Type", "text/html")
        self.end_headers()
        
        urlpath = self.path
        if urlpath == "/":
            urlpath = "channel.html"

        with open(f".{urlpath}", "rb") as f:
            content = f.read()

        self.wfile.write(content)

def main():
    print("starting wasm server...")
    server_address = ("localhost", 8080)
    httpd = HTTPServer(server_address, HTTPRequestHandler)
    print("running wasm server...")
    httpd.serve_forever()

if __name__ == "__main__":
    main()