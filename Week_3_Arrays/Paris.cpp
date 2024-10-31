#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

class pair_num
{
public:
    int x1;
    int x2;
};

bool big_to_small(int x, int y)
{
    return x > y;
}

int main()
{
    vector<pair_num> result;
    int count = 0;
    int n;
    cin >> n;
    int K;
    cin >> K;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, big_to_small);

    if (abs(arr[0] - arr[n - 1]) < K)
    {
        cout << "0";
        return 0;
    }

    int dem = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = dem; j < n; j++)
        {
            if (abs(arr[i] - arr[j] == K))
            {
                pair_num cur_pair;
                cur_pair.x1 = arr[i];
                cur_pair.x2 = arr[j];
                result.push_back(cur_pair);
                count++;
                dem = j + 1;
                break;
            }
            if (abs(arr[i] - arr[j]) > K)
            {
                dem = j;
                break;
            }
        }
    }
    cout << count << endl;
    // for (size_t i = 0; i < result.size(); i++)
    // {
    //     cout << result[i].x1 <<" "<< result[i].x2<<" ";
    // }
    return 0;
}

// Giải quyết bài toán bằng cath sử dụng bài toán tìm kiếm nhị phân thay thế vòng lặp for