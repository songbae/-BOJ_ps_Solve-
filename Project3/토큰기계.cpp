#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
pair<int,int>v[201][21];
int n, m, s, t;
int ans;
int node[201];
bool ok;
bool pp;
void dfs(int st,int token, int cnt, int end) {
	if (cnt == end) {
		ans = st;// 현재 몇번째인지가 end랑 같아지면 답출력
		return;
	}
	int x = v[st][token].first;//다음 기계 
	int y = v[st][token].second;//다음 토큰
	node[st]++;// 현재기계번호에 값을 하나 추가 
	int num = 0;
	int num1 = 0;
	if (!ok) {
		for (int i = 1; i <= n; i++) {
			if (node[i] % 2 == 0) {// 만약 현재까지 더한 기계값들이 모두 짝수이면 배열이 2번반복됐다는걸 의미하니 
				num1++;
				if (node[i] != 0)num++;
			}
			else break;
		}
	}
	if (num1 == n)ok = true;
	if (ok&&!pp) {
		pp = true;
		end = end % num;
		cnt = 0;
		if (end == 0)end = num;
	}
	dfs(x, y, cnt + 1, end);
	return;
}
int main() {
	cin >> n >> m >> s >> t; f;// 기계,토큰,시작,반복횟수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a, b; cin >> a >> b;
			v[i][j] = { b,a };//배열에 기계-토큰 ->(다음기계,토큰) 
		}
	}
	int start = s;//시작 기계
	int end = t;//몇번째인지
	dfs(start,1,1, end);
	cout << ans;
}