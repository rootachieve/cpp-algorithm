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

ll n,m;

int main() {
	string temp;
	cin>>temp;
	if (temp[0] <= 90 && temp[0] >= 65) {
		cout<<"Error!";
	}
	else {
		bool underBar = false;
		bool upper = false;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == '_') {
				underBar = true;
			}
			if (temp[i] <= 90 && temp[i] >= 65) {
				upper = true;
			}
		}
		string ans;
		if ((upper && underBar)||(temp[temp.size()-1]=='_'||temp[0]=='_')) {
			cout << "Error!";
		}
		else if (upper) {
			for (int i = 0; i <= temp.size(); i++) {
				if (i == temp.size()) {
					cout << ans;
					break;
				}
				if (temp[i] <= 90 && temp[i] >= 65) {
					ans+='_';
					ans+=(temp[i]+32);
				}
				else {
					ans+=("%c", temp[i]);
				}
			}
		}
		else {
			for (int i = 0; i <= temp.size(); i++) {
				if (i == temp.size()) {
					cout<<ans;
					break;
				}
				if (temp[i]=='_') {
					i++;
					ans+=(temp[i] - 32);
					if (temp[i] == '_') {

						cout << "Error!";
						break;
					}
				}else{
					ans+=(temp[i]);
				}
			}
		}
	}
}