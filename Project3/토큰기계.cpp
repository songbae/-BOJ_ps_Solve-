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
		ans = st;// ���� ���°������ end�� �������� �����
		return;
	}
	int x = v[st][token].first;//���� ��� 
	int y = v[st][token].second;//���� ��ū
	node[st]++;// �������ȣ�� ���� �ϳ� �߰� 
	int num = 0;
	int num1 = 0;
	if (!ok) {
		for (int i = 1; i <= n; i++) {
			if (node[i] % 2 == 0) {// ���� ������� ���� ��谪���� ��� ¦���̸� �迭�� 2���ݺ��ƴٴ°� �ǹ��ϴ� 
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
	cin >> n >> m >> s >> t; f;// ���,��ū,����,�ݺ�Ƚ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a, b; cin >> a >> b;
			v[i][j] = { b,a };//�迭�� ���-��ū ->(�������,��ū) 
		}
	}
	int start = s;//���� ���
	int end = t;//���°����
	dfs(start,1,1, end);
	cout << ans;
}