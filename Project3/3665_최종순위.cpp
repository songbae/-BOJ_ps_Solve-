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
	for (int i = 0; i < v[st].size(); i++) {//����� ������ Ž��
		int nx = v[st][i];
		if (--depth[nx] == 0) {// ������ �ϳ��� ���ش�
			ans.push_back(nx);//0�̸� �信 �־��ش�
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
			order[i] = k;// ���⵵ ��ġ
			arr[k] = i;
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			if (arr[a] > arr[b]) {// ���⵵ ��ġ�� �ٲ��ٸ�
				v[a].push_back(b);
				depth[b]++;
			}
			else {
				v[b].push_back(a);
				depth[a]++;
			}
		}
		for (int i = 1; i <= m; i++){
			if (depth[order[i]] != 0)continue;// depth�� 0�̾ƴϸ� ��ŵ
			if (depth[order[i]] == 0&&v[order[i]].size()==0)ans.push_back(order[i]);//������ 0�̰� ����� ������������ �׳� �ִ´�
			else {
				ans.push_back(order[i]);//������ 0������ ����� ������ ������
				topology(order[i]);// �������� ����
			}
			
	}
		
		if (ans.size() != m)cout << "IMPOSSIBLE";
		else for (auto T : ans)cout << T << " ";
		cout << endl;
	}

}