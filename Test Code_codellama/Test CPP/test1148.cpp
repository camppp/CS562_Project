void TblDISTRICT_NEXT_O_ID::Key::print() {
    if (mVal == 0) {
        cout << "(NULL)" << endl;
    } else {
        cout << "TBLID: " << mVal & 0xFFFF << endl;
        cout << "D_W_ID: " << (mVal >> 16) & 0xFFFF << endl;
        cout << "D_ID: " << (mVal >> 32) & 0xFFFF << endl;
        cout << "T_ID: " << (mVal >> 48) & 0xFFFF << endl;
    }
}
