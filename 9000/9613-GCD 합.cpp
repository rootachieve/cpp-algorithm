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
int t;
vector<int> v;
int n;
ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b,a%b);
}

int main() {
int a;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		v.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a);
			v.push_back(a);
		}
		ll sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for(int j = i + 1; j < n; j++) {
				sum+=gcd(v[i],v[j]);
			}
		}

		printf("%lld\n",sum);
	}
}