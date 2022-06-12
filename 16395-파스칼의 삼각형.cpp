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
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

ll table[32][32];

int main() {
	table[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			table[i][j] = table[i-1][j] + table[i-1][j-1];
		}
	}
	int n,m;
	cin>>n>>m;
	printf("%lld",table[n][m]);
}