#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int number_of_test;
    cin >> number_of_test;
    vector<bool> answer_;

    for (int j = 0; j < number_of_test; j++)
    {
        int n;
        cin >> n;
        int arr[n];
        int total_sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total_sum += arr[i];
        }

        int left_sum = 0;
        bool check_ = false;

        for (int i = 0; i < n; i++)
        {
            if (left_sum == total_sum - left_sum - arr[i])
            {
                check_ = true;
                break;
            }
            left_sum += arr[i];
        }

        answer_.push_back(check_);
    }

    for (int i = 0; i < number_of_test; i++)
    {
        if (answer_[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
