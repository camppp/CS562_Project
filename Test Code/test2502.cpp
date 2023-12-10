class SSet {
    private:
        vector<int> elements;

    public:
        void loadFromFile(string filename) {
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Error opening file");
            }

            int element;
            while (file >> element) {
                elements.push_back(element);
            }
        }

        bool checkZeroSumFast() {
            // Initialize a hash table to store the sum of each subset
            unordered_map<int, int> sums;

            // Iterate over all subsets of the set
            for (int i = 0; i < elements.size(); i++) {
                // Calculate the sum of the current subset
                int sum = 0;
                for (int j = i; j < elements.size(); j++) {
                    sum += elements[j];
                }

                // Check if the sum is zero
                if (sum == 0) {
                    return true;
                }

                // Store the sum in the hash table
                sums[sum]++;
            }

            // Check if any subset has a sum of zero
            for (const auto& sum : sums) {
                if (sum.second > 1) {
                    return true;
                }
            }

            return false;
        }
};
