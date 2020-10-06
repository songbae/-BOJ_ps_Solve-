#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 4000
using namespace std;
vector<pair<int, int>>ans;
int k, cnt;
vector<int>v;
int tree[MAX];
bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first > b.first;
}
void dfs(int num, int depth){
if (num > cnt)return;
dfs(2 * num, depth + 1);
for (int i = 0; i < v.size(); i++) {
	int next = v[i];

}
}
int main() {
	cin >> k;
	int n;
	do {
		cin >> n;
		v.push_back(n);
		cnt++;
	} while (getc(stdin) == ' ');
	dfs(1, 0);
	sort(ans.begin(), ans.end(), cmp);
	int p=k;
	for (auto t : ans) {// 깊이와 왼쪽->오른쪽 순으로 저장 되어있다
		if (t.first != p) {
			cout << endl;//깊이가 다르면 
			p--;
			cout << t.second << " ";
		}
		else cout << t.second << " ";
	}
}