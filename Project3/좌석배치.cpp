#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int c, a, b; cin >> a >> b;
	cin >> c;
	//b가 행  a가 열 ;
	int cnt = 0;
	int num = 1;
	int nx = 0, ny = 1;

	if (c > a * b) {
		cout << "0";
		return 0;
	}
	while (1) {
		if (num == c+1) {
			cout << ny << " " << nx << endl;
			break;
		}
		 nx += dx[cnt];
		 ny += dy[cnt];
		 if (nx > b || ny > a || nx < 1 || ny < 1 || n[nx][ny] != 0) {
			 nx -= dx[cnt];
			 ny -= dy[cnt];
			 cnt = (cnt + 1) % 4;
		 }
		else n[nx][ny] = num++;

	}
	/*for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= a; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}*/
}