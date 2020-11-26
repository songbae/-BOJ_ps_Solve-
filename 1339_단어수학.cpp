#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n,answer;
int arr[26][8];
int alpa[26];
vector<pair<int, int>>v;
vector<string>voca;
bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first > b.first;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t; cin >> t;
		for (int j = 0; j < t.size(); j++)arr[t[j] - 65][t.size() - j-1]++;
		voca.push_back(t);
	}
	for (int i = 0; i < 26; i++) {
	int sum = 0;
		for (int j = 7; j >= 0; j--) {
			sum += arr[i][j]*pow(10,j);
		}
		v.push_back({ sum,i });
	}
	sort(v.begin(), v.end(), cmp);
	int num = 9;
	for (auto T : v)alpa[T.second] = num--;
	for (int i = 0; i < voca.size(); i++) {
		string K = "";
		for (int j = 0; j < voca[i].size(); j++) {
			K +=to_string(alpa[voca[i][j]-65]);
		}
		answer += stoi(K);
	}
	cout << answer;

}