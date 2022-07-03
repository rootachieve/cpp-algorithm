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
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
int map[21][21];
int n;
bool base[21];
int Min = 100000000;
void back(int num) {
	if (num == n + 1) {
		int sum1 =0;
		int sum2 = 0;


		for (int i = 1; i < n; i++) {
			if (base[i]) {
				for (int j = i + 1; j <= n; j++) {
					if(base[j]){
						sum1 += map[i][j];
						sum1 += map[j][i];
					}
				}
			}
			else {
				for (int j = i + 1; j <= n; j++) {
					if (!base[j]) {
						sum2 += map[i][j];
						sum2 += map[j][i];
					}
				}
			}
			
		}

		Min = min(Min,abs(sum1-sum2));
	}
	else {
		back(num + 1);
		base[num] = true;
		back(num + 1);
		base[num] = false;
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j];
		}
	}

	back(1);

	printf("%d",Min);
}