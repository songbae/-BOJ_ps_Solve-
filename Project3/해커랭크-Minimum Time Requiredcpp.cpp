#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
int num;
long long target, cmp = 1e9;
vector<long long>v;
int main() {
	cin >> num >> target;
	v.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
		cmp = min(v[i], cmp);
	}
	long long st = 0;
	long long ed = cmp*target;// �ִ��ϼ��� ����°��� �������� 
	long long mid = 0;
	while (st <= ed) {// ���ǹ��� ���� �����ϰ� ¥�Ⱑ ���� 
		 mid = (st + ed) / 2;
		long long cnt = 0;
		for (int i = 0; i < v.size(); i++)cnt += mid / v[i];
		if (cnt >= target)ed = mid-1;
		else if (cnt < target)st = mid + 1;

	}//-> ���ǹ��� Ż��������   ������ 20-> mid 19~21 �̷��� 1��
	for (long long i = mid - 1; i <= mid + 1; i++) {
		long long cnt = 0;
		for (int j = 0; j < v.size(); j++)cnt += i / v[j];
		if (cnt >= target) {
			cout << i;
			return 0;
		}
	}

}