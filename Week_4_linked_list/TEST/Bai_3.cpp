#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;        
    vector<int> A(n); 

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int x;
    cin >> x; 

    A.erase(A.begin() + (x - 1));

    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i];
        if (i < A.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl; 

    return 0;
}
