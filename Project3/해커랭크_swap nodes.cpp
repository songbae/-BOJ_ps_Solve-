#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, a, b,test;
vector < pair<int, int>>v;

void inorder(int cur,int d, int cnt) {
	if (cnt % d==0)swap(v[cur].first, v[cur].second);// k�� ����϶� �ڽĵ齺��
	if (v[cur].first != -1)inorder(v[cur].first, d, cnt + 1);
	cout << cur << " ";
	if (v[cur].second != -1)inorder(v[cur].second, d, cnt + 1);
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		v[i].first = a;// pair �� �����ϱ� �迭�ȿ� first.second  2���� ���� �ϳ��� �迭�� ���� ���־�� 
		v[i].second = b;
	}
	cin >> test;
	while (test--) {
		cin >> a;
		inorder(1,a,1);// ���� ���/ ��ǥ �ٲ����� / ������� 
		cout << endl;
	}

}