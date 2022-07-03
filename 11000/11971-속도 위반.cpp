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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int arr[2][101];
int main(){
	int n,m;
	cin>>n>>m;
	int a,b;
	int Cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b;
		for (int j = Cnt + 1; j <= Cnt + a; j++) {
			arr[0][j] = b;
		}
		Cnt+=a;
	}
	Cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = Cnt + 1; j <= Cnt + a; j++) {
			arr[1][j] = b;
		}
		Cnt += a;
	}

	int Max = 0;
	for (int i = 1; i <= 100; i++) {
		Max = max(Max,arr[1][i]-arr[0][i]);
	}

	cout<<Max;
}