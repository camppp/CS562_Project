#include <iostream>
#include <string>

using namespace std;

int main() {
    int ownerID;
    string ownerName, additionalInfo;
    float assetValue;

    // Prompt the user to input the owner's ID
    cout << "Enter the owner's ID: ";
    cin >> ownerID;

    // Prompt the user to input the owner's name
    cout << "Enter the owner's name: ";
    cin >> ownerName;

    // Prompt the user to input additional information about the owner
    cout << "Enter additional information about the owner: ";
    cin >> additionalInfo;

    // Prompt the user to input the value of the owner's asset
    cout << "Enter the value of the owner's asset: ";
    cin >> assetValue;

    // Display all entered information in a formatted manner
    cout << "Owner ID: " << ownerID << endl;
    cout << "Owner Name: " << ownerName << endl;
    cout << "Additional Information: " << additionalInfo << endl;
    cout << "Asset Value: " << assetValue << endl;

    return 0;
}
