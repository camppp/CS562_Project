from bs4 import BeautifulSoup
from typing import List

def calculateTotalHeight(html_template: str) -> List[int]:
    soup = BeautifulSoup(html_template, 'html.parser')
    list_items = soup.find_all('li')
    total_heights = []

    for li in list_items:
        divs = li.find_all('div')
        total_height = 0
        for div in divs:
            style = div.get('style')
            if style:
                height = int(style.split(':')[1].split('px')[0])
                total_height += height
        total_heights.append(total_height)

    return total_heights