#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

char in[200002];
int SA[200002];
int g[200002];
int tg[200002];
int Rank[200002];
int LCP[200002];
int t,n;
bool cmp(int x, int y)
{
	if (g[x] == g[y])
		return g[x + t] < g[y + t];


	return g[x] < g[y];
}

void getSA(char* str) {
	t = 1;

	for (int i = 0; i < n; i++) {
		SA[i] = i;
		g[i] = str[i] - 97;
	}

	while (t <= n) {
		g[n] = -1;
		sort(SA,SA+n,cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < n; i++)
		{
			
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			else
				tg[SA[i]] = tg[SA[i - 1]];
		}


		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		t <<= 1;
	}
}
int main() {
	scanf("%d",&n);
	scanf("%s",&in);
	getSA(in);
	printf("");
	for (int i = 0; i < n; i++) {
		Rank[SA[i]] = i;
	}

	int len = 0;

	for (int i = 0; i < n; i++) {
		int k = Rank[i];
		if (k) {
			int j = SA[k - 1];

			while (in[j + len] == in[i + len]) {
				len++;
			}

			LCP[k] = len;

			if (len) {
				len--;
			}
		}
	}

	printf("%d",*max_element(LCP,LCP+n));
}