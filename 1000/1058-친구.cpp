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

int map[51][51];

int main() {
	string in;
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>in;
		for (int j = 1; j <= n; j++) {
			if (in[j - 1] == 'Y') {
				map[i][j] = 1;
			}

			if (i != j&&map[i][j]!=1) {
				map[i][j] = 100;
			}
		}
	}


	for (int m = 1; m <= n; m++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j],map[i][m] + map[m][j]);
			}
		}
	}

	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int Cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && map[i][j] <= 2) {
				Cnt++;
			}
		}
		Max = max(Max, Cnt);
	}

	cout<<Max;
}