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

int arr[10001];
bool check[10001];
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
		check[arr[i]] = true;
	}
	bool Find = false;
	int loc;
	for (int j = n; j > 1; j--) {
		if (arr[j] > arr[j - 1]) {
			Find = true;
			loc = j-1;

			check[arr[j]] = false;
			break;
		}
		else {
			check[arr[j]] = false;
		}
	}

	if (Find) {
		int target = arr[loc];
		target++;
		check[arr[loc]] = false;
		for (int i = 1; i < loc; i++) {
			printf("%d ",arr[i]);
		}
		for (int i = target; i <= n; i++) {
			if (!check[i]) {
				printf("%d ",i);
				check[i] = true;
				break;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				printf("%d ",i );
			}
		}
	}
	else {
		printf("-1");
	}
}