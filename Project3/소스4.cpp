#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 500001
using namespace std;
int answer = -1;
int curnum = -1;
vector<int> v;
map<int, int> tt;
int solution(int k, vector<int>score) {
	v = score;
	int size = v.size();
	int cnt = 1;
	for (int i = 0; i < v.size()-1; i++) {
		if (curnum == v[i] - v[i + 1]) {
			cnt++;
		}
		tt[1]++;
		tt.insert(1, 2);
		else {
			if (cnt >= k) {
				size -= cnt;
			}
			cnt = 1;
		}
		for (auto t : tt) {
			t.
		}
		curnum = v[i] - v[i + 1];
		
	}


	return answer;





	q.push(Ω√¿€);
	while(!q.empty()){
	int start = q.front;
	if(start==hub)cnt++
	q.pop()
		for (int i = 0; i < road.size(); i++) {
			if(start==road[i].front();q.push(road[i].back());
		}

	while (!q.empty()) {
		int start = q.front;
			if (start == hub)cnt++
				q.pop()
				for (int i = 0; i < road.size(); i++) {
					if (start == road[i].front(); q.push(road[i].back());
				}
}