#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

bool arr[1001];
int n,m;
int Cnt;
int main() {
	cin>>n>>m;

	for (int i = 2; i <= n; i++) {
		if (Cnt == n) {
			break;
		}
		if (!arr[i]) {
			for (int j = i; j <= n; j += i) {
				if(!arr[j]){
					arr[j] = true;
					Cnt++;
					if (Cnt == m) {
						printf("%d",j);
						break;
					}
				}
			}
		}
		
	}
}