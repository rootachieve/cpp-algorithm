#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 100999
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

ll arr[2001][2001];

int main(){
	arr[0][0] = 1;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 0; i + j <= 2000; j++) {	
			arr[i][i+j] = MODULAR(arr[i][i+j], arr[i-1][j]);
		}

		for (int j = 0; j <= 2000; j++) {
			arr[i][j] = MODULAR(arr[i][j], arr[i - 1][j]);
		}

	}

	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		cout<<arr[n][n]%MOD<<"\n";
	}
}