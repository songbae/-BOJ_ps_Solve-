#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> answer;
int N,cnt;
pair<int, int > cur;
int cur_d;
queue<pair<int, pair<int,int>>>q;
bool check;
vector<vector<int>>v;
int dx[4] = { 1,-1,0,1 };
int dy[4] = { -1,1,1,0 };
void bfs() {
    q.push({ cur_d,cur });
    check = true;
    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int d = q.front().first;
        q.pop();
        if (x == N - 1 && y == N - 1)break;
        if (d == 2)cur_d = 0;
        else if (d == 3)cur_d = 1;
        else if (y != N - 1 && x == 0 && d == 1)cur_d = 2;
        else if (x != N - 1 && y == 0 && d == 0)cur_d = 3;
        else if (y == N - 1 && x == 0 && d == 1)cur_d = 3;
        else if (x == N - 1 && y == 0 && d == 0)cur_d = 2;
        if (cur_d == 0 || cur_d == 1)cnt += 2;
        else cnt += 1;
        int nx = x + dx[cur_d];
        int ny = y + dy[cur_d];
        v[nx][ny] = cnt;
        q.push({ cur_d,{nx,ny} });
    }
     
}
vector<vector<int>> solution(int n, bool horizontal) {
    N = n;
    cnt = 1;
    v.resize(n+1);
    for (int i = 0; i < n; i++) {
        v[i].resize(n+1);
    }
    if (horizontal) {
        cur = { 0,1 };
        cur_d = 2;
    }
    else {
        cur = { 1,0 };
        cur_d = 3;
    }
  
    v[cur.first][cur.second] = cnt;
    bfs();
    answer = v;
    return answer;
}

int main() {
    int PP = 4;
    bool T = true;
    solution(PP, T);
    for (int i = 0; answer.size(); i++) {
        for (int j = 0; answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
      
}