python
def fileTypeByExtension(extension):
    file_types = {
        "txt": "text",
        "doc": "text",
        "docx": "text",
        "pdf": "text",
        "jpg": "image",
        "jpeg": "image",
        "png": "image",
        "gif": "image",
        "mp4": "video",
        "avi": "video",
        "mov": "video",
        "mkv": "video",
        "mp3": "audio",
        "wav": "audio",
        "flac": "audio",
        "aac": "audio"
    }
    return file_types.get(extension, "unknown")
