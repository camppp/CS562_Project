python
def parseFilePath(file_path):
    result = {}
    filename_start = file_path.rfind('/') + 1
    filename_end = file_path.find('<gh_stars>')
    stars_start = file_path.find('<gh_stars>') + len('<gh_stars>')
    stars_end = file_path.find('+')
    
    result["filename"] = file_path[filename_start:filename_end]
    result["directory_path"] = file_path[:filename_start]
    result["stars_count"] = int(file_path[stars_start:stars_end])
    
    return result

# Test the function with the given example
file_path = "chrome/chrome_cleaner/os/process.cc<gh_stars>1000+"
print(parseFilePath(file_path))
