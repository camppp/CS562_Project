#include <WebKit/WebKit.h>
#include <WebCore/DataReference.h>
#include <WebCore/WebCoreArgumentCoders.h>

namespace WebKit {

class CustomDataSerializer {
public:
    CustomDataSerializer() = default;

    // Serializes a data reference and string argument into a byte array
    std::vector<uint8_t> serialize(const DataReference& dataReference, const std::string& stringArgument) {
        // Encode the data reference and string argument using the provided header files
        auto encodedDataReference = WebCore::encodeDataReference(dataReference);
        auto encodedStringArgument = WebCore::encodeStringArgument(stringArgument);

        // Concatenate the encoded data references and string arguments
        std::vector<uint8_t> serializedData;
        serializedData.reserve(encodedDataReference.size() + encodedStringArgument.size());
        serializedData.insert(serializedData.end(), encodedDataReference.begin(), encodedDataReference.end());
        serializedData.insert(serializedData.end(), encodedStringArgument.begin(), encodedStringArgument.end());

        return serializedData;
    }

    // Deserializes a byte array into a data reference and string argument
    std::pair<DataReference, std::string> deserialize(const std::vector<uint8_t>& serializedData) {
        // Decode the encoded data references and string arguments
        auto decodedDataReference = WebCore::decodeDataReference(serializedData);
        auto decodedStringArgument = WebCore::decodeStringArgument(serializedData);

        return std::make_pair(decodedDataReference, decodedStringArgument);
    }
};

} // namespace WebKit
