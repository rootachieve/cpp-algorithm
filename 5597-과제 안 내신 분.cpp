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
bool arr[33];
int main() {
	int a;
	for (int i = 1; i <= 28; i++) {
		cin>>a;
		arr[a] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) {
			cout<<i<<"\n";
		}
	}
}