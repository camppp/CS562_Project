from bs4 import BeautifulSoup
from typing import List

def extractButtonContent(html_content: str) -> List[str]:
    soup = BeautifulSoup(html_content, 'html.parser')
    button_elements = soup.find_all('button')
    button_contents = [button.get_text() for button in button_elements]
    return button_contents