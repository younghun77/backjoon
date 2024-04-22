//https://www.acmicpc.net/problem/2178
//(1,1) -> (N,M) 이동시 걸리는 시간
//1. visited[0][0]에서 시작하는가? 실제 시작 위치는 [0][0]
//2. visited[n-1][m-1] 값이 정답이 되는가? 예제를 보면 실제 target은 [N-1][M-1]임
//아래는 input
//4 6
//101111
//101010
//101011
//111011 <- 3,5



#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
int arr[104][104];
int visited[104][104];
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
queue<pair<int,int>> q;


int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}	
	visited[0][0] = 1;
	q.push({0,0});
	
	
	while(q.size())
	{
		tie(x,y) = q.front();
		q.pop(); 
		for(int i=0; i<4; i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			
			if(nx<0 || nx>=n || ny<0 || ny>=m || !arr[nx][ny])continue;
			if(visited[nx][ny])continue;
			
			q.push({nx,ny});
			visited[nx][ny] = visited[x][y] + 1;
			
		}
	}
	
	
	cout << visited[n-1][m-1];
	
	return 0;
} 
