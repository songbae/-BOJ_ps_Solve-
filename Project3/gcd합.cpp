#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> pro;
vector<int>con;
queue<int>q;
queue<int>q1;
int ans;
int day;

string solution(int n, vector<int>p, vector<int>c) {
	string answer = "";
	int sum = 0;
	for (auto t : p)pro.push_back(t);
	for (auto t : c)con.push_back(t);
	int cnt = 1;
	while (day < n&&cnt<4) {
		sum += pro[day] - con[day];
		if (sum >= 0) {
			ans += (con[day] * 100) / cnt;
			cnt = 1;
		}
		else {
			sum +=con[day];
			cnt++;
		}
		day++;
	}
	double answ = ans / day;
	double k = round(answ * 100) / 100;
	answer = to_string(k);
	return answer;
}