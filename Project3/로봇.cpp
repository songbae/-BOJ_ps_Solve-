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
	while (!q.empty()) {//���ͽ�Ʈ��
		int cost = -q.top().first;// ó�� ����ġ 0���� ���� 
		int x = get<1>(q.top().second);
		int y = get<2>(q.top().second);
		int nowd = get<0>(q.top().second);//���� ���� 
		q.pop();
		for (int i = 0; i < v[x][y].size(); i++) {
			int nx = v[x][y][i].second.first;// ������ġ
			int ny = v[x][y][i].second.second;//������ġ
			int nextd = v[x][y][i].first;
			int ncost = 1;
			if (abs(nextd - nowd) == 3)ncost++;// ������ġ�� ������ġ�� ������ �ٸ���
			else ncost += abs(nextd - nowd);// �����ų� ���̰� 2���������� 
			if (nx == endx && ny == endy&&dist[x][y]!=INF) {// ���� ������ġ�� ��ǥ���� ��
				if (abs(nextd - ed)== 3)ncost++;//��ǥ��ġ�� ����� ������ ���� �� 
				else ncost += abs(nextd - ed);// ��ǥ��ġ�� ����� ���� ���� �� 
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
	for (int i = 1; i <= n; i++) {//��
		for (int j = 1; j <= m; j++) {//�� 
			for (int d1 = 0; d1 < 4; d1++) {//�̰�  ���� 
				for (int d2 = 0; d2 < 3; d2++) {// ��ĭ��ĭ��ĭ 
					int nx = i + dx[d2][d1];
					int ny = j + dy[d2][d1];
					if (nx > n || ny > m || nx <= 0 || ny <= 0)break;
					if (mp[i][j] == 0 && mp[nx][ny] == 0) {
						v[i][j].push_back({ d1,{nx,ny} });//���͸� 2�������θ��� �׷��� ����Ǯ����  ������ ���� 
					}
					else break;
				}
			}
		}
	}
	int stx, sty, std;
	cin >> stx >> sty >> std;// ���� x,y , d ���� 
	cin >> endx >> endy >> ed;//�� x,y d ���� 
	if (std == 1) std -= 1;// ���� ����� �������� 0,1,2,3���°� ���� 
	else if (std == 2)std = 2;// ��ǥ��ȯ 
	else if (std == 3)std -= 2;
	else if (std == 4)std -= 1;
	if (ed == 1) ed -= 1;
	else if (ed == 2)ed = 2;
	else if (ed == 3) ed -= 2;
	else if (ed == 4)ed -= 1;
	dist[stx][sty] = 0;
	q.push({ 0,{std, stx, sty } });
	if (stx == endx && sty == endy) {//���࿡ ���۰� ����ġ�� ���ٸ� 
		if (std == ed)cout << "0";//������ ���ٸ� 0���
		else {
			if (abs(std - ed) > 2)cout << "1";//������ �ٸ��ٸ� �ٸ���ŭ ����ġ�߰�
			else cout << abs(std - ed);//����ġ��ŭ ��� 
		}
		return 0;
	}
	dfs();//���ͽ�Ʈ�� ~
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == INF)cout << "0" << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << dist[endx][endy];
}