#include <utility>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

std::string serializeData(const std::string& data) {
#if defined ENABLE_BOOST_IOSTREAMS && !defined DISABLE_BOOST_IOSTREAMS
    // Use Boost.IOStreams for serialization
    std::string serializedData;
    boost::iostreams::back_insert_device<std::string> inserter(serializedData);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> outputStream(inserter);
    {
        cereal::BinaryOutputArchive archive(outputStream);
        archive(data);
    }
    outputStream.flush();
    return serializedData;
#else
    // Use standard C++ streams for serialization
    std::stringstream ss;
    {
        cereal::BinaryOutputArchive archive(ss);
        archive(data);
    }
    return ss.str();
#endif
}
