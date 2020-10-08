#include <string>
#include <vector>
#include <iostream>
using namespace std;
int rownum[301];
int b[301][301];
int sum;
int answer;
bool map[301][301];
void dfs(int cnt, int st, int ed, int x, int y, int target) {
    if (cnt == target) {
        bool check = false;
        int tt[301]; memset(tt, 0, sizeof(tt));
        for (int i = 0; i < x; i++) {
            int k = 0;
            for (int j = 0;j< y; j++) {
                if (b[i][j] == 1) {
                    k++;
            }
            if (k % 2 != 0) {
                check = true;
                break;
            }
            if (check)break;
        }
        if (!check) {
            answer++;
            return;
        }
        return;
    }
    for (int i = st; i < x; i++) {
        for (int j = ed; j < y; j++) {
            if (map[i][j])continue;
            map[i][j] = true;
            dfs(cnt + 1, i, j, x, y, target);
            map[i][j] = false;
        }
    }
    return;
}
int solution(vector<vector<int>> a) {
    int xsize = a.size();
    int ysize = a[0].size();
    for (int i = 0; i < ysize; i++) {
        for (int j = 0; j < xsize; j++) {
            if (a[j][i] == 1) {
                rownum[i]++;
                sum++;
            }
        }
    }
    dfs(0, 0, 0, xsize, ysize, sum);
    return answer;
}

int main() {
    vector < vector<int>>p = { {1, 0, 0, 1, 1}, { 0, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1 } };
    cout << solution(p);
}