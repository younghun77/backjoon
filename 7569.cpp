//https://www.acmicpc.net/problem/7569
//https://blog.naver.com/0x7ffffffe/223300798877
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int M, N, H;
int dist[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> que;

int main()
{
    cin >> M >> N >> H;

    for (int h=0; h<H; h++) 
    {
        for (int n=0; n<N; n++)
        {
            for (int m=0; m<M; m++)
            {
                int temp;
                cin >> temp;
                if (temp == 1) que.push({m, n, h});
                if (temp == 0) dist[m][n][h] = -1;
            }
        }
    }

    while(!que.empty())
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
            if (dist[nx][ny][nz] != -1) continue;
            dist[nx][ny][nz] = dist[curx][cury][curz]+1;
            que.push({nx, ny, nz});
        }

    }

    int ans = 0;
    for (int h=0; h<H; h++) 
    {
        for (int n=0; n<N; n++)
        {
            for (int m=0; m<M; m++)
            {
                if(dist[m][n][h] == -1)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, dist[m][n][h]);
            }
        }
    }
    cout << ans << "\n";
}
