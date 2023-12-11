class SymbolManager {
public:
  void pushFunction(PDBSymbolFunc* func) {
    functions.push_back(std::unique_ptr<PDBSymbolFunc>(func));
  }

  void pushData(PDBSymbolData* data) {
    data.push_back(std::unique_ptr<PDBSymbolData>(data));
  }

  size_t getFunctionCount() {
    return functions.size();
  }

  size_t getDataCount() {
    return data.size();
  }

private:
  std::vector<std::unique_ptr<PDBSymbolFunc>> functions;
  std::vector<std::unique_ptr<PDBSymbolData>> data;
};
