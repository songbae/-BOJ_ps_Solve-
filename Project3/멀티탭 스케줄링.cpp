#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k;
vector<int>v;
bool check[101];
int check2[101];
bool ok;
map<int, int>tt;
int main() {
	f; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)check[v[i]] = true;//ÅÇ¿¡²ÈÇôÀÖ´Â ±â±âµé check
	int cnt = 0;
	for (int i = n; i < v.size(); i++) {
		int next = v[i];//
		ok = false; int num = 0;
		memset(check2, false, sizeof(check2));
		if (check[next])continue;//ÀÌ¹Ì ÅÇ¿¡ ²ÈÇôÀÖ´Ù¸é pass
		for (int j = i + 1; j < k; j++) {
			if (check[v[j]])check2[v[j]]++;
		}
		while (1) {
			for (int j = 0; j < v.size(); j++) {
				if (check[v[j]] && check2[v[j]] == num) {
					check[v[j]] = false;
					check[next] = true;
					cnt++;
					ok = true;
					break;
				}
			}
			if (ok)break;
			num++;
		}
	}
	cout << cnt;
}