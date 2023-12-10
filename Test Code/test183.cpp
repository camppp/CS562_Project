#include <iostream>
#include <string>

using namespace std;

const int BOOT_ADDRESS = 0x1000;  // Example boot address
const int BOOT_SECTOR = 0;        // Example boot sector
const int SECTOR_SIZE = 512;      // Example sector size

class Processor {
public:
    void freeze() {
        cout << "Processor frozen." << endl;
    }

    void jump(int address) {
        cout << "Jumping to address: " << hex << address << dec << endl;
    }

    void execute() {
        cout << "Executing boot code." << endl;
    }
};

class RAM {
public:
    void load(int address, const string& data) {
        cout << "Loading data into RAM at address " << hex << address << dec << ": " << data << endl;
    }
};

class HardDisk {
public:
    string read(int sector, int size) {
        // Simulated read operation
        return "Boot code data from sector " + to_string(sector) + " with size " + to_string(size);
    }
};

void simulateBoot(Processor* processor, RAM* ram, HardDisk* hd) {
    cout << ".....start ..." << endl;
    processor->freeze();
    ram->load(BOOT_ADDRESS, hd->read(BOOT_SECTOR, SECTOR_SIZE));
    processor->jump(BOOT_ADDRESS);
    processor->execute();
    cout << ".....over ..." << endl;
}

int main() {
    Processor processor;
    RAM ram;
    HardDisk hardDisk;

    simulateBoot(&processor, &ram, &hardDisk);

    return 0;
}
