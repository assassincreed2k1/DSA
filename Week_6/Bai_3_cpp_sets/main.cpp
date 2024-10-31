#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void add(vector<int> &arr, int x)
{
    arr.push_back(x);
}

void remove(vector<int> &arr, int x)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            arr.erase(arr.begin() + i);
        }
    }
}

bool found(vector<int> &arr, int x)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr;
    vector<string> ans;
    int q;
    cin >> q;
    while (q > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            add(arr, x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            remove(arr, x);
        }
        else if (type == 3)
        {
            int x;
            cin >> x;
            if (found(arr, x))
            {
                ans.push_back("Yes");
            }
            else
            {
                ans.push_back("No");
            }
        }
        q--;
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
