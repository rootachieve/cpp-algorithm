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


int arr[53];

int main() {
	int n;
	cin>>n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		arr[a]++;
	}
	cin.ignore();
	string temp;
	getline(cin,temp);
	for (int i = 0, l = temp.size(); i < l; i++) {
		if (temp[i] == ' ') {
			arr[0]--;
		}
		else if (65 <= temp[i]&&temp[i] <= 95) {
			arr[temp[i]-64]--;
		}
		else {
			arr[temp[i]-70]--;
		}
	}

	for (int i = 0; i <= 53; i++) {
		if (i == 53) {
			printf("y");
			break;
		}
		if (arr[i] != 0) {
			printf("n");
			break;
		}
	}
}