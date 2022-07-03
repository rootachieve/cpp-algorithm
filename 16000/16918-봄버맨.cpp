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
int map[202][202];
vector<pair<pair<int,int>,int>>v;
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin>>temp;
		for (int j = 1; j <= m; j++) {
			temp[j-1] == 'O' ? map[i][j] = 0 : map[i][j] = -1;
		}
	}
	for (int t = 2; t <= k; t++) {
		if (t % 2 == 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] == -1) {
						map[i][j] = t;
					}
				}
			}
			
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] == t-3) {
						map[i][j] = -1;
						if(map[i-1][j] != t-3) map[i - 1][j] = -1;
						if (map[i + 1][j] != t - 3) map[i +1][j] = -1;
						if (map[i][j+1] != t - 3) map[i][j+1] = -1;
						if (map[i][j-1] != t - 3) map[i][j-1] = -1;
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == -1) {
				cout<<'.';
			}
			else {
				cout<<'O';
			}
		}
		cout<<"\n";
	}
}