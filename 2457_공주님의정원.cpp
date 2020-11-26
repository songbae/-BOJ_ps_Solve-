#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n,ans;
priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		string s = "";
		string s1 = "";
		if (d == 1) {
			if (c==2||c == 4 || c == 6 || c == 8 || c == 9 || c == 11) {
				c--;
				d = 31;
			}
			else if (c == 5 || c == 7 || c == 10 || c == 12) {
				c--;
				d = 30;

			}
			else if (c == 3) {
				c--;
				d = 28;
			}
		}
		if (b < 10)s += to_string(a) + "0" + to_string(b);
		else s += to_string(a) + to_string(b);
		if(d<10)s1 += to_string(c) + "0" + to_string(d);
		else s1 += to_string(c)+ to_string(d);
		q.push({ stoi(s),stoi(s1) });
	}
	int cur = 0;
	int temp = 301;
		while (!q.empty()) {
			int st = q.top().first;
			int ed = q.top().second;
			if (temp >= 1130)break;
			if (st > temp)break;
			 if (cur < st&&temp<ed) {
				cur = temp;
				ans++;
			}
			q.pop();
			if (temp < ed)temp = ed;
	}
		if (temp<1130)cout << "0";
		else cout << ans;
}