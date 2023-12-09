import httplib

def send_request(url, headers):
    conn = httplib.HTTPConnection(url)
    conn.request("GET", "/", headers=headers)
    response = conn.getresponse()
    print(response.status, response.reason)

# Injecting additional headers
headers = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
    "Accept-Language": "en-US,en;q=0.5",
    "Accept-Encoding": "gzip, deflate",
    "Connection": "close",
    "Upgrade-Insecure-Requests": "1",
    "If-Modified-Since": "Mon, 26 Jul 1997 05:00:00 GMT",
    "If-None-Match": "W/13493676329823",
    "Cache-Control": "max-age=0",
    "TE": "Trailers",
    "DNT": "1",
    "Content-Type": "application/x-www-form-urlencoded",
    "Content-Length": "42",
    "Origin": "http://example.com",
    "Host": "example.com",
    "Referer": "http://example.com/",
    "Cookie": "PHPSESSID=298zf09hf012fh2",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
    "Accept-Language": "en-US,en;q=0.5",
    "Accept-Encoding": "gzip, deflate",
    "Connection": "close",
    "Upgrade-Insecure-Requests": "1",
    "If-Modified-Since": "Mon, 26 Jul 1997 05:00:00 GMT",
    "If-None-Match": "W/13493676329823",
    "Cache-Control": "max-age=0",
    "TE": "Trailers",
    "DNT": "1",
    "Content-Type": "application/x-www-form-urlencoded",
    "Content-Length": "42",
    "Origin": "http://example.com",
    "Host": "example.com",
    "Referer": "http://example.com/",
    "Cookie": "PHPSESSID=298zf09hf012fh2",
}

send_request("http://example.com", headers)