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
ll n;
stack<int> s;
int main() {
	cin>>n;

	if (n == 0) {
		printf("0");
	}else{
		while (n != 0) {
			if (n % 2 == 0) {
				s.push(0);
				n/=-2;
			}
			else {
				s.push(1);
				if (n < 0) {
					n--;
					n/=-2;
				}
				else {
					n/=-2;
				}
			}
		}

		while (!s.empty()) {
			cout<<s.top();
			s.pop();
		}

	}
}