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
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
char arr[23][130];

int n;
void draw1(int s) {
	for (int i = s + 1; i <= s + n; i++) {
		arr[0][i] = '-';
	}
}

void draw2(int s) {
	for (int i = 1; i <= n; i++) {
		arr[i][s] = '|';
	}
}


void draw3(int s) {
	for (int i = 1; i <= n; i++) {
		arr[i][s + n + 1] = '|';
	}
}


void draw4(int s) {
	for (int i = s + 1; i <= s + n; i++) {
		arr[n+1][i] = '-';
	}
}


void draw5(int s) {
	for (int i = 1; i <= n; i++) {
		arr[i + n+ 1][s] = '|';
	}
}


void draw6(int s) {
	for (int i = 1; i <= n; i++) {
		arr[i + n + 1][s + n + 1] = '|';
	}
}


void draw7(int s) {
	for (int i = s + 1; i <= s + n; i++) {
		arr[(n+1)*2][i] = '-';
	}
}


int main() {
	string in;
	cin>>n>>in;
	int loc = 0;

	for (int i = 0; i < (n * 2 + 3); i++) {
		for (int j = 0; j < in.size() * (n + 3); j++) {
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '1') {
			draw3(loc);
			draw6(loc);
		}
		else if (in[i] == '2') {
			draw1(loc);
			draw3(loc);
			draw4(loc);
			draw5(loc);
			draw7(loc);
		}
		else if (in[i] == '3') {
			draw1(loc);
			draw3(loc);
			draw4(loc);
			draw6(loc);
			draw7(loc);
		}
		else if (in[i] == '4') {
			draw2(loc);
			draw3(loc);
			draw4(loc);
			draw6(loc);
		}
		else if (in[i] == '5') {

			draw1(loc);
			draw2(loc);
			draw4(loc);
			draw6(loc);
			draw7(loc);
		}
		else if (in[i] == '6') {

			draw1(loc);
			draw2(loc);
			draw4(loc);
			draw5(loc);
			draw6(loc);
			draw7(loc);
		}
		else if (in[i] == '7') {

			draw1(loc);
			draw3(loc);
			draw6(loc);
		}
		else if (in[i] == '8') {

			draw1(loc);
			draw2(loc);
			draw3(loc);
			draw4(loc);
			draw5(loc);
			draw6(loc);
			draw7(loc);
		}
		else if (in[i] == '9') {

			draw1(loc);
			draw2(loc);
			draw3(loc);
			draw4(loc);
			draw6(loc);
			draw7(loc);
		}
		else if (in[i] == '0') {

			draw1(loc);
			draw2(loc);
			draw3(loc);
			draw5(loc);
			draw6(loc);
			draw7(loc);
		}
		loc+=n+3;
	}


	printf("");
	for (int i = 0; i < (n * 2 + 3); i++) {
		printf("%s\n",arr[i]);
	}

}