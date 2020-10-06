#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

int N, M, K;
int arr[1000 + 1][1000 + 1];
bool visit[11][1000 + 1][1000 + 1];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool possible(int wall) {
    if (wall <= K) {
        return true;
    }
    else return false;
}

int BFS() {
    queue<tuple<int, int, int>> que;
    //y,x,wallcount
    que.push({ 0,0,0 });
    visit[0][0][0] = true;
    int dist = 0;
    while (!que.empty()) {
        int size = que.size();
        dist++;
        while (size--) {
            int y = get<0>(que.front());
            int x = get<1>(que.front());
            int wallcount = get<2>(que.front());
            if (y == N - 1 && x == M - 1) {
                return dist;
            }
            que.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newx < M && newy >= 0 && newy < N) {
                    int  existwall = wallcount + arr[newy][newx];
                    if (possible(existwall) && visit[existwall][newy][newx] != true) {
                        que.push({ newy,newx,existwall });
                        visit[existwall][newy][newx] = true;
                    }
                }
                else continue;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    cout << BFS();
    return 0;
}