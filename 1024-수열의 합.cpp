#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
#define MAX 1000002;
using namespace std;

long long cal[2][102];

long long n,m;
int main() {
	scanf("%lld%lld",&n,&m);

	for (int i = 1; i <= 100; i++) {
		cal[0][i] = cal[0][i-1] + 1;
		cal[1][i] = cal[1][i-1] + (i - 1);
	}
	int Findnum = -1;
	int FindLeng = -1;
	for (int i = m; i <= 100; i++) {
		if ((n - cal[1][i]) % cal[0][i] == 0&& (n - cal[1][i]) / cal[0][i]>=0) {
			Findnum = (n - cal[1][i]) / cal[0][i];
			FindLeng = i;
			break;
		}
	}

	if (Findnum == -1) {
		printf("-1");
	}
	else {
		for(int i = 0;i<FindLeng;i++){
		printf("%d ",Findnum + i);
		}
	}
}