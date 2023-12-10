python
def extractDomainName(url: str) -> str:
    start_index = url.find("//") + 2
    end_index = url.find("/", start_index)
    return url[start_index:end_index]

# Test cases
print(extractDomainName("http://www.example.com/page1"))  # Output: "www.example.com"
print(extractDomainName("https://subdomain.example.org/page2"))  # Output: "subdomain.example.org"
