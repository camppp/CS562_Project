#ifndef PY4DGEO_TEST_DATA_DIRECTORY
#error Test data directory needs to be set from CMake
#endif

#define DATAPATH(filename) (std::string(PY4DGEO_TEST_DATA_DIRECTORY) + "/" + filename)
