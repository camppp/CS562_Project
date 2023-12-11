def minChangesTo24HourFormat(schedule):
    hours, minutes = map(int, schedule.split(':'))
    if hours > 23 or minutes > 59:
        return 2
    else:
        return 0


print(minChangesTo24HourFormat("12:45"))  # Output: 0
print(minChangesTo24HourFormat("25:30"))  # Output: 2