#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int n,m;
int in[40];
int Count;
int main() {
	scanf("%d%d",&n,&m);
	int temp = n;
	int p = 1;
	int k = 1;
	while (temp != 0) {
		if ((temp & p) == p) {
			in[k] = 1;
			temp-=p;
			Count++;
		}
		k++;
		p*=2;
	}
	int ans = 0;
	p = 1;
	for (int i = 1; i < k; i++) {
		if (Count <= m) {
			break;
		}
		if (in[i] == 1) {
			ans+=p;
			in[i] = 0;
			if (in[i + 1] == 1) {
				Count--;
			}
			in[i+1]++;
		}
		else if(in[i]==2) {
			in[i] = 0;
			if (in[i + 1] == 1) {
				Count--;
			}

			in[i + 1]++;
		}
		p*=2;
	}

	printf("%d",ans);
}