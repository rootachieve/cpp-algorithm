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
int map[7][7];
int main() {
	bool valid = true;
	string in;
	cin>>in;
	string befo = in;
	string temp;
	for (int i = 2; i <= 36; i++) {
		cin>>temp;
		if (temp[0] - befo[0] != 0 && temp[1] - befo[1] != 0 && abs(temp[0] - befo[0]) + abs(temp[1] - befo[1])==3&&map[temp[0]-64][temp[1]-48]==0) {
			map[temp[0] - 64][temp[1] - 48] = 1;
			befo = temp;
		}
		else {

			befo = temp;
			valid = false;
		}
	}

	if(in[0] - befo[0] != 0 && in[1] - befo[1] != 0 && abs(in[0] - befo[0]) + abs(in[1] - befo[1]) == 3) {

	}
	else {
		valid = false;
	}

	if (!valid) {
		cout<<"Invalid";
	}
	else {

		cout << "Valid";
	}
}