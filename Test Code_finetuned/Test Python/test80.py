def dump_nodes(stub):
    # Extract and display the list of nodes in the network
    print("Nodes: ", stub['nodes'])

def dump_links(stub):
    # Extract and display the list of links in the network
    print("Links: ", stub['links'])

def dump_addrs(stub):
    # Extract and display the list of addresses in the network
    print("Addresses: ", stub['addresses'])

def dump_neighs(stub):
    # Extract and display the list of neighbors in the network
    print("Neighbors: ", stub['neighbors'])

def dump_routes(stub):
    # Extract and display the list of routes in the network
    print("Routes: ", stub['routes'])

# Example usage
network_stub = {
    'nodes': ['Node1', 'Node2', 'Node3'],
    'links': [('Node1', 'Node2'), ('Node2', 'Node3')],
    'addresses': {'Node1': '192.168.1.1', 'Node2': '192.168.1.2', 'Node3': '192.168.1.3'},
    'neighbors': {'Node1': ['Node2'], 'Node2': ['Node1', 'Node3'], 'Node3': ['Node2']},
    'routes': {'Node1': ['192.168.1.0/24'], 'Node2': ['192.168.1.0/24'], 'Node3': ['192.168.1.0/24']}
}

dump_nodes(network_stub)
dump_links(network_stub)
dump_addrs(network_stub)
dump_neighs(network_stub)
dump_routes(network_stub)