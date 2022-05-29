#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
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

string a;
int arr[27];
int main() {
	cin>>a;
	for (int i = 0; i < a.size(); i++) {
		arr[a[i]-65]++;
	}

	string f,b;
	string center;
	bool err = false;
	for (int i = 0; i <= 25; i++) {
		while (arr[i] >= 2) {
			f.push_back((char)(i+65));
			b = (char)(i+65) + b;
			arr[i]-=2;
		}

		if (arr[i] != 0 && center =="") {
			center = (char)(i + 65);
		}
		else if (arr[i] != 0 && center != "") {
			err = true;
			break;
		}
	}

	if (err) {
		printf("I'm Sorry Hansoo");
	}
	else {
		cout<<f+center+b;
	}
}