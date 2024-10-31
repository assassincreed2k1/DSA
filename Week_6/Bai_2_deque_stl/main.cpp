#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> maxValueArray(int arr[], int n, int k)
{
    vector<int> maxValue;
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    maxValue.push_back(max);

    for (int i = 1; i < n - k + 1; i++)
    {
        if (arr[i + k - 1] > max)
        {
            max = arr[i + k - 1];
        }
        if (arr[i - 1] == max)
        {
            max = INT_MIN;
            for (int j = i; j < i + k; j++)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                }
            }
        }
        maxValue.push_back(max);
    }
    return maxValue;
}

int main()
{
    int q;
    cin >> q;
    vector<vector<int>> ans;
    for (int k = 0; k < q; k++)
    {
        int sizeArr;
        cin >> sizeArr;
        int arr[sizeArr];
        int sizeSmallArr;
        cin >> sizeSmallArr;
        for (int i = 0; i < sizeArr; i++)
        {
            cin >> arr[i];
        }
        ans.push_back(maxValueArray(arr, sizeArr, sizeSmallArr));
    }
    for (int i = 0; i < q; i++)
    {
        for (int x : ans[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
