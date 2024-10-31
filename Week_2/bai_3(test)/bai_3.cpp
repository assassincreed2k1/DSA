#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_odd(int n)
{
    return n % 2 != 0;
}

vector<int> sort_(vector<int> arr, int n)
{
    vector<int> id;
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        if (is_odd(arr[i]))
        {
            id.push_back(i);
            val.push_back(arr[i]);
        }
    }
    sort(val.begin(), val.end());
    for (size_t i = 0; i < id.size(); i++)
    {
        arr[id[i]] = val[i];
    }
    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        arr.push_back(cur);
    }
    vector<int> result = sort_(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}