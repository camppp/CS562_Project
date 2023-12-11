from bs4 import BeautifulSoup

def extractServiceInfo(html):
    soup = BeautifulSoup(html, 'html.parser')
    service_info = {}
    for service in soup.find_all('div', class_='col-sm-6 col-md-12'):
        title = service.find('h2', class_='service_title').text
        description = service.find('p').text
        service_info[title] = description
    return service_info