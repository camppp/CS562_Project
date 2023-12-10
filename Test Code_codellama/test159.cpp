// Create nodes for the point-to-point link
Ptr<Node> node1 = CreateObject<Node>();
Ptr<Node> node2 = CreateObject<Node>();

// Create the point-to-point link and set its attributes
PointToPointHelper p2p;
p2p.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
p2p.SetChannelAttribute("Delay", StringValue("2ms"));

// Create the devices and install them on the nodes
NetDeviceContainer devices = p2p.Install(node1, node2);

// Assign IP addresses to the devices
Ipv4AddressHelper address;
address.SetBase("10.1.1.0", "255.255.255.0");
Ipv4InterfaceContainer interfaces = address.Assign(devices);

// Install the internet stack on the nodes
InternetStackHelper stack;
stack.Install(node1);
stack.Install(node2);

// Create a TCP socket on node1
Ptr<Socket> socket = node1->GetObject<TcpL4Protocol>()->CreateSocket();

// Connect the socket to node2
InetSocketAddress local = InetSocketAddress(node1->GetObject<Ipv4>()->GetAddress(1, 0), 80);
InetSocketAddress remote = InetSocketAddress(node2->GetObject<Ipv4>()->GetAddress(1, 0), 80);
socket->Connect(local, remote);

// Send data through the socket
std::string data = "Hello, world!";
socket->Send(data.c_str(), data.size());

// Receive data through the socket
std::string receivedData;
socket->Receive(receivedData);

// Print the received data
std::cout << "Received data: " << receivedData << std::endl;
