#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
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

int map[752][752];
int check[2][752][752];

int main() {
	int n,m;
	cin>>n>>m;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		string in;
		cin>>in;
		for (int j = 1; j <= m; j++) {
			if (in[j - 1] == '1') {
				map[i][j] = 1;
				check[0][i][j] = check[0][i-1][j-1] + 1;
				check[1][i][j] = check[1][i-1][j+1] + 1;
				Max = 1;
			}
		}
	}

	if (Max == 0) {
		cout<<0;
	}
	else {
		int lim = min(n, m);
		bool Find;
		for (int k = 1; k <= lim; k++) {
			Find = false;
			for (int i = 1 + k; i <= n - k; i++) {
				for (int j = 1 + k; j <= m - k; j++) {
					if (check[1][i][j - k] > k && check[0][i][j + k] > k && check[1][i + k][j] > k && check[0][i + k][j] > k) {
						Max= k + 1;
						Find = true;
						break;
					}
				}
				if (Find) {
					break;
				}
			}
		}

		cout << Max;
	}

	
}