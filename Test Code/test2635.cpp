python
from datetime import datetime

class UpdateLog:
    def __init__(self):
        self.log = []

    def add_entry(self, description: str) -> None:
        current_date = datetime.now().strftime("%Y/%m/%d")
        self.log.append((current_date, description))

    def display_log(self) -> None:
        for entry in self.log:
            print(f"{entry[0]} : {entry[1]}")

    def search_entry(self, keyword: str) -> None:
        matching_entries = [entry for entry in self.log if keyword in entry[1]]
        if matching_entries:
            for entry in matching_entries:
                print(f"{entry[0]} : {entry[1]}")
        else:
            print("No matching entries found.")

    def search_by_date(self, date: str) -> None:
        matching_entries = [entry for entry in self.log if entry[0] == date]
        if matching_entries:
            for entry in matching_entries:
                print(f"{entry[0]} : {entry[1]}")
        else:
            print("No entries found for the specified date.")
