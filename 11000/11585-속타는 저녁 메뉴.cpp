#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int pi[1000002];
int num;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}

	return gcd(b,a%b);
}
void kmp(string a) {
	int n = a.size();
	int i = - 1;
	int j = 0;
	pi[j] = i;
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
	string temp;
	string base,Find;
	scanf("%d",&num);
	for (int i = 1; i <= num; i++) {
		cin>>temp;
		Find+=temp[0];
	}
	for (int i = 1; i <= num; i++) {
		cin >> temp;
		base += temp[0];
	}
	kmp(Find);
	base += base;
	int i = 0;
	int j = 0;
	int ans = 0;
	while (i < 2 * num - 1) {
		if (j == -1 || base[i] == Find[j]) {
			i++;
			j++;
		}
		else {
			j = pi[j];
		}

		if (j == num) {
			ans++;
			j = pi[j];
		}
	}
	printf("%d/%d",(ans/gcd(ans,num)),(num/gcd(ans,num)));
}