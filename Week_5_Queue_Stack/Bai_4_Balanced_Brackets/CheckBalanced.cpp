#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

std::string isBalanced(const std::string &s)
{
    std::stack<char> stack;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (stack.empty())
            {
                return "no";
            }
            char top = stack.top();
            stack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return "no";
            }
        }
    }
    return stack.empty() ? "yes" : "no";
}

int main()
{
    int n;
    vector<string> arrStr;
    cin >> n;

    for (int i = 0; i < n;i++){
        std::string s;
        std::cin >> s;
        arrStr.push_back(s);
    }
    for (int i = 0; i < n;i++){
        std::cout << isBalanced(arrStr[i]) << std::endl;
    }
    return 0;
}
