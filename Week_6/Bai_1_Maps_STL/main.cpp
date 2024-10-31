#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void addMark(string x, int y, map<string, int> &studentList)
{
    if (studentList.find(x) != studentList.end())
    {
        studentList[x] += y;
        return;
    }
    else
    {
        studentList[x] = y;
    }
}

bool removeMark(string x, map<string, int> &studentList)
{
    if (studentList.find(x) != studentList.end())
    {
        studentList.erase(x);
        return true;
    }
    return false;
}

int main()
{
    map<string, int> studentList;
    vector<int> answer;
    int q;
    cin >> q;
    while (q > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            string name;
            cin >> name;
            int mark;
            cin >> mark;
            addMark(name, mark, studentList);
        }
        else if (type == 2)
        {
            string name;
            cin >> name;
            removeMark(name, studentList);
        }
        else if (type == 3)
        {
            string name;
            cin >> name;
            answer.push_back(studentList[name]);
        }
        q--;
    }
    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
