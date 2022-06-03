#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int v[1001];
int visit[1001];
int ans = 0;
void dfs(int num,int root) {
	visit[num] = root;
	if (visit[v[num]] != 0) {
		if (visit[v[num]] == root) {
			ans++;
			return;
		}
		else {
			return;
		}
	}
	else {
		dfs(v[num],root);
	}
}

int main() {
	int t;
	cin>>t;
	int n;
	int a;
	while (t--) {
		ans = 0;
		cin>>n;
		for (int i = 1; i <= n; i++) {
			cin>>v[i];
			visit[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (visit[i]==0) {
				dfs(i,i);
			}
		}

		printf("%d\n", ans);
	}

}