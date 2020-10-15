#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 500001
using namespace std;
vector<int> answer;
vector< pair<int, int>>v;
int ans;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)return a.second > b.second;
	return a.first > b.first;
}
vector<int> solution(int N) {

	for (int i = 9; i > 0; i--) {
	int num = N;
	int k = 1;
	while (num) {
		
		int rest = num % i;
		num /= i;
		if (rest != 0)
			k *= rest;
		}
	v.push_back({ k,i });
	}

	sort(v.begin(), v.end(), cmp);
	answer.push_back(v[0].second);
	answer.push_back(v[0].first);
	return answer;
}
int main() {

}