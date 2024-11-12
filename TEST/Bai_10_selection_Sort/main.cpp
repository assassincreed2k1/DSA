#include <iostream>
#include <vector>

using namespace std;

void printSelectionSort(vector<int> arr)
{

    for (int j = arr.size() - 1; j >= 0; j--)
    {
        int max_index = j;
        for (size_t i = 0; i < arr.size() - 1 - j; i++)
        {
            if(arr[i]>arr[max_index]){
                max_index = i;
            }
        }
        cout << max_index << " ";
        swap(arr[j], arr[max_index]);
    }
}

int main()
{
    int num;
    cin >> num;
    vector<vector<int>> sortQuestion;
    for (int ques = 0; ques < num; ques++)
    {
        int size;
        cin >> size;
        vector<int> arr;
        for (int i = 0; i < size;i++){
            cin >> arr[i];
        }
        sortQuestion.push_back(arr);
    }
    for(int i = 0; i < num;i++){
        printSelectionSort(sortQuestion[i]);
    }
}