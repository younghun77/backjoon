//https://velog.io/@e7838752/boj2606
#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> computers[101];
int num_computers;

void dfs(int x) {
	visited[x] = true;
	for(int i = 0; i < computers[x].size(); i++){ //computers[x].size()는 computer[x]와 연결된 개수만큼 loop
		int y = computers[x][i]; //y는 computers[x]와 연결된 computer 번호
		if(!visited[y]) dfs(y); //computer y를 방문한 이력이 없다면 y부터 다시 dfs로
	}
}

int main() {
	cin >> num_computers;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
    //computers[from] 및 computers[to]와 연결된 computer를 vector에 push 
		computers[from].push_back(to);
		computers[to].push_back(from);	// 양방향 연결해준 곳
	}
	dfs(1); //1번과 연결된 컴퓨터 개수 찾기
	
	int answer = 0;
	
	for (int i=2; i<=num_computers; i++) // 등호 빼먹은 곳
		if(visited[i]) answer++; //감염된 컴퓨터의 개수를 제외하는것이니까 자기 자신(1번 computer)은 제외해야 함
	
	cout << answer << endl;
}
