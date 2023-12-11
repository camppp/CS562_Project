def highest_mark_students(marks: dict) -> Union[str, List[str]]:
    max_mark = max(marks.values())
    max_scores = {k: v for k, v in marks.items() if v == max_mark}
    if len(max_scores) == 1:
        return max_scores.keys()[0]
    else:
        return list(max_scores.keys())