#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

vector<int> v[20001];
int visit[20001];
int Count[2][20001];
int n,m;
queue<int> q;
int main() {
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push(1);
	visit[1] = 1;
	Count[1][1] = 1;
	Count[0][1] = 1;

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < v[f].size(); i++) {
			if (visit[v[f][i]] == 0) {
				visit[v[f][i]] = visit[f]+1;
				Count[0][visit[f]+1]++;
				Count[1][visit[f]+1] == 0 ? Count[1][visit[f] + 1] = v[f][i] : Count[1][visit[f] + 1] = min(Count[1][visit[f] + 1],v[f][i]);
				q.push(v[f][i]);
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		if (Count[0][i] > 0) {
			printf("%d %d %d",Count[1][i],i-1,Count[0][i]);
			break;
		}
	}

}