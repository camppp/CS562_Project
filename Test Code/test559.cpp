#include <iostream>
#include "primo/program_options/options_config.h"

struct Options {
    std::wstring inputFile;
    std::wstring outputFile;
};

void setDefaultOptions(Options& opt)
{
    opt.inputFile = getExeDir() + L"\\..\\assets\\mov\\big_buck_bunny_trailer_iphone.m4v";
    opt.outputFile = getExeDir() + L"\\big_buck_bunny_trailer_iphone";
}

void help(primo::program_options::OptionsConfig<wchar_t>& optcfg)
{
    std::wcout << L"Usage: demux_mp4_file -i <input_mp4_file> -o <output_mp4_file_name_without_extension>\n";
    primo::program_options::doHelp(std::wcout, optcfg);
}

bool validateOptions(Options& opt)
{
    // Add validation logic for the provided options
    // Return true if options are valid, false otherwise
}

int main(int argc, char* argv[])
{
    primo::program_options::OptionsConfig<wchar_t> optcfg;
    optcfg.add(L"i", L"input", L"Input MP4 file", primo::program_options::OptionType::String);
    optcfg.add(L"o", L"output", L"Output MP4 file name without extension", primo::program_options::OptionType::String);

    Options opt;
    setDefaultOptions(opt);

    if (argc < 2) {
        help(optcfg);
        return 1;
    }

    if (!primo::program_options::parseCommandLine(argc, argv, optcfg, opt)) {
        help(optcfg);
        return 1;
    }

    if (!validateOptions(opt)) {
        std::wcout << L"Invalid options provided.\n";
        help(optcfg);
        return 1;
    }

    // Call demux function with the provided options
    // demuxMP4(opt.inputFile, opt.outputFile);

    return 0;
}
