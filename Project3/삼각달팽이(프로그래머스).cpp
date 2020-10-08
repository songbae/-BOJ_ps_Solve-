#include <string>
#include <vector>
#include<iostream>
using namespace std;
int map[1001][1001];
int dx[3] = { 1,0,-1 };
int dy[3] = { 0,1,-1 };
    vector<int> answer; 
void bfs(int x, int y, int n) {
    int num = 0;
    int k = 0;
    while (n) {
        for (int i = 1; i <=n; i++) {
            map[x][y] = num++;
            x += dx[k];
            y += dy[k];
        }
        n--;
        k++;
        k%= 3;
        if (n == 0)map[x][y] = num;
    }
}
vector<int> solution(int n) {
    bfs(0,1,n);
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j <= 10; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) if (map[i][j] != 0)answer.push_back(map[i][j]);
    return answer;
}
int main() {
    int n;
    cin >> n;
    solution(n);
}