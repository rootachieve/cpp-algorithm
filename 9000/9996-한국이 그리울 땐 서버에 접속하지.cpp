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

int n;
string a;

int main() {
	cin>>n;
	cin>>a;
	string temp;
	for (int i = 01; i <= n; i++) {
		cin>>temp;

		if (temp.length() < a.length() - 1) {
			printf("NE\n");
		}else{
			bool err =false;
			int index = 0;
			int now = 0;
			while (a[index] != '*') {
				if (now == temp.length() || temp[now] != a[index]) {
					err= true;
					break;
				}
				else {
					index++;
					now++;
				}
			}
			index = a.length()-1;
			now = temp.length() - 1;
			while (a[index] != '*') {
				if (now == temp.length() || temp[now] != a[index]) {
					err = true;
					break;
				}
				else {
					index--;
					now--;
				}
			}

			if (err) {
				printf("NE\n");
			}else{
				printf("DA\n");
			}
		}
	}
}