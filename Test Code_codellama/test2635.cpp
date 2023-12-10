import datetime

class UpdateLog:
    def __init__(self):
        self.entries = []

    def add_entry(self, description: str) -> None:
        self.entries.append((datetime.datetime.now().strftime("%Y/%m/%d"), description))

    def display_log(self) -> None:
        for entry in self.entries:
            print(f"{entry[0]} - {entry[1]}")

    def search_entry(self, keyword: str) -> None:
        for entry in self.entries:
            if keyword in entry[1]:
                print(f"{entry[0]} - {entry[1]}")

    def search_by_date(self, date: str) -> None:
        for entry in self.entries:
            if date == entry[0]:
                print(f"{entry[0]} - {entry[1]}")
