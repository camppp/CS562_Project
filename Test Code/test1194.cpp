TMatrix44 TMatrix44::operator*=(TMatrix44 &m){
    auto tmp = new float[16];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int dest = i * 4 + j;
            tmp[dest] = 0;
            for(int k = 0; k < 4; k++){
                tmp[dest] += _mat[i * 4 + k] * m._mat[k * 4 + j];
            }
        }
    }
    for(int i = 0; i < 16; i++){
        _mat[i] = tmp[i];
    }
    delete[] tmp;
    return *this;
}
