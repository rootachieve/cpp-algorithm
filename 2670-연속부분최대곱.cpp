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
double arr[10001];
int main() {
	int n;
	cin>>n;
	double a;
	double now = 1;
	double Max = -1;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}
	Max = arr[1];
	for(int i = 2;i<n;i++){
		if (arr[i - 1] * arr[i] > arr[i]) {
			arr[i]*=arr[i-1];
		}

		Max = max(Max,arr[i]);
		
	}

	printf("%.3lf",Max);
}