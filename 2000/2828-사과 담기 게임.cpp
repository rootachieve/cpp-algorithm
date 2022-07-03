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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int l = 1;
int r;

int n,m,c;

int main() {
	int a;
	scanf("%d%d%d",&n,&m,&c);
	int ans = 0;
	r = m;
	for (int i = 1; i <= c; i++) {
		scanf("%d",&a);

		if (a < l) {
			int temp = l-a;
			ans+=temp;
			l-=temp;
			r-=temp;
		}
		else if (r < a) {
			int temp = a - r;
			ans += temp;
			l += temp;
			r += temp;
		}
	}
	cout<<ans;
}