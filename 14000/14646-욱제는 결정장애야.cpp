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
bool arr[100001];
int main() {
	int n;
	int a;
	int Max = 0;
	int Cnt = 0;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a;
		if (arr[a]){
			arr[a] = false;
			Cnt--;
		}
		else {
			arr[a] = true;
			Cnt++;
			Max = max(Max,Cnt);
		}
	}

	cout<<Max;
}