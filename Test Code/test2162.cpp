python
def publish_landmarks(pubLandMarks, landmarks):
    msg = ""  # Initialize an empty message
    for landmark in landmarks:
        msg += f"Landmark detected at ({landmark[0]}, {landmark[1]})\n"  # Format each landmark coordinate
    pubLandMarks.publish(msg)  # Publish the formatted message
