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
int map[1002][1002];
int ans[1002][1002];
int main() {
	int n;
	cin>>n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		for (int j = 1; j <= n; j++) {
			if (temp[j-1] != '.') {
				map[i][j] = temp[j-1] - 48;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) {
				int sum = map[i][j-1]+map[i][j+1] + map[i-1][j] + map[i-1][j+1] + map[i-1][j-1] + map[i+1][j] + map[i+1][j-1] + map[i+1][j+1];
				if (sum >= 10) {
					ans[i][j]=-2;
				}
				else {
					ans[i][j] = sum;
				}
			}
			else {
				ans[i][j]=-1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == -1) {
				cout<<"*";
			}
			else if (ans[i][j] == -2) {
				cout<<'M';
			}
			else {
				cout<<ans[i][j];
			}
		}

		cout<<"\n";
	}


}