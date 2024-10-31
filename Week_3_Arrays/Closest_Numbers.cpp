#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

class pair_num
{
public:
    int num_1;
    int num_2;
};

map<int, vector<pair_num>> map_number;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int hieu_min = abs(arr[0] - arr[1]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int hieu_cur = abs(arr[i] - arr[j]);
            if (hieu_cur < hieu_min)
            {
                map_number.erase(hieu_min);
                pair_num pair_;
                pair_.num_1 = arr[i];
                pair_.num_2 = arr[j];
                map_number[hieu_cur].push_back(pair_);
                hieu_min = hieu_cur;
            }
            else if (hieu_cur == hieu_min)
            {
                pair_num pair_;
                pair_.num_1 = arr[i];
                pair_.num_2 = arr[j];
                map_number[hieu_cur].push_back(pair_);
            }
            else
            {
                break;
            }
        }
    }
    for (size_t i = 0; i < map_number[hieu_min].size(); i++)
    {
        cout << map_number[hieu_min][i].num_1 << " " << map_number[hieu_min][i].num_2 << " ";
    }
    return 0;
}