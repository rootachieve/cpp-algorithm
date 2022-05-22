#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>
#include <algorithm>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int CountZ;
int CountO;

int main() {
	string in;
	cin>>in;
	char now ='2';
	for (int i = 0; i < in.size(); i++) {
		if (now != in[i]) {
			if (in[i] == '0') {
				CountZ++;
				now = in[i];
			}
			else {
				CountO++;
				now = in[i];
			}
		}
	}

	printf("%d",min(CountZ,CountO));
}