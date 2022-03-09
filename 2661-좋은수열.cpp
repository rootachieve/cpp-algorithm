#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n;
string t = "";
bool Find = false;

bool check() {
	bool err = true;
	int node = t.size();
	for (int i = 1; i <= node / 2; i++) {
		
		if (t.substr(node - i, i) == t.substr(node - i * 2, i)) {
			err = false;
			break;
		}
	}

	return err;
}

void back(int now) {
	if (now == n) {
		printf("%s",t.c_str());
		Find = true;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (Find) {
				break;
			}
			char temp = i+48;
			t.push_back(temp);
			if (check()) {
				back(now+1);
			}
			t.pop_back();
		}
	}
}
int main() {
	scanf("%d",&n);
	back(0);
}