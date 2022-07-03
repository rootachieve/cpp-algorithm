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

int arr[50001];

int main() {

	int n;
	cin >> n;
	for (int i = 1; i*i <= n; i++) {
		arr[i*i] = 1;
		for (int j = 1; i*i + j <= n; j++) {
			if (arr[j] != 0) {
				arr[j+i*i] == 0 ? arr[j+i*i] = arr[j]+1 : arr[j+i*i] = min(arr[j+i*i],arr[j]+1);
			}
		}
	}
	printf("%d",arr[n]);
}