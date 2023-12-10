void TblDISTRICT_NEXT_O_ID::Key::print() {
    FILE * f = stdout;
    fprintf(f, "DISTRICT::Key { " );
    if( mVal == 0 ) {
        fprintf(f, "(NULL) ");
    } else {
        uint16_t pos = 0;
        // Print TBLID
        fprintf(f, "TBLID: %u, ", static_cast<uint16_t>(mVal & 0xFFFF));
        // Print D_W_ID
        pos += 16;
        fprintf(f, "D_W_ID: %u, ", static_cast<uint16_t>((mVal >> pos) & 0xFFFF));
        // Print D_ID
        pos += 16;
        fprintf(f, "D_ID: %u, ", static_cast<uint16_t>((mVal >> pos) & 0xFFFF));
        // Print T_ID
        pos += 16;
        fprintf(f, "T_ID: %u", static_cast<uint16_t>((mVal >> pos) & 0xFFFF));
    }
    fprintf(f, " }\n");
}
