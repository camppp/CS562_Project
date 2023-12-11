import threading
import glob
import os
from queue import Queue

def count_words_in_file(file_path, word_count_queue, lock):
    with open(file_path, 'r') as file:
        word_count = len(file.read().split())
        with lock:
            word_count_queue.put(word_count)

def count_words_threading(directory_path):
    word_count_queue = Queue()
    lock = threading.Lock()

    file_paths = glob.glob(os.path.join(directory_path, '*.txt'))
    threads = []

    for file_path in file_paths:
        thread = threading.Thread(target=count_words_in_file, args=(file_path, word_count_queue, lock))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    total_word_count = sum(word_count_queue.get() for _ in range(word_count_queue.qsize()))

    return total_word_count