#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
int arr[101][101];
int n, m, k;
map<char, int>s;
bool check[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = {1,-1,0,0};
queue < pair<int, pair<int, int>>>q;
int bfs(int x,int y, int d) {
	int t = arr[x][y];
	int cnt = 0;
	if (check[x][y])return 0;
	for(int i=0; i<t;i++){
		int nx = x + dx[d] * i;
		int ny = y + dy[d] * i;
		if (nx >= n || ny >= m || nx < 0 || ny < 0)break;
		if (check[nx][ny])continue;
		check[nx][ny] = true;
		cnt++;
		t = max(t, i + arr[nx][ny]);
	}
	return cnt;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	s.insert({ 'E', 0 });
	s.insert({ 'W', 1 });
	s.insert({ 'S', 2 });
	s.insert({ 'N', 3 });
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int a, b; char c; cin >> a >> b >> c;
		int a1, b1; cin >> a1 >> b1;
		cnt+=bfs(a-1, b-1, s[c]);
		check[a1-1][b1-1] = false;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j])cout << "F" << " ";
			else cout << "S" << " ";
		}
		cout << endl;
	}
}