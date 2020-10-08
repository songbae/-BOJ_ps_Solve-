#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 999999
#define MAX 102
using namespace std;
int n, m;
int mp[MAX][MAX];
int dist[MAX][MAX];
int dx[3][4] = { {0,1,0,-1},{0,2,0,-2}, {0,3,0,-3} };
int dy[3][4] = { {1,0,-1,0},{2,0,-2,0}, {3,0,-3,0} };
int endx, endy, ed;
vector<pair<int,pair<int,int>>>v[MAX][MAX];
priority_queue<pair<int,tuple<int,int,int>>>q;
void dfs() {
	while (!q.empty()) {//다익스트라
		int cost = -q.top().first;// 처음 가중치 0으로 시작 
		int x = get<1>(q.top().second);
		int y = get<2>(q.top().second);
		int nowd = get<0>(q.top().second);//현재 방향 
		q.pop();
		for (int i = 0; i < v[x][y].size(); i++) {
			int nx = v[x][y][i].second.first;// 다음위치
			int ny = v[x][y][i].second.second;//다음위치
			int nextd = v[x][y][i].first;
			int ncost = 1;
			if (abs(nextd - nowd) == 3)ncost++;// 다음위치와 현재위치의 방향이 다를떄
			else ncost += abs(nextd - nowd);// 같으거나 차이가 2보다적을떄 
			if (nx == endx && ny == endy&&dist[x][y]!=INF) {// 만약 다음위치가 목표값일 때
				if (abs(nextd - ed)== 3)ncost++;//목표위치의 방향과 현재의 방향 비교 
				else ncost += abs(nextd - ed);// 목표위치의 방향과 현재 방향 비교 
			}
			if (dist[nx][ny] > dist[x][y] + ncost) {
				dist[nx][ny] = dist[x][y] + ncost;
				q.push({ -dist[nx][ny],{nextd,nx,ny} });
			}

		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)for(int j = 1; j <= m; j++) cin >> mp[i][j];
	for (int i = 0; i < MAX; i++)for(int j = 0; j < MAX; j++)dist[i][j] = INF;
	for (int i = 1; i <= n; i++) {//행
		for (int j = 1; j <= m; j++) {//열 
			for (int d1 = 0; d1 < 4; d1++) {//이게  방향 
				for (int d2 = 0; d2 < 3; d2++) {// 한칸두칸세칸 
					int nx = i + dx[d2][d1];
					int ny = j + dy[d2][d1];
					if (nx > n || ny > m || nx <= 0 || ny <= 0)break;
					if (mp[i][j] == 0 && mp[nx][ny] == 0) {
						v[i][j].push_back({ d1,{nx,ny} });//벡터를 2차원으로만들어서 그래프 문제풀듯이  간선들 연결 
					}
					else break;
				}
			}
		}
	}
	int stx, sty, std;
	cin >> stx >> sty >> std;// 시작 x,y , d 방향 
	cin >> endx >> endy >> ed;//끝 x,y d 방향 
	if (std == 1) std -= 1;// 시작 방향과 끝방향을 0,1,2,3에맞게 변경 
	else if (std == 2)std = 2;// 좌표변환 
	else if (std == 3)std -= 2;
	else if (std == 4)std -= 1;
	if (ed == 1) ed -= 1;
	else if (ed == 2)ed = 2;
	else if (ed == 3) ed -= 2;
	else if (ed == 4)ed -= 1;
	dist[stx][sty] = 0;
	q.push({ 0,{std, stx, sty } });
	if (stx == endx && sty == endy) {//만약에 시작과 끝위치가 같다면 
		if (std == ed)cout << "0";//방향이 같다면 0출력
		else {
			if (abs(std - ed) > 2)cout << "1";//방향이 다르다면 다른만큼 가중치추가
			else cout << abs(std - ed);//가중치만큼 출력 
		}
		return 0;
	}
	dfs();//다익스트라 ~
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == INF)cout << "0" << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << dist[endx][endy];
}