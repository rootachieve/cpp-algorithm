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
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int arr[21][1001];
int main() {
	int n;
	cin>>n;
	arr[1][1] = true;
	arr[1][5] = true;
	arr[1][10] = true;
	arr[1][50] = true;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (arr[i][j]) {
				arr[i+1][j+1] = true;
				arr[i + 1][j + 5] = true;
				arr[i + 1][j + 10] = true;
				arr[i + 1][j + 50] = true;
			}
		}
	}
	int Cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		if (arr[n][i]) {
			Cnt++;
		}
	}

	cout<<Cnt;
}