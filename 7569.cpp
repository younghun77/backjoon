//https://www.acmicpc.net/problem/7569
//https://blog.naver.com/0x7ffffffe/223300798877
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

bool visited[101][101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<tuple<int, int, int>> que;
vector<int> vec;
//1.익은 복숭아는 여러곳에 위치함
//2.익은 복숭아를 기준으로 상하좌우 이동하면서 visited 인지 확인 후 아니면 증가
//3.start 지점부터 가장 많은 count가 답이 됨

int bfs(int x, int y, int z)
{
  que.push({x, y, z})
  visited[x][y][z] = true;
  
  while(!que.empty())
  {
    int x = que.front();
    visited[x] = true;
    que.pop();

    for (int i=0; i<4; i++)
    {
      int dx = x+dx[i];
      int dy = y+dy[i];
      if (dx < 2 || dy < 2 || dx > 100 || dy > 100) continue;
      if (arr[dx][dy] == 0 && !visited[dx][dy])
      {
        que.push({dx,dy});
        visited[dx][dy] = true;
      }
    }
      
  }

  
}
int main()
{
  for(int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      for (int k=0; k<H; k++)
        {
            if (!visited(arr[i][j][k]) && arr[i][j][k] == 1) vec.push_back(bfs(i, j, k));
          
        }
  sort(vec.begin(), vec.end());
  cout << vec[0];
}
