import datetime

def generate_image_filename(mv_serial: str, network_id: str, publishPath: str) -> str:
    current_time = datetime.datetime.now().strftime("%Y-%m-%d-%H-%M-%S")
    file_name = f"From-{mv_serial}-at-{current_time}.jpeg"
    full_path = os.path.join(publishPath, file_name)
    return full_path