#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
string s;
string s1;
int ans;
deque<char>D;
deque<char>D1;
int main() {
	cin >> s >> s1;

	if (s.size() > s1.size())swap(s1, s);//s°¡ ÂªÀº¾Ö¾ß 
	D.assign(s1.begin(), s1.end());
	D1.assign(s.begin(), s.end());
	int size = s1.size() + s.size();
	for (int i = 0; i < s.size(); i++)D.push_front('0');
	for (int i = 0; i < s1.size(); i++)D1.push_back('1');
	for(int i=0; i<size; i++){
		int cnt = 0;
		for(int j=0; j<size; j++){
			if (D[j] != D1[j]) {
				cnt = 0;
				continue;
			}
			cnt++;
			ans = max(ans, cnt);

		}
		D1.pop_back();
		D1.push_front('1');
	}
	cout << ans;
}