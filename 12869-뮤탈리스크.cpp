#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

typedef struct info {
	int a;
	int b;
	int c;
};
int dp[62][62][62];
int n;
int temp[3];
queue<info> q;
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&temp[i]);
	}

	dp[temp[0]][temp[1]][temp[2]] = 1;
	info in = {temp[0],temp[1],temp[2]};
	q.push(in);

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		int A,B,C;
		A = max(now.a - 9, 0);
		B = max(now.b - 3, 0);
		C = max(now.c - 1, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = {A,B,C};
			q.push(temp2);
		}

		A = max(now.a - 9, 0);
		B = max(now.b - 1, 0);
		C = max(now.c - 3, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = { A,B,C };
			q.push(temp2);
		}

		A = max(now.a - 3, 0);
		B = max(now.b - 9, 0);
		C = max(now.c - 1, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = { A,B,C };
			q.push(temp2);
		}

		A = max(now.a - 1, 0);
		B = max(now.b - 9, 0);
		C = max(now.c - 3, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = { A,B,C };
			q.push(temp2);
		}

		A = max(now.a - 1, 0);
		B = max(now.b - 3, 0);
		C = max(now.c - 9, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = { A,B,C };
			q.push(temp2);
		}

		A = max(now.a - 3, 0);
		B = max(now.b - 1, 0);
		C = max(now.c - 9, 0);
		if (dp[A][B][C] == 0 || dp[A][B][C] > dp[now.a][now.b][now.c] + 1) {
			dp[A][B][C] = dp[now.a][now.b][now.c] + 1;
			info temp2 = { A,B,C };
			q.push(temp2);
		}
	}
	printf("%d",dp[0][0][0]-1);
}