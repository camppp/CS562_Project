def weighted_average(grades, credits):
    total_weighted_sum = 0
    total_credits = 0

    for course, grade_list in grades.items():
        weighted_sum = sum(grade_list) * credits[course]
        total_weighted_sum += weighted_sum
        total_credits += credits[course]

    return total_weighted_sum / total_credits