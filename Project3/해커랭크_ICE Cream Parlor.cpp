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
			v.push_back({ a,i });// 정렬하고 난후 index값이 바뀌기 때문에 index값을 저장하고 시작한다.
		}
		sort(v.begin(), v.end());// 이분탐색을 하기위해 정렬하기 
		for (int i = 0; i < v.size(); i++) {// 한점을 고정시키고  이분탐색으로 나머지점 탐색
			if (check)break;
			int st = i+1;
			int ed = m - 1;
			while (st <= ed) {// 이분탐색
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