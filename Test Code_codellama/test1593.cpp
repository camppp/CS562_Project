#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NEHeader {
    unsigned short ne_segtab;
    unsigned short ne_rsrctab;
    unsigned short ne_restab;
    unsigned short ne_modtab;
    unsigned short ne_imptab;
    signed int ne_nrestab;
    unsigned short ne_cmovent;
    unsigned short ne_align;
    unsigned short ne_cres;
    unsigned char ne_exetyp;
    unsigned char ne_flagsothers;
    unsigned short ne_pretthunks;
    unsigned short ne_psegrefbytes;
};

NEHeader extractNEHeader(const vector<unsigned char>& header) {
    NEHeader ne_header;

    // Extract the ne_segtab field
    ne_header.ne_segtab = *(unsigned short*)(&header[0]);

    // Extract the ne_rsrctab field
    ne_header.ne_rsrctab = *(unsigned short*)(&header[2]);

    // Extract the ne_restab field
    ne_header.ne_restab = *(unsigned short*)(&header[4]);

    // Extract the ne_modtab field
    ne_header.ne_modtab = *(unsigned short*)(&header[6]);

    // Extract the ne_imptab field
    ne_header.ne_imptab = *(unsigned short*)(&header[8]);

    // Extract the ne_nrestab field
    ne_header.ne_nrestab = *(signed int*)(&header[10]);

    // Extract the ne_cmovent field
    ne_header.ne_cmovent = *(unsigned short*)(&header[14]);

    // Extract the ne_align field
    ne_header.ne_align = *(unsigned short*)(&header[16]);

    // Extract the ne_cres field
    ne_header.ne_cres = *(unsigned short*)(&header[18]);

    // Extract the ne_exetyp field
    ne_header.ne_exetyp = header[20];

    // Extract the ne_flagsothers field
    ne_header.ne_flagsothers = header[21];

    // Extract the ne_pretthunks field
    ne_header.ne_pretthunks = *(unsigned short*)(&header[22]);

    // Extract the ne_psegrefbytes field
    ne_header.ne_psegrefbytes = *(unsigned short*)(&header[24]);

    return ne_header;
}

int main() {
    // Create a vector of bytes representing the NE file header
    vector<unsigned char> header = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

    // Extract the NE header fields
    NEHeader ne_header = extractNEHeader(header);

    // Print the extracted values
    cout << "ne_segtab: " << ne_header.ne_segtab << endl;
    cout << "ne_rsrctab: " << ne_header.ne_rsrctab << endl;
    cout << "ne_restab: " << ne_header.ne_restab << endl;
    cout << "ne_modtab: " << ne_header.ne_modtab << endl;
    cout << "ne_imptab: " << ne_header.ne_imptab << endl;
    cout << "ne_nrestab: " << ne_header.ne_nrestab << endl;
    cout << "ne_cmovent: " << ne_header.ne_cmovent << endl;
    cout << "ne_align: " << ne_header.ne_align << endl;
    cout << "ne_cres: " << ne_header.ne_cres << endl;
    cout << "ne_exetyp: " << ne_header.ne_exetyp << endl;
    cout << "ne_flagsothers: " << ne_header.ne_flagsothers << endl;
    cout << "ne_pretthunks: " << ne_header.ne_pretthunks << endl;
    cout << "ne_psegrefbytes: " << ne_header.ne_psegrefbytes << endl;

    return 0;
}
