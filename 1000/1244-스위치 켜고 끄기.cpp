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

int arr[101];

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}

	int m;
	cin>>m;
	int a,b;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		if (a == 1) {
			for (int i = 1; i <= n; i++) {
				if (i%b == 0) {
					arr[i] == 0 ? arr[i] = 1 : arr[i] = 0;
				}
			}
		}
		else {
			for (int i = 1; b - i >= 1 && b + i <= n; i++) {
				if (arr[b - i] == arr[b + i]) {
					arr[b-i] == 0 ? arr[b-i] = 1 : arr[b-i] = 0;
					arr[b+i] == 0 ? arr[b+i] = 1 : arr[b+i] = 0;
				}
				else {
					break;
				}
			}

			arr[b] == 0 ? arr[b] = 1 : arr[b] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout<<arr[i]<<" ";
		if (i % 20 == 0) {
			cout<<"\n";
		}
	}
}