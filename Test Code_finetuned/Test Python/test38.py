def find_connected_rooms(rooms: dict, start_room: int) -> list:
    stack = [start_room]
    seen = {room: False for room in rooms}
    seen[start_room] = True
    connected_rooms = [start_room]

    while stack:
        room = stack.pop()
        for connected_room in rooms[room]:
            if not seen[connected_room]:
                stack.append(connected_room)
                seen[connected_room] = True
                connected_rooms.append(connected_room)

    return connected_rooms