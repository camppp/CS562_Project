void doPrefill(GlobalTestConfig* gtc) {
    std::unordered_map<int, int> dataStructure;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    while (dataStructure.size() < gtc->prefill) {
        int key = dis(gen);
        if (dataStructure.find(key) == dataStructure.end()) {
            dataStructure[key] = 1; // Insert the key
        }
    }

    // Output the pre-filled data structure
    for (const auto& pair : dataStructure) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}
