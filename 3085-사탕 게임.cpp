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
int n;
int base[2][4] = {{0,0,-1,1},{-1,1,0,0}};
char map[52][52];
int check(int y, int x, int dir) {
	if (dir == 1) {
		int cnt = 1;
		for (int i = y + 1; i < n && map[i][x] == map[y][x]; i++) {
			cnt++;
		}

		for (int i = y - 1; i >= 0 && map[i][x] == map[y][x]; i--) {
			cnt++;
		}

		return cnt;
	}
	else {
		int cnt = 1;
		for (int i = x + 1; i < n && map[y][i] == map[y][x]; i++) {
			cnt++;
		}

		for (int i = x - 1; i >= 0 && map[y][i] == map[y][x]; i--) {
			cnt++;
		}

		return cnt;
	}
}
int main() {
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>map[i];
	}

	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Max = max(Max,check(i,j,1));

			Max = max(Max, check(i, j, 2));
			
			char temp = map[i][j];
			for(int k = 0;k<4;k++){
				if(i+base[0][k]>=0&&i+base[0][k]<n&& j + base[1][k] >= 0 && j + base[1][k] < n){
					temp = map[i][j];
					map[i][j] = map[i+base[0][k]][j+base[1][k]];
					map[i + base[0][k]][j + base[1][k]] = temp;

					Max = max(Max, check(i, j, 1));
					Max = max(Max, check(i, j, 2));

					temp = map[i][j];
					map[i][j] = map[i + base[0][k]][j + base[1][k]];
					map[i + base[0][k]][j + base[1][k]] = temp;

				}
			}
		}
	}

	cout<<Max;
}