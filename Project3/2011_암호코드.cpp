#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000 
using namespace std;
string s;
int dp[5001];// 몇개의 단어가 연속하는지 개수판단
vector<int>v;
bool check;
int main() {
	cin >> s;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= s.size(); i++) dp[i] = (dp[i - 1]%mod + dp[i - 2]%mod)%mod;
	if (s.size() == 0) {
		cout << "0";;
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0' && i == 0)check = true;
		if (i > 0 && s[i] == '0' && s[i - 1] > '2')check = true;
		if (i > 0 && s[i] == '0' && s[i - 1] == '0')check = true;
		if (check) {
			cout << "0";
			return 0;
		}
	}
	while (1) { 
      check = false;
		for (int i = 0; s.size()>=1&&i < s.size()-1; i++) {
			if (s[i + 1] == '0') {
				v.push_back(i);
				s.erase(s.begin(), s.begin() + i + 2);
				check = true;
				break;
			}
			if (stoi(s.substr(i, 2)) > 26) {
				v.push_back(i + 1);
				s.erase(s.begin(), s.begin()+i+1);
				check = true;
				break;
			}
		}
		if (!check) {
			v.push_back(s.size());
			break;
		}
	}
	long long sum = 1;
	for (auto T : v) {
		if (T == 0)continue;
		sum = ((sum%mod)*(dp[T]%mod))%mod;
	}
	cout << sum;

}