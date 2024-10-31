#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;        
    vector<int> A(n); 
    int sum = 0;    

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    double M = static_cast<double>(sum) / n;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > M)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
