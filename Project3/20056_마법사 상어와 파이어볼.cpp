#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
deque<int>mp[51][51];
deque<pair<int, pair<int, int>>>ball[51][51];
bool check[1000001];
int n, m, k, num;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
void decompose() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ball[i][j].size() < 2)continue;
			int sum = 0;//질량
			int speed = 0;//속도
			int zero = 0; //0의 개수 
			int one = 0; //1의 개수 
			int d = 0;
			for (int k = 0; k < ball[i][j].size(); k++) {
				sum += ball[i][j][k].second.second;
				speed += ball[i][j][k].second.first;
				if ((ball[i][j][k].first) % 2 == 0)zero++;
				else one++;
			}
			if (zero == ball[i][j].size() || one == ball[i][j].size())d = 12;
			else d = 16;
			int many = ball[i][j].size();
			while (ball[i][j].size() > 0) {
				ball[i][j].pop_back();
			}
			while (mp[i][j].size() > 0) {
				mp[i][j].pop_back();
			}
			if (sum / 5 == 0)continue;
			if (d == 12) {
				for (int k = 0; k < 4; k++) {
					ball[i][j].push_back({ 2 * k,{speed / many,sum / 5} });
					mp[i][j].push_back(num++);
				}
			}
			else if (d == 16) {
				for (int k = 0; k < 4; k++) {
					;
					ball[i][j].push_back({ (2 * k) + 1,{speed / many,sum / 5} });
					mp[i][j].push_back(num++);
				}
			}
		}
	}
}
void move() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j].size() < 1)continue;
			int cnt = 0;
			for (int k = 0; k < mp[i][j].size(); k++) {
				if (check[mp[i][j][k]])continue;
				check[mp[i][j][k]] = true;
				cnt++;
				int nnum = mp[i][j][k];
				int d = ball[i][j][k].first;
				int s = ball[i][j][k].second.first;
				int w = ball[i][j][k].second.second;
				int nx = i + (dx[d] * s) % n;
				int ny = j + (dy[d] * s) % n;
				if (nx < 1)nx = nx + n;
				if (nx > n)nx = nx - n;
				if (ny < 1)ny = ny + n;
				if (ny > n)ny = ny - n;
				ball[nx][ny].push_back({ d,{s,w} });
				mp[nx][ny].push_back(nnum);
			}
			while (cnt) {
				ball[i][j].pop_front();
				mp[i][j].pop_front();
				cnt--;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	num = 1;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		mp[a][b].push_back(num++);
		ball[a][b].push_back({ e,{d,c} });
	}
	for (int i = 0; i < k; i++) {
		memset(check, false, sizeof(check));
		move();
		decompose();
	}
	int sum = 0;
	for (int j = 1; j <= n; j++) for (int t = 1; t <= n; t++) if (ball[j][t].size() > 0)
		for (int tt = 0; tt < ball[j][t].size(); tt++)sum += ball[j][t][tt].second.second;
	cout << sum;
}