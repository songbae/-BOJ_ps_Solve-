#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[501];
bool ok[501];
int find(int x) {
	if (x == parent[x])return x;
	return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y)return false;
	if (x > y) {
		if (ok[x])ok[y]=true;
		parent[x] = y;
	}
	else {
		if (ok[y])ok[x] = true;
		parent[y] = x;
	}
	return true;
}

int main(){
	f;
	int num = 1;
	while (1) {
		int a, b; cin >> a >> b;//a는 노드 개수 b는 간선개수 
		if (a == 0)break;
	for (int i = 1; i <=a; i++)parent[i] = i;
	memset(ok, false, sizeof(ok));
		int cnt = 0;
		for (int i = 0; i < b; i++) {
			int n, m; cin >> n >> m;
			if (!Union(n, m))ok[find(n)] = true;
		
			}
			for (int i = 1; i <= a; i++) {
				if (parent[i] == i&&!ok[find(i)])cnt++;
			}
			if (cnt > 1)cout <<"Case "<<num<<": "<< "A forest of "<< cnt <<" trees."<<endl;
			else if(cnt==1) cout << "Case "<<num<<": "<<"There is one tree." << endl;
		else cout << "Case "<<num<<": "<<"No trees." << endl;
		num++;
	}

}