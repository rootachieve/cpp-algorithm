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
struct flow{
	int s;
	int e;
	flow(int a, int b) {
		s = a;
		e = b;
	}
};
vector<flow> v;
int n;
bool com(flow a, flow b) {
	if (a.s == b.s) {
		return a.e>b.e;
	}
	else {
		return a.s<b.s;
	}
}
int main(){
	scanf("%d",&n);
	int a,b,c,d;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		v.push_back(flow(a*100 + b,c*100+d));
	}

	sort(v.begin(),v.end(),com);
	
	int s = 101;
	int e = 301;
	int Count =0;
	int nowe =0;
	int type;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].s > e) {
			if(nowe>0){
				e = nowe;
				nowe = 0;
				Count++;
				if (e > 1130) {
					type = 2;
					break;
				}
			}
			else {
				type = 1;
				break;
			}
		}

		if (v[i].s <= e && nowe < v[i].e) {
			nowe = v[i].e;
		}
		
	}
	if (nowe != 0) {
		e = nowe;
		nowe = 0;
		Count++;
		if (e > 1130) {
			type = 2;
		}
	}

	if (type == 2) {
		printf("%d",Count);
	}else{
		printf("0");
	}
}