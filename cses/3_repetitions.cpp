// https://cses.fi/problemset/task/1069
#include <iostream>
using namespace std;

int main()
{
    string dna;
    getline(cin, dna);

    int ans = 1;
    int current = 1;
    char prevChar = dna[0];

    for (int i = 1; i < dna.size(); i++)
    {
        if (dna[i] == prevChar)
        {
            current++;
        }
        else
        {
            ans = max(ans, current);
            current = 1;
        }
        prevChar = dna[i];
    }

    cout << max(ans, current);

    return 0;
}