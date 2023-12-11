import sqlite3
import datetime

# Connect to the SQLite database
conn = sqlite3.connect('file_management.db')

# Create a cursor object
c = conn.cursor()

# Create the table if it does not exist
c.execute('''
          CREATE TABLE IF NOT EXISTS files
          (download_date timestamp, filename text, file_type text, file_md5 text, fileid_tg text, file_size integer, last_usage_date timestamp, usage_count integer)
          ''')

def insert_file_record(filename, file_type, file_md5, fileid_tg, file_size):
    timestamp = datetime.datetime.now()
    c.execute('''
              INSERT INTO files (download_date, filename, file_type, file_md5, fileid_tg, file_size, last_usage_date, usage_count)
              VALUES (?,?,?,?,?,?,?,?)
              ''', (timestamp, filename, file_type, file_md5, fileid_tg, file_size, timestamp, 0))
    conn.commit()

# Test the function
insert_file_record('test.txt', 'text','md5hash', 'fileid', 1024)