#include <CLI/CLI.hpp>

struct Config {
    std::string screen_capture_file;
    std::string screen_capture_connection_id;
    int screen_capture_width = 960;
};

int main(int argc, char** argv) {
    Config config;
    CLI::App app{"Screen Capture Application"};

    app.add_option("--screen-capture-file",
                  config.screen_capture_file,
                  "Screen capture file path")
      ->check(CLI::ExistingFile)
      ->group("EXPERIMENTAL_OPTIONS");

    app.add_option("--screen-capture-connection-id",
                  config.screen_capture_connection_id,
                  "Screen capture connection id")
      ->excludes("--screen-capture-report")
      ->group("EXPERIMENTAL_OPTIONS");

    app.add_option("--screen-capture-width", config.screen_capture_width,
                  "Width for screen-capture (NON NEGATIVE multiple of 4). default: 960")
      ->check(CLI::PositiveNumber)
      ->group("EXPERIMENTAL_OPTIONS");

    CLI11_PARSE(app, argc, argv);

    // Additional application logic using the parsed configuration
    // ...

    return 0;
}
