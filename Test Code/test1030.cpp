// Define a functor to output key-value pairs to the console
struct OutputFunctor {
    template <class TKey, class TValue>
    void operator()(const std::pair<const TKey, TValue>& pair) const {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
};

int main() {
    // Create an instance of the Mapping class
    Mapping<std::string, int> myMapping;

    // Add key-value pairs to the mapping
    myMapping.AddMapping("One", 1);
    myMapping.AddMapping("Two", 2);
    myMapping.AddMapping("Three", 3);

    // Apply the OutputFunctor to each key-value pair in the mapping
    myMapping.ForEachMapping(OutputFunctor());

    return 0;
}
