//https://www.acmicpc.net/problem/7569
//https://blog.naver.com/0x7ffffffe/223300798877
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int M, N, H;
bool visited[101][101][101];
int arr[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> que;
vector<int> vec;

int bfs(int x, int y, int z)
{
    int count = 0;
    que.push({x, y, z});
    visited[x][y][z] = true;

    while (!que.empty())
    {
        int curx, cury, curz;
        tie(curx, cury, curz) = que.front();
        que.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int nz = curz + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
            if (arr[nx][ny][nz] == 0 && !visited[nx][ny][nz])
            {
                que.push({nx, ny, nz});
                visited[nx][ny][nz] = true;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int temp;
                cin >> temp;
                arr[k][j][i] = temp;
                visited[k][j][i] = false;
                if (!visited[k][j][i] && arr[k][j][i] == 1) 
                {
                    vec.push_back(bfs(k, j, i));
                }
            }
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.back();
}
