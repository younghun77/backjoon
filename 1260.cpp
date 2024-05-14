//https://velog.io/@e7838752/boj1260
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<int> graph[1001];
bool visited[1001];

void dfs(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i=0; i<graph[start].size(); i++)
    {
      int y = graph[start][i];
      if(!visited[y]) dfs(y);
    }
}
void bfs(int start)
{
    queue<int> que;
    que.push(start);
    visited[start] = true;
    while(!que.empty())
    {
      que.pop();
      int x = que.front();
      cout << x << " ";
      for (int i=0; i<graph[x].size(); i++)
      {
          int y = graph[x][i];
          if (visited[y]) continue;
          visited[y] = true;
          que.push(y);
      }
    }
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int v;
	cin >> n >> m >> v;

	int numFrom, numTo;
	for (int i = 0; i < m; i++) {
		cin >> numFrom >> numTo;
    //정점<->간선
		graph[numFrom].push_back(numTo);
		graph[numTo].push_back(numFrom);
	}

  //각 정점이 가지고 있는 간선에 대해서 sort
	for (int i = 0; i < n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	cout << endl;
	bfs(v);
	cout << endl;
}
