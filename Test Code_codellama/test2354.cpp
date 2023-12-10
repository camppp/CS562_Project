cin >> c;
auto vp = nvector::Read<I2Point>(3);
bool b = false;

// Check if the points are collinear
if (CheckCollinear(vp[0], vp[1], vp[2])) {
    b = true;
}

// Your implementation goes here
for (unsigned i = 0; i < 3; ++i) {
    // Your code here
}
