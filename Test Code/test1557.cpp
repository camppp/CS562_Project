class FunctionGroup {
private:
    std::vector<Function> mOverloads;

public:
    class overloads_iterator {
    private:
        std::vector<Function>::iterator iter;

    public:
        overloads_iterator(std::vector<Function>::iterator it) : iter(it) {}

        overloads_iterator& operator++() {
            ++iter;
            return *this;
        }

        overloads_iterator& operator--() {
            --iter;
            return *this;
        }

        Function& operator*() {
            return *iter;
        }

        bool operator!=(const overloads_iterator& other) const {
            return iter != other.iter;
        }
    };

    overloads_iterator overloads_begin() const {
        return overloads_iterator(mOverloads.begin());
    }

    overloads_iterator overloads_end() const {
        return overloads_iterator(mOverloads.end());
    }
};
