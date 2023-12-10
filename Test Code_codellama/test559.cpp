#include <iostream>
#include <string>
#include <primo/program_options.h>

using namespace std;

// Function to set default options
void setDefaultOptions(primo::program_options::options_description& desc) {
    // Set default input and output file names
    desc.add_options()
        ("input,i", primo::program_options::value<string>()->default_value("input.mp4"), "Input MP4 file")
        ("output,o", primo::program_options::value<string>()->default_value("output"), "Output file name without extension");
}

// Function to display help information
void help(primo::program_options::options_description& desc) {
    cout << "Usage: demux [options]" << endl;
    cout << desc << endl;
}

// Function to validate options
bool validateOptions(primo::program_options::variables_map& vm) {
    // Check if input file exists
    if (!vm.count("input")) {
        cout << "Error: Input file not specified" << endl;
        return false;
    }

    // Check if output file name is valid
    if (!vm.count("output")) {
        cout << "Error: Output file name not specified" << endl;
        return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    // Set default options
    primo::program_options::options_description desc("Demux Options");
    setDefaultOptions(desc);

    // Parse command-line arguments
    primo::program_options::variables_map vm;
    primo::program_options::store(primo::program_options::parse_command_line(argc, argv, desc), vm);
    primo::program_options::notify(vm);

    // Display help information if requested
    if (vm.count("help")) {
        help(desc);
        return 0;
    }

    // Validate options
    if (!validateOptions(vm)) {
        return 1;
    }

    // Demux the input MP4 file
    string inputFile = vm["input"].as<string>();
    string outputFile = vm["output"].as<string>();
    // TODO: Implement demuxing logic here

    return 0;
}
