#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSelectionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            cout << i << " " << minIndex<<" ";
            swap(arr[i], arr[minIndex]);
        }
    }
    cout << endl;
}

int main()
{
    int numQ;
    cin >> numQ;
    vector<vector<int>> ans;
    while (numQ > 0)
    {
        int size;
        cin >> size;
        vector<int> arr;
        for (int i = 0; i < size; i++)
        {
            int data;
            cin >> data;
            arr.push_back(data);
        }
        ans.push_back(arr);
        numQ--;
    }
    for (size_t i = 0; i < ans.size(); i++)
    {
        printSelectionSort(ans[i]);
    }
    return 0;
}
