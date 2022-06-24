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

int arr[101];
int peo[11];
int temp[11];
int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		for (int i = 0; i <= 100; i++) {
			arr[i] = 0;
		}
		for (int i = 1; i <= 10; i++) {
			peo[i] = 0;
			temp[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin>>peo[i];
			if (peo[i] % 2 == 1) {
				peo[i]++;
			}
			arr[peo[i]]++;
		}
		int Cnt = 0;
		while (arr[peo[1]] != n) {
			for (int i = 1; i <= n; i++) {
				arr[peo[i]]--;
				if (i == n) {
					temp[1] = peo[i]/2;
					peo[i] -= peo[i]/2;

				}
				else {
					temp[i + 1] = peo[i] / 2;
					peo[i] -= peo[i] / 2;
				}
			}

			for (int i = 1; i <= n; i++) {
				peo[i]+=temp[i];
				temp[i] = 0;
				if (peo[i] % 2 == 1) {
					peo[i]++;
				}

				arr[peo[i]]++;
			}
			Cnt++;
		}
		cout<<Cnt<<"\n";
	}
}