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
char arr[26];
bool arr2[26];
int main() {
	int n,m;
	cin>>n>>m;
	bool err = false;
	for (int i = 0; i < n; i++) {
		arr[i] = '?';
	}
	int point = 0;
	int a;
	string b;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		point = (point+a)%n;
		if (arr[point] == '?') {
			if (arr2[b[0] - 65]) {
				err=true;
			}
			arr2[b[0]-65] = true;
			arr[point] = b[0];
		}
		else {
			if (arr[point] != b[0]) {
				err = true;
			}
		}
	}

	if (err) {
		cout<<'!';
	}
	else {
		int Cnt = n;
		while (Cnt > 0) {
			cout<<arr[point];
			Cnt--;
			point--;
			if (point == -1) {
				point = n-1;
			}
		}
	}
}