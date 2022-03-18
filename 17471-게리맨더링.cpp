#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 100000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
vector<int> v[12];
int n;
int type[12];
int check[12];
int p[12];
int Count = 0;
int Min = 10000;
void dfs(int node,int ty) {
	check[node] = 1;
	Count++;
	for (int i = 0; i < v[node].size(); i++) {
		if (check[v[node][i]] == 0 && type[v[node][i]] == ty) {
			dfs(v[node][i],ty);
		}
	}
}

void back(int now) {
	if (now == n+1) {
		int Cr = 0;
		int Cb = 0;
		for (int i = 1; i <= n; i++) {
			check[i] = 0;
			if (type[i] == 1&&Cr==0) {
				Cr = i;
			}
			if(type[i]==2&&Cb==0) {
				Cb = i;
			}
		}

		if (Cr > 0 && Cb > 0) {
			Count = 0;
			dfs(Cr,1);
			dfs(Cb,2);

			if (Count == n) {
				int Pr = 0;
				int Pb = 0;
				for (int i = 1; i <= n; i++) {
					if (type[i] == 1) {
						Pr+=p[i];
					}
					else {
						Pb+=p[i];
					}
				}
				Min = min(Min,abs(Pr-Pb));
			}
		}
	}
	else {
		type[now]=1;
		back(now+1);
		type[now]=2;
		back(now+1);
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&p[i]);
	}
	int k = 0;
	int b;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&k);
		for (int j = 1; j <= k; j++) {
			scanf("%d",&b);
			v[i].push_back(b);
			v[b].push_back(i);
		}
	}
	back(1);
	if(Min<10000){
		printf("%d",Min);
	}
	else {
		printf("-1");
	}
}
