#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int l;
	cin>>l;
	int sum = 0;
	int a;
	for (int i = l; i >= 1; i--) {
		cin>>a;
		sum+=a*pow(n,i-1);
	}

	int now = 1;
	while (now*m <= sum) {
		now*=m;
	}

	while (now > 0) {
		printf("%d ",sum/now);
		sum-=(sum/now*now);
		now/=m;
	}
}