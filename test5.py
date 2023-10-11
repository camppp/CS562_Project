import tkinter as tk
from tkinter import messagebox

# Function to check if the username and password are correct
def validate_login():
    username = username_entry.get()
    password = password_entry.get()

    # Replace this with your own authentication logic
    if username == "your_username" and password == "your_password":
        messagebox.showinfo("Login Successful", "Welcome, " + username + "!")
    else:
        messagebox.showerror("Login Failed", "Invalid username or password")

# Create the main window
root = tk.Tk()
root.title("Login Page")

# Create and place username label and entry field
username_label = tk.Label(root, text="Username:")
username_label.pack()
username_entry = tk.Entry(root)
username_entry.pack()

# Create and place password label and entry field
password_label = tk.Label(root, text="Password:")
password_label.pack()
password_entry = tk.Entry(root, show="*")  # Use 'show' to hide the password
password_entry.pack()

# Create and place login button
login_button = tk.Button(root, text="Login", command=validate_login)
login_button.pack()

# Run the main loop
root.mainloop()
