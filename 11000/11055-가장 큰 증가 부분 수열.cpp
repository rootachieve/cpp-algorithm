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
int n;
int base[1001];
int D[1001];
int main() {
	scanf("%d",&n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&base[i]);
		int Max = 0;
		for (int j = 1; j < i; j++) {
			if(base[j]<base[i]){
				Max = max(Max,D[j]);
			}
		}
		D[i] = Max + base[i];
		ans = max(ans,D[i]);
	}

	printf("%d",ans);

}