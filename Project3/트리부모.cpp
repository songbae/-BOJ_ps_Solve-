#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100
using namespace std;
int edge[100];
int n;
bool check[100];
vector<int> answer;
vector<vector<int>>v;
vector<int>ans;
void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (edge[next] == 2)answer.push_back({ x,next });
		dfs(next);
	}

}
vector<int>solution(int n, vector<vector<int>> edges) {
	int siz = edges.size();
	for (int i = 0; i < siz; i++) {
		int st = edges[i][0];
		int end = edges[i][1];
		v[st].push_back(end);
		v[end].push_back(st);
		edge[st]++; edge[st]++;
	}
	for (int i = 0; i < n; i++) {
		if (edge[i] == 3)ans.push_back(i);
	}
	dfs();
	return answer;
}

int main() {

}