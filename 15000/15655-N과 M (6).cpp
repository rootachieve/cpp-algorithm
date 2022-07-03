#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
int ch[10];
int n,m;
int base[10];
void back (int now, int loc) {
	if (now == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ",ch[i]);
		}
		printf("\n");
	}
	else {
		for (int i = loc + 1; i <= n; i++) {
			ch[now] = base[i];
			back(now+1,i);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%d",&base[i]);
	}

	sort(base,base+n+1);
	back(0,0);
}