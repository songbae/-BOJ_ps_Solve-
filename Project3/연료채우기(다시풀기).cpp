#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10001
using namespace std;
vector<pair<int, int>>v;
int n, ans = MAX;
struct cmp1{
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
	};
priority_queue < pair<int, int>, vector<pair<int, int>>, cmp1>pq;
bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.first < b.first;
}
void dfs(int cur, int left, int idx,int target,int cnt) {
	if (target - cur - left <= 0) {
		ans = min(ans, cnt);
		return;
	}
	
	for (int i = idx; i < v.size(); i++) {
		if (left-v[i].first+cur>=0) {
			int big = left - v[i].first + cur + v[i].second;
			pq.push({ i,big });
		}
	}
	if (!pq.empty())return;
	int index = pq.top().first;
	int big = pq.top().second;
	pq.pop();
	dfs(v[index].first, big, index+1, target, cnt + 1);
	return;
}
int main() {
	cin >> n; f;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		sum += b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	int end, left;
	cin >> end >> left;
	if (sum + left < end) {
		cout << "-1";
		return 0;
	}
	dfs(0,left,0,end,0);//현재위치, 남은 연료, 몇번째인덱스인지,도달지점,몇번들렷는지
	if (ans == MAX)cout << "-1";
	else cout << ans;
}