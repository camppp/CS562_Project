import os

def find_source_files(TEST_SRCDIR, TEST_WORKSPACE):
    if TEST_SRCDIR:
        return os.path.abspath(os.path.join(TEST_SRCDIR, TEST_WORKSPACE))
    else:
        return os.path.abspath(os.path.join(os.path.dirname(__file__), TEST_WORKSPACE))