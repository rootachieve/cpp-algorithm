#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n;
char map[12][12];
int prefix[12];
bool Find = false;
void back(int loc) {
	if (loc == n + 1) {
		if(!Find){
			for(int i = 0;i<n;i++){
					printf("%d ",prefix[i+1]-prefix[i]);
			}
			Find = true;
		}
	}else {
		if (Find) {
			return;
		}
		if (map[loc][loc] == '0') {
			prefix[loc] = prefix[loc-1];
			bool err = false;
			for (int j = 1; j <= loc - 1; j++) {
				if (map[j][loc] == '+' && prefix[loc] - prefix[j - 1] <= 0) {
					err = true;
				}
				else if (map[j][loc] == '0' && prefix[loc] - prefix[j - 1] != 0) {
					err = true;
				}
				else if (map[j][loc] == '-' && prefix[loc] - prefix[j - 1] >= 0) {
					err = true;
				}
			}

			if (!err) {
				back(loc + 1);
			}
		}
		else if (map[loc][loc] == '+') {
			for (int i = 1; i <= 10; i++) {
				if (Find) {
					return;
				}
				prefix[loc] = prefix[loc-1]+i;
				bool err = false;
				for (int j = 1; j <= loc - 1; j++) {
					if (map[j][loc] == '+' && prefix[loc] - prefix[j - 1] <= 0) {
						err= true;
					}else if (map[j][loc] == '0' && prefix[loc] - prefix[j - 1] != 0) {
						err = true;
					}else if (map[j][loc] == '-' && prefix[loc] - prefix[j - 1] >= 0) {
						err = true;
					}
				}
				
				if (!err) {
					back(loc+1);
				}
			}
		}
		else {
			for (int i = -10; i < 0; i++) {
				if (Find) {
					return;
				}
				prefix[loc] = prefix[loc - 1] + i;
				bool err = false;
				for (int j = 1; j <= loc - 1; j++) {
					if (map[j][loc] == '+' && prefix[loc] - prefix[j - 1] <= 0) {
						err = true;
					}
					else if (map[j][loc] == '0' && prefix[loc] - prefix[j - 1] != 0) {
						err = true;
					}
					else if (map[j][loc] == '-' && prefix[loc] - prefix[j - 1] >= 0) {
						err = true;
					}
				}

				if (!err) {
					back(loc + 1);
				}
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	scanf("%c", &map[1][1]);
	for (int i = 1; i <= n; i++) {
	
		for (int j = i;j <= n; j++) {
			scanf("%c",&map[i][j]);
		}
	}

	printf("");
	back(1);
}