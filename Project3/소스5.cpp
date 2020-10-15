#include<bits/stdc++.h>
#include<regex>
#define INF 999999999
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, int>mp;
string city, Tcity;
string ncost[3] = { "Mugunghwa","ITX-Saemaeul","ITX-Cheongchun" };
string hcost[2] = { "S-Train","V-Train" };
double dist[101][101];
double ndist[101][101];
vector<int>arrive;
queue<int>q;
deque<pair<int, int>>dq;
int main() {
	f;
	dq.pop
	int n, m, k, l;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string c; cin >> c; mp[c] = i;
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		string c; cin >> c; arrive.push_back(mp[c]);
	}
	for (int i = 0; i <= 100; i++) {
		fill(dist[i], dist[i] + 101, INF);
		fill(ndist[i], ndist[i] + 101, INF);
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		string a, b, c; double cost; cin >> a >> b >> c >> cost;
		dist[mp[b]][mp[c]] = min(dist[mp[b]][mp[c]], cost);
		dist[mp[c]][mp[b]] = min(dist[mp[c]][mp[b]], cost);
		for (auto t : ncost) if (t == a)cost = 0;
		for (auto t : hcost)if (t == a)cost = cost / 2;
		ndist[mp[b]][mp[c]] = min(ndist[mp[b]][mp[c]], cost);
		ndist[mp[c]][mp[b]] = min(ndist[mp[c]][mp[b]], cost);
	}

	for (int i = 1; i <= n; i++) {//지나는점
		for (int j = 1; j <= n; j++) {//시작점
			for (int k = 1; k <= n; k++) {//도착점
				if (dist[j][k] > dist[j][i] + dist[i][k])dist[j][k] = dist[j][i] + dist[i][k];
				if (ndist[j][k] > ndist[j][i] + ndist[i][k])ndist[j][k] = ndist[j][i] + ndist[i][k];
			}
		}
	}
	long long yes = 0;
	long long no = 0;
	for (int i = 0; i < k - 1; i++) {
		int start = arrive[i];
		int end = arrive[i + 1];
		yes += dist[start][end];
		no += ndist[start][end];
	}
	no += m;
	if (yes <= no)cout << "No";
	else cout << "Yes";
}