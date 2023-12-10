python
class NEHeader:
    def __init__(self, ne_segtab, ne_rsrctab, ne_restab, ne_modtab, ne_imptab, ne_nrestab, ne_cmovent, ne_align, ne_cres, ne_exetyp, ne_flagsothers, ne_pretthunks, ne_psegrefbytes):
        self.ne_segtab = ne_segtab
        self.ne_rsrctab = ne_rsrctab
        self.ne_restab = ne_restab
        self.ne_modtab = ne_modtab
        self.ne_imptab = ne_imptab
        self.ne_nrestab = ne_nrestab
        self.ne_cmovent = ne_cmovent
        self.ne_align = ne_align
        self.ne_cres = ne_cres
        self.ne_exetyp = ne_exetyp
        self.ne_flagsothers = ne_flagsothers
        self.ne_pretthunks = ne_pretthunks
        self.ne_psegrefbytes = ne_psegrefbytes

def extract_ne_header(byte_array):
    ne_segtab = int.from_bytes(byte_array[0:2], byteorder='little')
    ne_rsrctab = int.from_bytes(byte_array[2:4], byteorder='little')
    ne_restab = int.from_bytes(byte_array[4:6], byteorder='little')
    ne_modtab = int.from_bytes(byte_array[6:8], byteorder='little')
    ne_imptab = int.from_bytes(byte_array[8:10], byteorder='little')
    ne_nrestab = int.from_bytes(byte_array[10:14], byteorder='little', signed=True)
    ne_cmovent = int.from_bytes(byte_array[14:16], byteorder='little')
    ne_align = int.from_bytes(byte_array[16:18], byteorder='little')
    ne_cres = int.from_bytes(byte_array[18:20], byteorder='little')
    ne_exetyp = byte_array[20]
    ne_flagsothers = byte_array[21]
    ne_pretthunks = int.from_bytes(byte_array[22:24], byteorder='little')
    ne_psegrefbytes = int.from_bytes(byte_array[24:26], byteorder='little')

    return NEHeader(ne_segtab, ne_rsrctab, ne_restab, ne_modtab, ne_imptab, ne_nrestab, ne_cmovent, ne_align, ne_cres, ne_exetyp, ne_flagsothers, ne_pretthunks, ne_psegrefbytes)

# Example usage
header_bytes = b'\x02\x00\x10\x00\x20\x00\x30\x00\x40\x00\x50\x00\x60\x00\x70\x00\x80\x00\x90\x00\xa0\x00\xb0\x00\xc0\x00'
ne_header = extract_ne_header(header_bytes)
print(ne_header.ne_segtab)  # Output: 2
print(ne_header.ne_rsrctab)  # Output: 16
# ... (print other fields)
