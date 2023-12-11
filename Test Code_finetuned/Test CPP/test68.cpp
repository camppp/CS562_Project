def extractPosition(msg):
    pose = msg.find(msg[0])
    return pose

print(extractPosition("Hello, World!"))  # Output: 0