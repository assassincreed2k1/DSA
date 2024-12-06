#include <iostream>
#include <vector>

using namespace std;

void computeLPSArray(string pattern, vector<int> &lps)
{
    lps[0] = 0;
    int len = 0;
    int m = (int)pattern.length();
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

std::vector<int> KMPSearch(string s, string pattern)
{
    int n = (int)s.length();
    int m = (int)pattern.length();

    vector<int> lps(m, 0);
    vector<int> result;

    computeLPSArray(pattern, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (s[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        if (i < n && s[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}

int main()
{
    std::string S, pattern;

    std::getline(std::cin, S);
    std::getline(std::cin, pattern);

    std::vector<int> positions = KMPSearch(S, pattern);

    if (positions.empty())
    {
        std::cout << "Pattern not found in the string." << std::endl;
    }
    else
    {
        for (int pos : positions)
        {
            std::cout << "Pattern found at index " << pos << endl;
        }
    }

    return 0;
}
