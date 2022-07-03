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

vector<string> v;

int main() {
	int n,m;
	cin>>n>>m;

	string u ="";
	for (int i = 0; i < n; i++) {
		u+=(char)(i+65);
	}
	string d;
	cin>>d;
	string in;
	for (int i = 1; i <= m; i++) {
		cin>>in;
		v.push_back(in);
	}
	char temp;
	for (int i = 0; v[i][0] != '?'; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (v[i][j] == '-') {
				temp = u[j];
				u[j] = u[j+1];
				u[j+1] = temp;
			}
		}
	}

	for (int i = m-1; v[i][0] != '?'; i--) {
		for (int j = 0; j < n - 1; j++) {
			if (v[i][j] == '-') {
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

	bool err = false;
	string ans;
	for (int i = 0; i < n - 1; i++) {
		if (u[i] == d[i + 1] && u[i + 1] == d[i]) {
			ans+='-';
			temp = u[i];
			u[i] = u[i + 1];
			u[i + 1] = temp;
			ans+='*';
			i++;
		}
		else{
			ans+='*';
		}
	}

	if (u!=d) {
		for (int i = 0; i < n - 1; i++) {
			cout<<'x';
		}
	}
	else {
		if (ans.size() == n) {
			ans.pop_back();
		}
		cout<<ans;
	}

	
}