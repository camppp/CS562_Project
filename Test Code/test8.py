import sqlite3
def sql_injection(username, password):
    # Connect to the SQLite database
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()

    # Attempt to log in
    cursor.execute("SELECT * FROM users WHERE username='{}' AND password='{}'".format(username, password))
    user = cursor.fetchone()

    # Close the connection
    conn.close()

    # Return whether the user was found
    return user is not None

# Test the function
print(sql_injection("admin", "' OR '1'='1"))