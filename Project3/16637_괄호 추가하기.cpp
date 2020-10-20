#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, max_ans = INT_MIN;
string str;

int cal(int a, int b, char oper)
{
	int result = a;
	switch (oper)
	{
	case '+': result += b; break;
	case '*': result *= b; break;
	case '-': result -= b; break;
	}
	return result;
}

void recur(int idx, int cur)
{
	// 1. ���� ����
	if (idx > n - 1)
	{
		max_ans = max(max_ans, cur);
		return;
	}
	char oper = (idx == 0) ? '+' : str[idx - 1];

	// 2. ��ȣ�� ���´� = ���� + ��ȣ ���
	if (idx + 2 < n)
	{
		int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		recur(idx + 4, cal(cur, bracket, oper));
	}
	// 3. �� ���´� = ���� + ����
	recur(idx + 2, cal(cur, str[idx] - '0', oper));
}

int main()
{
	cin >> n >> str;
	recur(0, 0);
	cout << max_ans;
	return 0;
}