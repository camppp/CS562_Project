from typing import List, Tuple
import re

class InvalidProductLink(Exception):
    pass

class InvalidInputTime(Exception):
    pass

class FlashSaleQueue:
    def __init__(self):
        self.registered_users = []

    def register_user(self, product_link: str, registration_time: str) -> None:
        if not self.is_valid_product_link(product_link):
            raise InvalidProductLink("Invalid product link")
        if not self.is_valid_time(registration_time):
            raise InvalidInputTime("Invalid registration time")
        self.registered_users.append((product_link, registration_time))

    def get_registered_users(self) -> List[Tuple[str, str]]:
        return self.registered_users

    @staticmethod
    def is_valid_product_link(product_link: str) -> bool:
        # A simple check for a valid URL
        regex = re.compile(
            r'^(?:http|ftp)s?://'  # http:// or https://
            r'(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\.)+(?:[A-Z]{2,6}\.?|[A-Z0-9-]{2,}\.?)|'  # domain...
            r'localhost|'  # localhost...
            r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'  #...or ip
            r'(?::\d+)?'  # optional port
            r'(?:/?|[/?]\S+)$', re.IGNORECASE)
        return re.match(regex, product_link) is not None

    @staticmethod
    def is_valid_time(time: str) -> bool:
        # A simple check for a valid time in HH:MM format
        regex = re.compile(r'^([01]?[0-9]|2[0-3]):[0-5][0-9]$')
        return re.match(regex, time) is not None