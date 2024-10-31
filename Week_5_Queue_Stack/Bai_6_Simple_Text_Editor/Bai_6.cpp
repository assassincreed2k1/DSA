#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int requestCount;
    cin >> requestCount;

    string currentString = "";
    vector<string> history = {};
    history.push_back(currentString);

    while (requestCount > 0)
    {
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            string appendString;
            cin >> appendString;
            currentString += appendString;
            history.push_back(currentString);
        }
        else if (operation == 2)
        {
            int lengthToRemove;
            cin >> lengthToRemove;
            if (lengthToRemove > currentString.length())
            {
                lengthToRemove = currentString.length();
            }
            currentString.erase(currentString.end() - lengthToRemove, currentString.end());
            history.push_back(currentString);
        }
        else if (operation == 3)
        {
            int index;
            cin >> index;
            if (index > 0 && index <= currentString.length())
            {
                cout << currentString[index - 1] << "\n";
            }
        }
        else if (operation == 4)
        {
            history.pop_back();
            currentString = history[history.size() - 1];
        }
        requestCount--;
    }
}
