#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[6][6];
    vector<int> sum_;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            sum_.push_back(sum);
        }
    }
    sort(sum_.begin(), sum_.end());
    cout << sum_[sum_.size()-1];
    return 0;
}