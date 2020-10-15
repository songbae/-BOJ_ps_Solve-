#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int>p;
stack<int>st;
vector<vector<int>>v;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    v.resize(board.size());

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0)continue;
            v[i].push_back(board[i][j]);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (auto t : v[i]) {
            cout << t << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < moves.size(); i++) {
        int x = moves[i] - 1;
        if (v[x].empty())continue;
        p.push_back(v[x].back());
        v[x].pop_back();
    }
    for (auto t : p)cout << t << " ";
    for (int i = 0; i < p.size(); i++) {
        if (st.empty())st.push(p[i]);
        else if (st.top() == p[i]) {
            st.pop();
            answer += 2;
        }
        else st.push(p[i]);
    }
    return answer;
}

int main() {
    vector<vector<int>>t = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1 },{4,2,4,4,2},{3,5,1,3,1} };
    vector<int>tt = { 1,5,3,5,1,2,1,4 };
    cout << solution(t, tt);
}