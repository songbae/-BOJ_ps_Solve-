#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, n, k;
int pre[1001], in[1001], idex[1001];
void search(int st,int ed,int st1,int ed1) {//��
	int root = pre[st];
	int mid = idex[root];// ������������ root��ġ
	if(mid!=st1)search(st+1,st+(mid-st1),st1,mid-1);//���� 
	if(mid!=ed1)search(st+(mid-st1)+1,ed,mid+1,ed1);//������
	cout << root << " ";
	return;
}
int main() {
	cin >> n; f;
	for (int i = 0; i < n; i++) {
		cin >> n; 
		for (int j = 1; j <= n; j++) { cin >> pre[j]; }
		for (int j = 1; j <= n; j++) { cin >> in[j];  }
		for (int j = 1; j <= n; j++) { idex[in[j]] = j; }
		search(1,n,1,n);
		cout << "\n";
	}


}