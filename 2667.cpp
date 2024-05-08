//https://velog.io/@e7838752/boj2667
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool visited[25][25];
int map[25][25];
int n;

int bfs(int x, int y)
{
	int count = 0;
	queue<pair<int, int>> que; //#
	visited[x][y] = true;
	que.push({x,y});
	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
                count++;
		for (int i=0; i<4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (!visited[nx][ny] && map[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				que.push({nx,ny});
			}
		}
	}
	return count;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++){
		string number;
		cin >> number;
        	for (int j = 0; j < n; j++)
		{
			map[i][j] = number[j] - '0'; //#
	    	}
	}
 
	vector <int> house;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (!visited[i][j] && map[i][j] == 1) house.push_back(bfs(i, j)); //#
		}
	}
	sort(house.begin(), house.end());
	cout << house.size() << "\n";
	for (int i=0; i<house.size(); i++)
	{
		cout << house[i] << "\n";
	}
}
