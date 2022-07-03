#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
//#include <stack>
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
char in[10001];
int ty ;
int main() {
	cin.getline(in,1000);

	for (int i = 0; in[i] != NULL; i++) {
		if (ty == 0) {
			if (in[i] == 'U') {
				ty++;
			}
		}
		else if (ty == 1) {
			if (in[i] == 'C') {
				ty++;
			}
		}
		else if (ty == 2) {
			if (in[i] == 'P') {
				ty++;
			}
		}
		else {
			if (in[i] == 'C') {
				ty++;
				break;
			}
		}
	}

	if (ty == 4) {
		printf("I love UCPC");
	}
	else {
		printf("I hate UCPC");
	}
}