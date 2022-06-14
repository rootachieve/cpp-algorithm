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
int arr[2][100002];
int arr2[2][100002];
int main() {
	cin>>n;
	int a;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[0][i];
		if (arr[0][i - 1] <= arr[0][i]) {
			arr[1][i] = arr[1][i-1]+1;
			Max = max(Max,arr[1][i]);
		}
		else {
			arr[1][i] = 1;
		}
	}

	for (int j = n; j >= 1; j--) {
		if (arr[0][j + 1] <= arr[0][j]) {
			arr[1][j] = arr[1][j+1] + 1;
			Max = max(Max, arr[1][j]);
		}
		else {
			arr[1][j] = 1;
		}
	}

	cout<<Max;
}