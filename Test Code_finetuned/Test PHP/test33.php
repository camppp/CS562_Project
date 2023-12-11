from bs4 import BeautifulSoup

def extractFormData(html):
    soup = BeautifulSoup(html, 'html.parser')
    form = soup.find('form', {'id': 'data-form'})
    username = form.find('input', {'id': 'username'})['value']
    password = form.find('input', {'id': 'password'})['value']
    return {"username": username, "password": password}