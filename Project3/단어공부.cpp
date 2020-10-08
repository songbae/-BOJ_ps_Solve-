#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int>>v;
vector<int>ans;
bool check[250001];
int n;
void dfs(int node,int cnt) {
    check[node] = true;
    for (int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        dfs(next, cnt + 1);
    }
    ans.push_back(cnt);
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    v.resize(n+1);
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i].front();
        int y = edges[i].back();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= edges.size(); i++) {
        memset(check, false, sizeof(check));
        dfs(i,0);
        sort(ans.begin(), ans.end(),greater<int>());
        int big = (ans[0] + ans[1]) * 2;
        answer = max(big, answer);
        ans.clear();
    }
    return answer;
}
int main() {

}