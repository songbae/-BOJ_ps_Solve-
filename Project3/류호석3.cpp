#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[11][11];
int n, m, k;
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,-1,1,0,1,-1 };
queue<pair<int, pair<int, int>>>q;//���� ����, ��,��
bool check[26];
int ans;
void bfs(int x, int y, string target) {
	q.push({ 1, {x,y} });
	while (!q.empty()) {
		int a = q.front().second.first;
		int b = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
			if (cnt == target.size()){// target�� �������� ans++
				ans++;
			continue;
		}
		for (int i = 0; i < 8; i++) {
			int nx = (a + dx[i])%n;
			int ny = (b + dy[i])%m;
			if (arr[nx][ny] != target[cnt])continue;// �ٸ��� pass
			q.push({cnt+1, { nx,ny }});//������ �ִ´�
		}

	}
}
int main() {
	cin >> n >> m >> k; f;
	for (int i = 0; i < n; i++) {
		string pp; cin >> pp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = pp[j];
		}
	}
	while (k) {
		string s; cin >> s;
		ans = 0;
			for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
				if (arr[i][j] != s[0])continue;// ���ڸ��� �ٸ��� �����ʴ´�
				bfs(i, j, s);
			}
			cout << ans << "\n";
		k--;
	}

		
	
}