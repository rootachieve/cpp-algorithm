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
bool comp(string a, string b) {
	if (a.size() == b.size()) {
		return a<b;
	}
	else {
		return a.size()<b.size();
	}
}
int main() {
	int n;
	cin>>n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		string num = "-1";
		for (int j = 0; j <= temp.size(); j++) {
			if (48 <= temp[j] && 58 >= temp[j]) {
				if (num == "-1") {
					num="";
				}

				if (temp[j] == '0') {
					if(num !=""){
						num+=temp[j];
					}
				}
				else {
					num += temp[j];
				}
			}
			else {
				if (num != "-1") {
					if (num == "") {
						v.push_back("0");
					}else{
						v.push_back(num);
					}
				}
				num = "-1";
			}
		}
	}

	sort(v.begin(),v.end(),comp);
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<"\n";
	}
}