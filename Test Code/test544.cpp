template <typename T>
string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) {
        os << *iter;
        if (iter != V.end() - 1) {
            os << ", ";
        }
    }
    os << " }";
    return os.str();
}
