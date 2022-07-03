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


int map[20][20];
int BCnt[4][20][20];
int WCnt[4][20][20];
int main() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	bool Find = false;
	for (int j = 19; j >= 1; j--) {
		for (int i = 19; i >= 1; i--) {
			if (map[i][j] == 1) {
				BCnt[0][i][j] = BCnt[0][i - 1][j + 1] + 1;
				BCnt[1][i][j] = BCnt[1][i][j + 1] + 1;
				BCnt[2][i][j] = BCnt[2][i + 1][j + 1] + 1;
				BCnt[3][i][j] = BCnt[3][i + 1][j] + 1;

			}
			else if (map[i][j] == 2) {
				WCnt[0][i][j] = WCnt[0][i - 1][j + 1] + 1;
				WCnt[1][i][j] = WCnt[1][i][j + 1] + 1;
				WCnt[2][i][j] = WCnt[2][i + 1][j + 1] + 1;
				WCnt[3][i][j] = WCnt[3][i + 1][j] + 1;
			}
		}
	}
	
	for (int j = 1; j <= 19; j++) {
		for (int i = 1; i <= 19; i++) {
			if (map[i][j] == 1) {
				BCnt[0][i][j] == 6 ? BCnt[0][i - 1][j + 1] = 0 : NULL;
				BCnt[1][i][j] == 6 ? BCnt[1][i][j + 1] = 0 : NULL;
				BCnt[2][i][j] == 6 ? BCnt[2][i + 1][j + 1] = 0 : NULL;
				BCnt[3][i][j] == 6 ? BCnt[3][i + 1][j] = 0 : NULL;
				for (int k = 0; k < 4; k++) {
					if (BCnt[k][i][j] == 5) {
						Find = true;
						printf("1\n");
						printf("%d %d", i, j);
						break;
					}
				}
			}
			else if (map[i][j] == 2) {
				WCnt[0][i][j] == 6 ? WCnt[0][i - 1][j + 1] = 0 : NULL;
				WCnt[1][i][j] == 6 ? WCnt[1][i][j + 1] = 0 : NULL;
				WCnt[2][i][j] == 6 ? WCnt[2][i + 1][j + 1] = 0 : NULL;
				WCnt[3][i][j] == 6 ? WCnt[3][i + 1][j] = 0 : NULL;
				for (int k = 0; k < 4; k++) {
					if (WCnt[k][i][j] == 5) {
						Find = true;
						printf("2\n");
						printf("%d %d", i, j);
						break;
					}
				}
			}
			if (Find) {
				break;
			}
		}
		if (Find) {
			break;
		}
	}
	if (!Find) {
		printf("0");
	}
}