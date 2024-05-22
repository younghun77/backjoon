//https://www.acmicpc.net/problem/7569
//https://blog.naver.com/0x7ffffffe/223300798877
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

bool visited[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> que;
vector<int> vec;
//1.익은 복숭아는 여러곳에 위치함
//2.익은 복숭아를 기준으로 상하좌우 이동하면서 visited 인지 확인 후 아니면 증가
//3.start 지점부터 가장 많은 count가 답이 됨

int bfs(int x, int y, int z)
{
  int curx, cury, curz;
  int count;
  que.push({x, y, z})
  visited[x][y][z] = true;
  
  while(!que.empty())
  {
    std::tie(curx, cury, curz) = que.front();
    que.pop();
	visited[curx][cury][curz] = true;

    for (int i=0; i<6; i++)
    {
      int dx = curx+dx[i];
      int dy = cury+dy[i];
	  int dz = curz+dz[i]
      if (dx < 2 || dy < 2 || dz < 2 || dx > 100 || dy > 100 || dz > 100) continue;
      if (arr[dx][dy][dz] == 0 && !visited[dx][dy][dz])
      {
        que.push({dx,dy,dz});
		count++;
      }
    }
      
  }
  return count;

  
}
int main()
{
  for(int i=0; i<N; i++) 
	for (int j=0; j<M; j++)
      for (int k=0; k<H; k++)
            if (!visited(arr[i][j][k]) && arr[i][j][k] == 1) 
			{
				vec.push_back(bfs(i, j, k));
			}
  sort(vec.begin(), vec.end());
  cout << vec[vec.size()];
}
