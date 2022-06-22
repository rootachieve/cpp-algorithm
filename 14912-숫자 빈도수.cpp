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

int main() {
	int n;
	int num;
	cin>>n>>num;
	int Cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100000; j*=10) {
			if ((i / j) > 0 && (i / j) % 10 == num) {
				Cnt++;
			}
		}
	}
	cout<<Cnt;
}