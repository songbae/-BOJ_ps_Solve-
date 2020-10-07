#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10001
using namespace std;
vector<pair<int, int>>v;
priority_queue<int>pq;
int n, ans;
bool check[10001];
bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.first < b.first;
}
bool ok;
void search(int end ,int left) {
	int cnt = 0;
	int idx = 0;
	while (left < end) {
			for (int i = 0; i < v.size(); i++) {
				if (check[i])continue;
				int gook = v[i].second;
				int start = v[i].first;
				if (start <= left) {
					pq.push(gook );
					check[i] = true;

				}
				else {
					break;
				}
			}
			if (pq.empty()) {
				if(left<end)ok = true;
				break;
			}
	cnt++;
	int x = pq.top();
	left += x;
	pq.pop();

	}
	ans = cnt;
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
	search(end, left);
	if(ok)cout << "-1";
	else cout << ans;
}