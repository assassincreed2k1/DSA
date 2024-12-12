// #include <iostream>
// #include <regex>
// #include <string>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     cin.ignore();
//     string html, line;

//     while (n--)
//     {
//         getline(cin, line);
//         html += line + "\n";
//     }

//     regex pattern(R"(<a\s+href=["']([^"']+)["'][^>]*>(?:<[^>]+>)*([^<]*))");
//     smatch match;
//     string::const_iterator searchStart(html.cbegin());

//     while (regex_search(searchStart, html.cend(), match, pattern))
//     {
//         string link = match[1];
//         string description = match[2];

//         if (!description.empty())
//         {
//             cout << link << "," << description << endl;
//         }
//         else
//         {
//             cout << link << "," << endl;
//         }

//         searchStart = match.suffix().first;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <regex>
    using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    string html, line;

    for (int i = 0; i < N; ++i)
    {
        getline(cin, line);
        html += line + "\n";
    }

    regex linkRegex(R"(<a\s+[^>]*href=["']([^"']+)["'][^>]*>(.*?)</a>)");
    smatch match;

    string::const_iterator searchStart(html.cbegin());
    while (regex_search(searchStart, html.cend(), match, linkRegex))
    {
        string link = match[1].str();
        string text = match[2].str();

        regex tagRegex(R"(<[^>]+>)");
        text = regex_replace(text, tagRegex, "");

        link.erase(link.find_last_not_of(" \t\n\r\f\v") + 1);
        link.erase(0, link.find_first_not_of(" \t\n\r\f\v"));
        text.erase(text.find_last_not_of(" \t\n\r\f\v") + 1);
        text.erase(0, text.find_first_not_of(" \t\n\r\f\v"));

        cout << link << "," << text << endl;

        searchStart = match.suffix().first;
    }

    return 0;
}