#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 500001
using namespace std;
int n;
vector<vector<int>>v;
vector<int>node;
int leaf[MAX];
bool check[MAX];
int leafdepth[MAX];
void depth(int num, int cnt) {
	for (int i = 0; i < v[num].size(); i++) {
		int next = v[num][i];
		if (!check[next]) {
			check[next] = true;
			depth(next, cnt + 1);
		}
	}
	leafdepth[num] = cnt;
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		leaf[a]++; leaf[b]++;
	}
	check[1] = true;
	depth(1,0);
	for (int i = 2; i <= n; i++) {
		if (leaf[i] == 1)node.push_back(i);
	}
	int sum = 0;
	for (int i = 0; i < node.size(); i++) {
		sum += leafdepth[node[i]];
	}
	if (sum % 2 == 0) {
		cout << "No"; return 0;
	}
	else cout << "Yes";

}