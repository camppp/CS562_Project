def find_connected_rooms(rooms: dict, start_room: int) -> list:
   seen = {room: False for room in rooms}
   stack = [start_room]
   connected_rooms = []

   while stack:
       current_room = stack.pop()
       if not seen[current_room]:
           seen[current_room] = True
           connected_rooms.append(current_room)
           stack.extend(rooms[current_room])

   return connected_rooms