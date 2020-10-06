#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX 100001
using namespace std;
int n;
int nodedepth[MAX];
int answer;
bool checknode[100001];
vector < vector<pair<int, int>>>node;
queue<pair<int, int>>q;
vector<int>leafnode;
void dfs() {
	for (int i = 0; i < leafnode.size(); i++) {
		memset(checknode, false, sizeof(checknode));
		q.push({ leafnode[i],0 });
		checknode[leafnode[i]] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int value = q.front().second;
			answer= max(answer, value);	
			q.pop();
			for (int j = 0; j < node[x].size(); j++) {
				int nx = node[x][j].first;
				int ncost = node[x][j].second;
				if (!checknode[nx]) {
					checknode[nx] = true;
					q.push({ nx,ncost + value });
				}
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cin >> n;
	node.resize(n+1);
	int start, end, value;
	int leaf = 0;
	for (int i = 1; i <=n; i++) {
		cin >> start;
		while (1) {
			cin >> end;
			if (end == -1)break;
			cin >> value;
			node[start].push_back({ end,value });
			nodedepth[start]++;
			nodedepth[end]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (nodedepth[i]==2) {
			leafnode.push_back(i);
		}
	}
	dfs();
	cout << answer;
}
