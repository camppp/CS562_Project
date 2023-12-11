import requests
from requests.exceptions import RequestException

class MockConnectionBaseUrlFetcher:
    def __init__(self, base_url):
        self.base_url = base_url
        self.connection_cache = {}

    def getUncachedInputStream(self, url):
        try:
            response = requests.get(url)
            response.raise_for_status()
            return response.content
        except RequestException as e:
            raise Exception(f"Failed to establish connection: {str(e)}")

    def addConnection(self, url):
        if url not in self.connection_cache:
            self.connection_cache[url] = self.getUncachedInputStream(url)

    def getConnection(self, url):
        if url in self.connection_cache:
            return self.connection_cache[url]
        else:
            raise Exception(f"Connection for {url} not found in cache")