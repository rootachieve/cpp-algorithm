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
bool arr[26];
int main() {
	bool check = false;
	string in;
	cin>>in;
	int ans = 0;
	for(int i = 65;i<=90;i++){
		int j;
		for (j = 0; j < in.size(); j++) {
			if (in[j] == i) {
				break;
			}
		}

		for (j++; in[j] != i; j++) {
			if (arr[in[j] - 65]) {
				arr[in[j] - 65] = false;
			}
			else {
				arr[in[j] - 65] = true;
			}
		}

		for (j = 0; j <= 25; j++) {
			if (arr[j]) {
				ans++;
				arr[j] = false;
			}
		}
	}

	printf("%d",ans/2);
}