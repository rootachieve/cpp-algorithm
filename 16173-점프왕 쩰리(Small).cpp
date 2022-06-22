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

int map[4][4];
int check[4][4];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j];
		}
	}

	check[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 1) {
				if (i + map[i][j] <= n) {
					check[i+map[i][j]][j] = 1;

				}

				if (j + map[i][j] <= n) {
					check[i][j+map[i][j]] = 1;
				}
			}
		}
	}

	if (check[n][n] == 1) {
		cout<<"HaruHaru";
	}
	else {
		cout<<"Hing";
	}
}