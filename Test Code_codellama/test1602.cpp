#include <iostream>
#include <string>

using namespace std;

string parseLicense(string readmeContent) {
    // Find the start of the license block
    size_t start = readmeContent.find("/*");
    if (start == string::npos) {
        // No license block found
        return "None";
    }

    // Find the end of the license block
    size_t end = readmeContent.find("*/");
    if (end == string::npos) {
        // No end of license block found
        return "None";
    }

    // Extract the license text
    string licenseText = readmeContent.substr(start + 2, end - start - 2);

    // Check for recognized license names
    if (licenseText.find("MIT License") != string::npos) {
        return "MIT";
    } else if (licenseText.find("Apache License 2.0") != string::npos) {
        return "Apache";
    } else if (licenseText.find("GPL") != string::npos) {
        return "GPL";
    } else if (licenseText.find("BSD") != string::npos) {
        return "BSD";
    } else {
        return "None";
    }
}

int main() {
    string readmeContent = "/*\n"
                           " * MIT License\n"
                           " *\n"
                           " * Copyright (c) 2020 <NAME> {@literal <<EMAIL>>}\n"
                           " *\n"
                           " * Permission is hereby granted, free of charge, to any person obtaining a copy\n"
                           " * of this software and associated documentation files (the \"Software\"), to deal\n"
                           " * in the Software without restriction, including without limitation the rights\n"
                           " * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
                           " * copies of the Software, and to permit persons to whom the Software is\n"
                           " */";

    string license = parseLicense(readmeContent);
    cout << "License: " << license << endl;

    return 0;
}
