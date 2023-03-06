// https://cses.fi/problemset/task/1083
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<int> buffer;

    int val;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        buffer.insert(val);
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (buffer.find(i) == buffer.end())
        {
            cout << i;
            break;
        }
    }

    return 0;
}