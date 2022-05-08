#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int pi[100002];
int n;
void kmp(string a) {
	n = a.size();
	int i = -1;
	int j = 0;
	pi[j] = -1;
	while (j < n) {
		if (i == -1 || a[i] == a[j]) {
			pi[++j] = ++i;
		}
		else {
			i = pi[i];
		}
	}
}
int main() {
	string a,b;
	cin>>a;
	cin>>b;
	b+=b;
	kmp(a);
	
	int i = 0;
	int j = 0;
	int ans = 0;
	while (i < 2 * n - 1) {
		if (j == -1 || b[i] == a[j]) {
			i++;
			j++;
		}
		else {
			j = pi[j];
		}

		if (j == n) {
			ans++;
			j = pi[j];
		}
	}
	printf("%d",ans);
}