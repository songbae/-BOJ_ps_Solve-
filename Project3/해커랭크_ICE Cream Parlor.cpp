#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, k;
vector<pair<int, int>>v;
bool check;

int main() {
	cin >> n;
	while (n--) {
		v.clear();
		check = false;
		int money; cin >> money;
		cin >> m;
		for (int i = 1; i <=m; i++) {
			int a; cin >> a;
			v.push_back({ a,i });// �����ϰ� ���� index���� �ٲ�� ������ index���� �����ϰ� �����Ѵ�.
		}
		sort(v.begin(), v.end());// �̺�Ž���� �ϱ����� �����ϱ� 
		for (int i = 0; i < v.size(); i++) {// ������ ������Ű��  �̺�Ž������ �������� Ž��
			if (check)break;
			int st = i+1;
			int ed = m - 1;
			while (st <= ed) {// �̺�Ž��
				int mid = (st + ed) / 2;
				if (v[i].first + v[mid].first < money)st = mid + 1;
				else if (v[i].first + v[mid].first > money)ed = mid-1;
				else if (v[i].first+ v[mid].first==money) {
					if (v[i].second > v[mid].second)swap(v[i].second,v[mid].second);
					cout << v[i].second << " " << v[mid].second << endl;
					check = true;
					break;
				}
			}
		}

	}
}