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
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int map[101][101];

int main() {
	int n;
	cin>>n;
	int a,b;
	for (int i = 1; i <= n; i++) {
		cin>>b>>a;
		for (int g = a; g < a + 10; g++) {
			for (int h = b; h < b + 10; h++) {
				map[g][h] = 1;
			}
		}
	}
	int Cnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] == 1) {
				if (map[i - 1][j] == 0){
					Cnt++;
				}

				if (map[i + 1][j] == 0) {
					Cnt++;
				}

				if (map[i][j - 1] == 0) {
					Cnt++;
				}

				if (map[i][j + 1] == 0) {
					Cnt++;
				}
			}
		}
	}

	cout<<Cnt;
}