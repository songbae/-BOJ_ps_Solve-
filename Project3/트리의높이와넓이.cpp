#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

map<int, pair<int, int>>tree;
int depth[10001];
int parent[10001];
vector<pair<int,int>>v;
vector<pair<int, int>>ans;//����,����
int maxd;
int start[10001];

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)return a.second < b.second;
	return a.first > b.first;
}
void inorder(int num) {//������ȸ�� ��ǥ,�� ���� ���� 
	if (num == -1)return;
	inorder(tree[num].first);
	v.push_back({v.size() + 1,depth[num]});//1~19���� ��ǥ�� ���� ������
	inorder(tree[num].second);
	return;
}
void deep(int num, int left, int right) {//��͵��鼭 ������� ���̱��ϱ�
	maxd = max(maxd, num);
	if (left == -1 && right == -1)return;
	depth[left] = num + 1;
	depth[right] = num + 1;
	if (left != -1)deep(num + 1, tree[left].first, tree[left].second);
	if (right != -1)deep((num + 1), tree[right].first, tree[right].second);
	return;
}
int main() {
	int n; cin >> n; f;
	for (int i = 0; i < n; i++) {
		int num, left, right; cin >> num >> left >> right;
		tree.insert({ num,{left,right} });//������ ����
		if (left != -1)start[left]++;
		if (right != -1)start[right]++;
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (start[i] == 0)root = i;
	}
	depth[root] = 1;
	deep(1, tree[root].first, tree[root].second);
	inorder(root);
	for (int i = 2; i <= maxd; i++) {// ���� 2~���ϱ��� ���鼭 
		int small = 10001; int big = 0;
		for (int j = 0; j < n; j++) {
			if (v[j].second == i) {// ���� �������߿��� ����ū�Ŷ� ������ ����
				small = min(small, v[j].first);
				big = max(big, v[j].first);
			}
		}
		if (small == big)continue;
		ans.push_back({ big - small + 1,i });
	}
	sort(ans.begin(), ans.end(),cmp);// �������� , ����ū �ʺ� ������ ����
	if (ans.size() == 0) {
		cout << root << " 1";
		return 0;
	}
	cout << ans[0].second << " " << ans[0].first;//���
}