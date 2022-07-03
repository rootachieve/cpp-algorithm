#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
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

pair<int,int> arr[26];
bool map[6][6];
bool LC,RC;
int Cnt;

bool LCCheck() {
	if (map[1][5] && map[2][4] && map[3][3] && map[4][2] && map[5][1]) {
		LC = true;
		return true;
	}
	return false;
}

bool RCCheck() {
	if (map[5][5] && map[4][4] && map[3][3] && map[2][2] && map[1][1]) {
		RC = true;	
		return true;
	}
	return false;
}

bool UDCheck(int y) {
	if (map[y][5] && map[y][4] && map[y][3] && map[y][2] && map[y][1]) {
		return true;
	}
	return false;
}

bool LRCheck(int x) {
	if (map[1][x] && map[2][x] && map[3][x] && map[4][x] && map[5][x]) {
		return true;
	}
	return false;
}
int main() {
	int a;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin>>a;
			arr[a] = {i,j};
		}
	}

	for (int i = 1; i <= 25; i++) {
		cin>>a;
		map[arr[a].first][arr[a].second] = true;
		if (!RC&&RCCheck()) {
			Cnt++;
		}

		if (!LC && LCCheck()) {
			Cnt++;
		}

		if (UDCheck(arr[a].first)) {
			Cnt++;
		}

		if (LRCheck(arr[a].second)) {
			Cnt++;
		}

		if (Cnt >= 3) {
			printf("%d",i);
			break;
		}
	}
}