#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int> &arr)
{
    vector<int> lis;

    for (int x : arr)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
        {
            lis.push_back(x); 
        }
        else
        {
            *it = x; 
        }
    }

    return lis.size();
}

int main()
{
    int n;
    cin >> n; // Read size of array
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr) << endl;
    return 0;
}
