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
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int arr[101][101];
int arr2[101][101];
int arr3[101][101];
int n1,m1;
int n2,m2;

int main() {
	scanf("%d%d",&n1,&m1);
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= m1; j++) {
			scanf("%d",&arr[i][j]);
		}
	}

	scanf("%d%d",&n2,&m2);
	for (int i = 1; i <= n2; i++) {
		for (int j = 1; j <= m2; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= m2; j++) {
			for (int k = 1; k <= m1; k++) {
				arr3[i][j] += arr[i][k] * arr2[k][j];
			}

			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}

	printf("");
}