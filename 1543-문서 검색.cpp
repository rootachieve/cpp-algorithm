#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <string>
#include <math.h>
#include <algorithm>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

string in1,in2;
int ans;
bool Check(int loc) {
	for (int i = 0; i < in2.size(); i++) {
		if (in2[i] != in1[i + loc]) {
			return false;
		}
	}
	return true;
}
int main() {
	getline(cin,in1);

	getline(cin, in2);

	if(in1.size()<in2.size()){
		printf("0");
	}
	else {
		for (int i = 0; in2.size() + i <= in1.size(); i++) {
			if (Check(i)) {
				ans++;
				i+=in2.size()-1;
			}
		}

		printf("%d", ans);
	}

}