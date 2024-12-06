#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string html, line;

    while (n--)
    {
        getline(cin, line);
        html += line + "\n";
    }

    regex pattern(R"(<a\s+href=["']([^"']+)["'][^>]*>(?:<[^>]+>)*([^<]*))");
    smatch match;
    string::const_iterator searchStart(html.cbegin());

    while (regex_search(searchStart, html.cend(), match, pattern))
    {
        string link = match[1];
        string description = match[2];

        if (!description.empty())
        {
            cout << link << "," << description << endl;
        }
        else
        {
            cout << link << "," << endl;
        }

        searchStart = match.suffix().first;
    }

    return 0;
}
