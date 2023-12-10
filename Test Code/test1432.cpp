python
def extract_network_info(event_dict):
    network_info = {}
    for key, value in event_dict.items():
        if "network" in key:
            network_info[key] = value
    return network_info
