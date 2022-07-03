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
int arr[32][30002];
int n;
int k;

int main() {
	scanf("%d",&n);
	arr[0][15000] = 1;
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		for (int j = 1; j <= 30000; j++) {
			if (arr[i-1][j] == 1) {
				arr[i][j+a] = 1;
				arr[i][j-a] = 1;
				arr[i][j] = 1;
			}
		}
	}
	scanf("%d",&k);
	for (int i = 1; i <= k; i++) {
		scanf("%d",&a);
		if (arr[n][a + 15000] == 1) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
	}

}