class Collection {
public:
    // Constructor
    Collection() {
        mFgtCollectionPtr = nullptr;
    }

    // Destructor
    ~Collection() {
        if (mFgtCollectionPtr != nullptr) {
            delete mFgtCollectionPtr;
        }
    }

    // Add an integer to the collection
    void add(int value) {
        if (mFgtCollectionPtr == nullptr) {
            mFgtCollectionPtr = new std::vector<int>;
        }
        mFgtCollectionPtr->push_back(value);
    }

    // Remove an integer from the collection
    void remove(int value) {
        if (mFgtCollectionPtr != nullptr) {
            auto it = std::find(mFgtCollectionPtr->begin(), mFgtCollectionPtr->end(), value);
            if (it != mFgtCollectionPtr->end()) {
                mFgtCollectionPtr->erase(it);
            }
        }
    }

    // Retrieve the maximum integer in the collection
    int max() {
        if (mFgtCollectionPtr != nullptr) {
            return *std::max_element(mFgtCollectionPtr->begin(), mFgtCollectionPtr->end());
        }
        return 0;
    }

    // Retrieve the minimum integer in the collection
    int min() {
        if (mFgtCollectionPtr != nullptr) {
            return *std::min_element(mFgtCollectionPtr->begin(), mFgtCollectionPtr->end());
        }
        return 0;
    }

private:
    std::vector<int>* mFgtCollectionPtr;
};
