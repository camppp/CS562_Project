import os
import threading

def count_words_threading(directory):
    # Create a list of all the text files in the directory
    files = [f for f in os.listdir(directory) if f.endswith('.txt')]

    # Create a list of threads to process the files concurrently
    threads = []
    for file in files:
        t = threading.Thread(target=count_words, args=(file,))
        threads.append(t)
        t.start()

    # Wait for all threads to finish
    for t in threads:
        t.join()

    # Return the total count of words
    return sum(t.result for t in threads)

def count_words(file):
    # Open the file and read its contents
    with open(file, 'r') as f:
        contents = f.read()

    # Split the contents into individual words
    words = contents.split()

    # Return the number of words
    return len(words)