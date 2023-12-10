python
def parseFirearmData(firearm_strings):
    firearm_data = {}
    for firearm in firearm_strings:
        parts = firearm.split('_')
        manufacturer = parts[1]
        model = parts[2]
        caliber = parts[3]
        barrel_length = parts[4]
        attachment = parts[5] if len(parts) > 5 else None
        if manufacturer in firearm_data:
            firearm_data[manufacturer].append((model, caliber, barrel_length, attachment))
        else:
            firearm_data[manufacturer] = [(model, caliber, barrel_length, attachment)]
    return firearm_data
