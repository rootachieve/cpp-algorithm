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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

string arr[10];
bool check[12];
int n;
ll Min = 9999999999;
string ansI;
string ansX;
ll Max = 0;
void back(int now, string num) {
	if (now == 0) {
		for (int i = 0; i <= 9; i++) {
			check[i] = true;
			back(1,num + to_string(i));
			check[i] = false;
		}
	}
	else if (now == n+1) {

		if (Max < stoll(num)) {
			Max=stoll(num);
			ansX = num;
		}

		if (Min > stoll(num)) {

			Min = stoll(num);
			ansI =num;
		}
	}
	else {
		int b = num[now-1] - 48;
		if (arr[now][0] == '>') {
			for (int i = b - 1; i >= 0; i--) {
				if (!check[i]) {
					check[i] = true;
					back(now+1, num + to_string(i));
					check[i] = false;
				}
			}
		}
		else {
			for (int i = b + 1; i <= 9; i++) {
				if (!check[i]) {
					check[i] = true;
					back(now + 1, num + to_string(i));
					check[i] = false;
				}
			}
		}
	}
}

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}

	back(0,"");
	cout<<ansX<<endl;
	cout<<ansI;
}