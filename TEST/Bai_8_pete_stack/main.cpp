#include <iostream>
#include <vector>
using namespace std;

int biggestPoint(vector<int> arr_1, vector<int> arr_2, int m, int n, int x)
{
    int sum = 0;
    int result = 0;
    int i = 0, j = 0;

    while (i < n && sum + arr_1[i] <= x)
    {
        sum += arr_1[i];
        i++;
    }
    result = i;

    while (j < m && (sum + arr_2[j] <= x))
    {
        sum += arr_2[j];
        j++;

        while (sum > x && i > 0)
        {
            i--;
            sum -= arr_1[i];
        }

        if (sum <= x)
        {
            result = max(result, i + j);
        }
    }

    return result;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> arr_1(n), arr_2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr_1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr_2[i];
    }
    cout << biggestPoint(arr_1, arr_2, m, n, x);
}
