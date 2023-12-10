class FunctionGroup {
private:
    std::vector<Function> mOverloads;

public:
    class overloads_iterator {
    public:
        overloads_iterator(const FunctionGroup& group) : group(group) {}

        Function& operator*() const {
            return group.mOverloads[index];
        }

        overloads_iterator& operator++() {
            index++;
            return *this;
        }

        overloads_iterator& operator--() {
            index--;
            return *this;
        }

        bool operator!=(const overloads_iterator& other) const {
            return index != other.index;
        }

    private:
        const FunctionGroup& group;
        int index = 0;
    };

    overloads_iterator overloads_begin() const {
        return overloads_iterator(*this);
    }

    overloads_iterator overloads_end() const {
        return overloads_iterator(*this, mOverloads.size());
    }
};
