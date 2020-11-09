#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int answer,cnt,target,nn;
pair<int, int>num[901];
bool check[900 + 1];
pair<int, int>cur;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector < vector<int>>v;
void bfs(pair<int, int>now, int T) {
    memset(check, false, sizeof(check));
    queue<pair<int, pair<int, int>>>q;
    q.push({ 0,now });
    while (!q.empty()) {
        int cost = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (num[T].first == x && num[T].second == y) {
            answer += cost+1;
            cur = { x,y };
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= nn)nx = 0;
            else if (nx < 0)nx = nn - 1;
            else if (ny >= nn)ny = 0;
            else if (ny < 0)ny = nn - 1;
            if (check[v[nx][ny]])continue;
            check[v[nx][ny]] = true;
            q.push({ cost + 1,{ nx,ny } });
        }

    }
}
int solution(int n, vector<vector<int>> board) {
    cur = { 0, 0 };
    nn = n;
    v = board;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            int a = board[i][j];
            num[a] = { i,j };
        }
    }
    for (int i = 0; i < n * n; i++) {
        target++;
        bfs(cur, target);
    }

    return answer;
}