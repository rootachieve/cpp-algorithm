#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int base[12];

int map[12][12];
int temp[12][12];
int Min = 101;
void back(int now) {
	if (now == 11) {
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				temp[i][j] = map[i][j];
			}
		}
		int Cnt = 0;

		for (int j = 1; j <= 10; j++) {
			if (base[j] == 1) {
				Cnt++;
				temp[1][j + 1] == 1 ? temp[1][j + 1] = 0 : temp[1][j + 1] = 1;

				temp[2][j] == 1 ? temp[2][j] = 0 : temp[2][j] = 1;

				temp[1][j - 1] == 1 ? temp[1][j - 1] = 0 : temp[1][j - 1] = 1;

				temp[1][j] == 1 ? temp[1][j] = 0 : temp[1][j] = 1;
			}
		}
		for (int i = 2; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (temp[i - 1][j] == 1) {
					Cnt++;
					temp[i - 1][j] == 1 ? temp[i - 1][j] = 0 : temp[i - 1][j] = 1;

					temp[i][j + 1] == 1 ? temp[i][j + 1] = 0 : temp[i][j + 1] = 1;

					temp[i + 1][j] == 1 ? temp[i + 1][j] = 0 : temp[i + 1][j] = 1;

					temp[i][j - 1] == 1 ? temp[i][j - 1] = 0 : temp[i][j - 1] = 1;

					temp[i][j] == 1 ? temp[i][j] = 0 : temp[i][j] = 1;
				}
			}
		}
		bool err = false;
		for (int i = 1; i <= 10; i++) {
			if (temp[10][i] == 1) {
				err = true;
				break;
			}
		}

		if (!err) {
			Min = min(Min,Cnt);
		}

	}
	else {
		base[now] = 0;
		back(now+1);
		base[now] = 1;
		back(now+1);
	}
}
int main() {
	string in;
	for (int i = 1; i <= 10; i++) {
		cin>>in;
		for (int j = 1; j <= 10; j++) {
			if (in[j - 1] == 'O') {
				map[i][j] = 1;
			}
		}
	}
	
	back(1);

	if (Min==101) {
		cout<<-1;
	}
	else {
		cout<<Min;
	}
}