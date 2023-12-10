#include <iostream>
#include <fstream>
#include <string>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

#ifdef ENABLE_BOOST_IOSTREAMS
#include <boost/iostreams/stream.hpp>
#endif

std::string serializeData(const std::string& data) {
#ifdef ENABLE_BOOST_IOSTREAMS
    // Use Boost.IOStreams for serialization
    boost::iostreams::stream<boost::iostreams::file_sink> file;
    file.open("data.bin", std::ios::binary);
    cereal::BinaryOutputArchive archive(file);
    archive(data);
    file.close();
    return "Boost.IOStreams";
#else
    // Use standard C++ streams for serialization
    std::ofstream file("data.bin", std::ios::binary);
    cereal::BinaryOutputArchive archive(file);
    archive(data);
    file.close();
    return "Standard C++ Streams";
#endif
}
