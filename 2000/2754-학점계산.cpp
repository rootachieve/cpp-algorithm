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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 100999
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

map<string,string> m = {{"A+","4.3"}, {"A0", "4.0"},{ "A-" , "3.7"},{"B+" , "3.3"}, {"B0" , "3.0"}, {"B-" , "2.7"},{"C+" , "2.3"}, {"C0", "2.0"}, {"C-" , "1.7"},{"D+" , "1.3"}, {"D0" , "1.0"}, {"D-" , "0.7"},{"F" , "0.0" },};
int main() {
	string in;
	cin>>in;
	cout<<m[in];
}