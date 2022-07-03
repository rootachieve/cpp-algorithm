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
int arr[2][10];
int main() {

	for (int i = 1; i <= 9; i++) {
		cin >> arr[0][i];
	}

	for (int j = 1; j <= 9; j++) {
		cin >> arr[1][j];
	}
	int sum1 = 0;
	int sum2 = 0;
	bool Find = false;
	for (int i = 1; i <= 9; i++) {
		sum1+=arr[0][i];
		if (sum1 > sum2) {
			Find = true;
		}
		sum2+=arr[1][i];
	}

	if (Find) {
		cout<<"Yes";
	}
	else {

		cout << "No";
	}

}