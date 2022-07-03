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
using namespace std;
int a,n,m;
int ch[10];
vector<int> v;
void back(int now,int loc) {
	if (now == m) {
		for(int i = 0;i<m;i++){
			printf("%d ",ch[i]);
		}
		printf("\n");
	}
	else {
		for (int i = loc; i < n; i++) {
			ch[now] = v[i];
			back(now+1,i);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		v.push_back(a);
	}

	sort(v.begin(),v.end());;
	back(0,0);
}