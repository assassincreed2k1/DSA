#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(const string &s)
{
    int n = s.length();
    int anagram_pairs = 0;

    unordered_map<string, int> freq_map;

    for (int i = 0; i < n; ++i)
    {
        vector<int> char_count(26, 0);

        for (int j = i; j < n; ++j)
        {
            char_count[s[j] - 'a']++;
            string hash_key = "";
            for (int k = 0; k < 26; ++k)
            {
                hash_key += to_string(char_count[k]) + "#";
            }
            anagram_pairs += freq_map[hash_key];
            freq_map[hash_key]++;
        }
    }
    return anagram_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);
        int result = sherlockAndAnagrams(s);
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
