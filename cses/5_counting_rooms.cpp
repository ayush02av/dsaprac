// https://cses.fi/problemset/task/1192
#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> STEPS = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(pair<int, int> current, vector<vector<char>> &building, int &n, int &m, vector<vector<int>> &visited)
{
    for (auto step : STEPS)
    {
        int newX = current.first + step.first;
        int newY = current.second + step.second;
        if (newX < 0 || newX == n || newY < 0 || newY == m || visited[newX][newY] == 1)
            continue;

        visited[newX][newY] = 1;
        if (building[newX][newY] == '.')
            dfs({newX, newY}, building, n, m, visited);
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<char>> building;
    for (int i = 0; i < n; i++)
    {
        building.push_back(vector<char>());
        for (int j = 0; j < m; j++)
        {
            char val;
            cin >> val;
            building[i].push_back(val);
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                if (building[i][j] == '.')
                {
                    dfs({i, j}, building, n, m, visited);
                    rooms++;
                }
            }
        }
    }

    cout << rooms;

    return 0;
}