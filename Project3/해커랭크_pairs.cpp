#include<bits/stdc++.h>
using namespace std;
int n, target,ans;
vector<int>v;
int main() {
	cin >> n >> target;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) { //���̺귯�� �ȿ����� Ž���� �ϰ� �� �ð��� �ɸ��µ� log n ���� Ž�����ؼ� �����ΰ����ٴ� ������.
		int x = lower_bound(v.begin() + i + 1, v.end(), v[i] + target) - v.begin();// �ο�ٿ��� �ε����� ã�´� 
		if(x!=n&&v[x]-v[i]==target)ans++;// �ε����� ������� n�� v.end()�� ��ȯ�ϱ⶧���� n�ΰ�츦 �����ϰ� Ž��
	}
	cout << ans;
}

/// �׽�Ʈ���غ�� 8������ -> �̶����� 1~2���� ó�� �Ϸ羿->