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
int map[101][101];
int main() {
	int n,m;
	cin>>n>>m;
	int a,b,c,d;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b>>c>>d;
		for (int h = a; h <= c; h++) {
			for (int g = b; g <= d; g++) {
				map[h][g]++;
			}
		}
	}
	int Cnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] > m) {
				Cnt++;
			}
		}
	}

	cout<<Cnt;

}