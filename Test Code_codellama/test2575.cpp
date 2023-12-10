#include <string>
#include <utility>
#include <memory>
#include <hyrise/storage/AbstractTable.h>
#include <hyrise/storage/StorageManager.h>

std::pair<std::string, std::shared_ptr<hyrise::storage::AbstractTable>> loadQueryAndReference(const std::string& numberString) {
  // Load the query from the file
  std::string query = loadFromFile("test/tpcch/query" + numberString + ".json");

  // Load the reference table from the storage manager
  std::shared_ptr<hyrise::storage::AbstractTable> referenceTable = reference("refTable");

  return std::make_pair(query, referenceTable);
}
