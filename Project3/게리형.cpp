#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int map1[21][21];
int check[21][21];
int distsum[6];
int MAX = 0, MIN = 1e9, ans = 1e9;
int n
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0, 1,-1 };
queue < pair<int, int>>q;
void checkmap(int x, int y, int d1, int d2) {// �ܰ��� 5�� ä��� 
	int cnt1 = d1, cnt2 = d2;
	for (int i = 0; i <= cnt1; i++) {
		check[x + i][y - i] = 5;
		check[x + cnt2 + i][y + cnt2 - i] = 5;
	}
	for (int i = 0; i <= cnt2; i++) {
		check[x + i][y + i] = 5;
		check[x + cnt1 + i][y - cnt1 + i] = 5;
	}
	return;//������� �ܰ� 5��ä���Ϸ�
}
void bfs(int x, int y, int d1, int d2) {//�ܰ��� ���� 5��ä��� 
	q.push({ x + 1,y });
	check[x + 1][y] = 5;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
			if (check[nx][ny] == 5)continue;
			check[nx][ny] = 5;
			q.push({ nx,ny });
		}//���� 5��ä������ ��ä�������ִ� �κ�����

	}
	for (int i = 0; i < n; i++) {//�׺κе� �� �� ��ü Ž���ϸ鼭 5�� ä��� 
		for (int j = 0; j < n; j++) {
			int x1 = i, y1 = j;
			if (check[x1 - 1][y1] == 5 && check[x1 + 1][y1] == 5 && check[x1][y1 - 1] == 5 && check[x1][y1 + 1] == 5)
				check[x1][y1] = 5;
		}
	}
	for (int i = 0; i < x + d1; i++)for (int j = 0; j <= y; j++)// 1�� �׳� �ܰ��� �����ؼ� 5���ƴҰ�� 1,2,3,4üũ 
		if (check[i][j] != 5)check[i][j] = 1;
	for (int i = 0; i <= x + d2; i++)for (int j = y + 1; j < n; j++)
		if (check[i][j] != 5)check[i][j] = 2;
	for (int i = x + d1; i < n; i++)for (int j = 0; j < y - d1 + d2; j++)
		if (check[i][j] != 5)check[i][j] = 3;
	for (int i = x + d2 + 1; i < n; i++)for (int j = y - d1 + d2; j < n; j++)
		if (check[i][j] != 5)check[i][j] = 4;
	return;
}


int main() {
	cin >> n; f;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> map1[i][j];
	for (int i = 0; i < n; i++) {//x, y ���
		for (int j = 0; j < n; j++) {
			int x = i, y = j;
			for (int d1 = 1; d1 < n; d1++) {//d1,d2 ���
				for (int d2 = 1; d2 < n - y; d2++) {
					if (x + d1 + d2 >= n)continue;// �̰�� �н� 
					memset(distsum, 0, sizeof(distsum));//���������� �ʱ�ȭ
					memset(check, 0, sizeof(check));//���������� �ʱ�ȭ
					checkmap(x, y, d1, d2);//�ܰ���  5�� üũ�ϴ� �Լ� 
					bfs(x, y, d1, d2);//�������� 1,2,3,4 üũ�Լ� 
					for (int k = 0; k < n; k++)for (int p = 0; p < n; p++)for (int t = 1; t <= 5; t++)
						if (check[k][p] == t)distsum[t] += map1[k][p];//1,2,3,4 üũ�Ǿ��ִ°� �� �����ֱ� 
				}
				MAX = max({ distsum[1],distsum[2],distsum[3],distsum[4],distsum[5] });// max�� min�� ���ϱ�
				MIN = min({ distsum[1],distsum[2],distsum[3],distsum[4],distsum[5] });
				ans = min(abs(MAX - MIN), ans);// �����̸� ans�� �� �ּҰ� ���� 
			}
		}
	}
		cout << ans;//�����
}