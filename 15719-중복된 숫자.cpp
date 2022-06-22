#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
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
	int n;
	cin>>n;
	int a;
	ll sum = 0,sum2 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		sum2+=a;
		sum+=i;
	}
	sum-=n;
	cout<<sum2-sum;
}