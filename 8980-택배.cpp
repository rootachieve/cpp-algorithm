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
int n,k;
int m;
int cap[10002];
struct info {
	int s,e,w;
	info(int a,int b,int c){
		s = a;
		e = b;
		w = c;
	}
};
vector<info> v;
bool compare(info a, info b) {
	if (a.e == b.e) {
		return a.s<b.s;
	}else {
		return a.e<b.e;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	scanf("%d",&m);
	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		v.push_back(info(a,b,c));
	}

	int answer = 0;
	sort(v.begin(),v.end(),compare);
	for (int i = 0; i < v.size(); i++) {
		int Min =k;
		for (int j = v[i].s; j < v[i].e; j++) {
			Min = min(k-cap[j],Min);
		}
		Min = min(Min,v[i].w);
		if (Min > 0) {
			for (int j = v[i].s; j < v[i].e; j++) {
				cap[j]+=Min;
			}
			answer+=Min;
		}
	}

	printf("%d",answer);
}
