
#include <iostream>
#include <string>
#include <map>

// ANSI escape codes
const std::map<std::string, std::string> COLORS = {
    {"red", "\033[91m"},
    {"green", "\033[92m"},
    {"yellow", "\033[93m"},
    {"blue", "\033[94m"},
    {"cyan", "\033[96m"},
    {"purple", "\033[95m"},
};

const std::string COLOR_RESET = "\033[0m";


std::string coloredText(const std::string& text, const std::string& colorCode) {
    return colorCode + text + COLOR_RESET;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: \n <command>  | " << argv[0] << "red|green|yellow|blue|cyan|purple" << std::endl;
        return 1;
    }

    std::string colorChoice = argv[1];
    std::string textToColorize;

    getline(std::cin, textToColorize);

    auto colorIt = COLORS.find(colorChoice);
    if (colorIt == COLORS.end()) {
        std::cerr << "Invalid color choice." << std::endl;
        return 1;
    }

    std::string colorCode = colorIt->second;

    std::string coloredOutput = coloredText(textToColorize, colorCode);
    std::cout << coloredOutput << std::endl;

    return 0;
}

