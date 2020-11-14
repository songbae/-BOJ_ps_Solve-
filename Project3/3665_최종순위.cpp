#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, k;
int order[501];
vector < vector<int>>v;
int depth[501];
int arr[501];
bool check[501];
vector<int>ans;
bool quest;
void topology(int st) {
	for (int i = 0; i < v[st].size(); i++) {//연결된 엣지를 탐색
		int nx = v[st][i];
		if (--depth[nx] == 0) {// 뎁스를 하나씩 빼준다
			ans.push_back(nx);//0이면 답에 넣어준다
		}
	}
}
int main() {
	cin >> n;
	while (n--) {
		memset(order, false, sizeof(order));
		memset(depth, false, sizeof(depth));
		memset(arr, false, sizeof(arr));
		ans.clear();
		v.clear();
		quest = false;
		cin >> m;
		v.resize(m + 1);
		for (int i = 1; i <= m; i++) {
			cin >> k;
			order[i] = k;// 전년도 위치
			arr[k] = i;
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			if (arr[a] > arr[b]) {// 전년도 위치가 바꼇다면
				v[a].push_back(b);
				depth[b]++;
			}
			else {
				v[b].push_back(a);
				depth[a]++;
			}
		}
		for (int i = 1; i <= m; i++){
			if (depth[order[i]] != 0)continue;// depth가 0이아니면 스킵
			if (depth[order[i]] == 0&&v[order[i]].size()==0)ans.push_back(order[i]);//뎁스도 0이고 연결된 엣지가없으면 그냥 넣는다
			else {
				ans.push_back(order[i]);//뎁스는 0이지만 연결된 에지가 있을때
				topology(order[i]);// 위상정렬 수행
			}
			
	}
		
		if (ans.size() != m)cout << "IMPOSSIBLE";
		else for (auto T : ans)cout << T << " ";
		cout << endl;
	}

}