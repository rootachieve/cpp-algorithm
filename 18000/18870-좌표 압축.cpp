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
int base[1000001];
int ans[1000001];
int n;
map<int,int> m;
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&base[i]);
		ans[i] = base[i];
	}
	int Count = 0;
	sort(base,base+n);
	for (int i = 0; i < n; i++) {
		if (m.find(base[i]) == m.end()) {
			m.insert({base[i],Count++});
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ",m.find(ans[i])->second);
	}
	
}