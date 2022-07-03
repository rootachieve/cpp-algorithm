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
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
vector<string> v;
string arr[1001];
set<string> s;
int main() {
	int n;
	cin >> n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		reverse(temp.begin(), temp.end());
		v.push_back(temp);
	}
	bool err;
	int Count = 1;
	do {
		s.clear();
		err = false;
		for (int i = 0; i < n; i++) {
			arr[i]+=v[i][Count-1];
			if(s.find(arr[i]) == s.end()){
				s.insert(arr[i]);
			}
			else {
				err = true;
			}
		}
		Count++;
	}while(err);

	cout<<Count-1;
}