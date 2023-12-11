def generate_report(users):
    # Split each user's information into username and date
    users_info = [user.split(": ") for user in users]

    # Sort the users by username in ascending order
    users_info.sort(key=lambda x: x[0])

    # Sort the users by date in descending order
    users_info.sort(key=lambda x: x[1], reverse=True)

    # Combine the username and date back into a string
    report = ["{}: {}".format(user[0], user[1]) for user in users_info]

    return report


users = ["alice: 16/1/4", "bob: 15/12/31", "charlie: 16/1/1"]
print(generate_report(users))