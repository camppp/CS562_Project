void DES_decrypt3(DES_LONG * data, DES_key_schedule * ks1, DES_key_schedule * ks2, DES_key_schedule * ks3, t_DES_SPtrans * sp) {
    register DES_LONG l, r;

    l = data[0];
    r = data[1];
    IP(l, r);  // Perform initial permutation
    data[0] = l;
    data[1] = r;

    // Perform the remaining decryption rounds using the provided subkeys
    DES_encrypt2((DES_LONG *)data, ks3, sp, DES_DECRYPT);  // Decrypt using ks3
    DES_encrypt2((DES_LONG *)data, ks2, sp, DES_ENCRYPT);  // Encrypt using ks2
}
