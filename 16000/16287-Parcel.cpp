#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 500002
using namespace std;
ll w;
ll n;
int s[800000];
vector<ll> v;
int main() {
	ll a;
	scanf("%lld %lld",&w,&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a);
		v.push_back(a);
	}
	bool Find = false;
	sort(v.begin(),v.end());
	for (int i = 2; i < n-1; i++) {
		for (int j = 0; j < i - 1; j++) {
			if (v[j] + v[i - 1] >= w) {
				break;
			}
			s[v[j]+v[i-1]] = 1;
		}

		for (int j = i + 1; j < n; j++) {
			if (v[j] + v[i] >= w) {
				break;
			}

			if (s[w - (v[j] + v[i])] == 1) {
				Find = true;
				break;
			}

		}

		if (Find) {
			break;
		}


	}

	if(Find){
	printf("YES");
	}else{
	printf("NO");
	}
}