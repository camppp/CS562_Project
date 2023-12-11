from typing import Union, List

def highest_mark_students(marks: dict) -> Union[str, List[str]]:
    max_mark = max(marks.values())
    top_students = [student for student, mark in marks.items() if mark == max_mark]
    if len(top_students) == 1:
        return top_students[0]
    else:
        return top_students