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

int n;
int arr[11];

int main() {
	cin>>n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		int Cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (Cnt == a && arr[j] == 0) {
				arr[j] = i;
				break;
			}
			if (arr[j] == 0) {
				Cnt++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ",arr[i]);
	}
}