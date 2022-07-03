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
bool arr[10000];
int main() {
	int a;
	int in = 0;
	int Min;
	for (int i = 1; i <= 4; i++) {
		in*=10;
		cin>>a;
		in+=a;
	}
	Min = in;
	for (int i = 1; i <= 3; i++) {
		in = in%10*1000+in/10;
		Min = min(Min,in);
	}

	bool Find =false;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int g = 1; g <= 9; g++) {
					int temp = i * 1000 + j * 100 + k * 10 + g;
					int nowMin = temp;
					for (int u = 1; u <= 3; u++) {
						temp = temp % 10 * 1000 + temp / 10;
						nowMin = min(nowMin, temp);
					}

					arr[nowMin] = true;
				}
			}
		}
	}
	int Cnt = 0;
	for (int i = 1111; i <= 9999; i++) {
		if (arr[i]) {
			Cnt++;
		}
		
		if (i == Min) {
			break;
		}
		
		
	}

	cout<<Cnt;
}