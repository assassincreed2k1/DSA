#include <iostream>
#include <regex>
#include <set>
#include <string>

int main()
{
    std::string input, line;
    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    std::set<std::string> emails; // To store unique emails

    // Read all input lines
    while (std::getline(std::cin, line))
    {
        input += line + "\n";
    }

    // Find all matches
    auto words_begin = std::sregex_iterator(input.begin(), input.end(), email_regex);
    auto words_end = std::sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it)
    {
        emails.insert(it->str()); // Add to set to ensure uniqueness
    }

    // Print emails sorted alphabetically
    bool first = true;
    for (const auto &email : emails)
    {
        if (!first)
            std::cout << ";";
        std::cout << email;
        first = false;
    }

    return 0;
}
