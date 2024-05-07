//https://velog.io/@e7838752/boj2667
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
bool visited[25][25];
int map[25][25];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y) {
	int count = 0;
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		count++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visited[nx][ny] && map[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
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
		for (int j = 0; j < n; j++){
			map[i][j] = number[j]-'0';
		}
	}

	vector<int> houses;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) houses.push_back(bfs(i, j));
		}
	}

	sort(houses.begin(), houses.end());
	cout << houses.size() << "\n";
	for (int i = 0; i < houses.size(); i++) {
		cout << houses[i] << "\n";
	}
}
