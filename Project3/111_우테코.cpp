#include <string>
#include <vector>
using namespace std;
 int answer;
int solution(int money, vector<string> expected, vector<string> actual) {
    int cur = 100;
    for (int i = 0; i < expected.size(); i++) {
        string a = expected[i];
        string b = actual[i];
        if (cur > money)cur = money;
        if (a != b) {
            money -= cur;
            cur *= 2;
        }
        else {
            money += cur;
            cur = 100;
        }
    }
    answer = money;
        return answer;
}