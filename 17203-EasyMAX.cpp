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

int arr[1001];
int arr2[1001];
int main() {
	int n,m;
	int a,b;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
		arr2[i] = abs(arr[i] - arr[i-1]) + arr2[i-1];
	}

	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		if (b <= a) {
			cout<<0<<"\n";
		}else{
			cout<<arr2[b] - arr2[a]<<"\n";
		}
	}
}