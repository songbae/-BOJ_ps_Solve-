#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k;
int pre[100001], in[100001], idex[100001];
void search(int st, int ed, int st1, int ed1) {//��
	int root = pre[ed1];
	int mid = idex[root];// ������������ root��ġ
	cout << root << " ";
	if (mid != st)search(st, mid-1, st1, st1+mid-st-1);//���� 
	if (mid != ed)search(mid+1,ed , st1+mid-st , ed1-1);//������ �̺κ� Ȯ���� �ˤ�
}
int main() {
	cin >> n; f;
		for (int j = 1; j <= n; j++) { cin >> in[j]; }
		for (int j = 1; j <= n; j++) { cin >> pre[j]; }
		for (int j = 1; j <= n; j++) { idex[in[j]] = j; }
		search(1, n, 1, n);
		cout << "\n";
	}
