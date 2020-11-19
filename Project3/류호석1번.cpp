#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
vector<string>v;
bool check[11];
struct cmp {
	bool operator()(pair<string, int > a, pair<string, int > b) {
		return a.first.size() < b.first.size();
	}
};
priority_queue<pair<string, int>,vector<pair<string,int>>,cmp>pq;
void dfs1(int index,int cur_cnt, int num,string t) {
	if (num == 2) {
		vector<int>temp;
		for (int i = 0; i < 11; i++)if (check[i])temp.push_back(i);
		string s1 = t.substr(0, temp[0]);
		string s2 = t.substr(temp[0], temp[1] - temp[0]);
		string s3 = t.substr(temp[1], 10);
		int t = stoi(s1) + stoi(s2) + stoi(s3);
		string temp1 = to_string(t);
		int cnt = 0;
		for (int i = 0; i < temp1.size(); i++) {
			int p = temp1[i] - '0';
			if (p % 2 == 1)cnt++;
		}
		pq.push({ temp1,cnt+cur_cnt });
		return;
	}
	for (int i = index; i < t.size(); i++) {
		if (check[i])continue;
		check[i] = true;
		dfs1(i + 1,cur_cnt, num + 1,t);
		check[i] = false;
	}
}
int main() {
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int k = s[i] - '0';
		if (k % 2 == 1)ans++;
		}
	pq.push({ s,ans });
	while (!pq.empty()) {//3개->2개변환
		string t = pq.top().first;
		int cnt = pq.top().second;
		if (t.size() < 3)break;
		pq.pop();
		dfs1(1, cnt, 0, t);
	}
	while (!pq.empty()) {//2개->1개변환
		string t = pq.top().first;
		int cnt = pq.top().second;
		if (t.size() < 2)break;
		pq.pop();
		int k = t[0] - '0';
		int k1 = t[1] - '0';
		int temp = k + k1;
		string temp1 = to_string(temp);
		for (int i = 0; i < temp1.size(); i++) {
			int ss = temp1[i]-'0';
			if (ss % 2 == 1)cnt++;
		}
		pq.push({ temp1,cnt });
	}
	int MAX = 0;
	int MIN = 1e9;
	while (!pq.empty()) {
		string p = pq.top().first;
		int cnt = pq.top().second;
		pq.pop();
		MIN = min(cnt, MIN);
		MAX = max(cnt, MAX);
	}
	cout << MIN << " " << MAX;
}
