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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
map<string,int> m;
string arr[500001];
int main(){

	int n,num;
	cin>>n>>num;
	for (int i = 1; i <= num; i++) {
		cin>>arr[i];
		if (m[arr[i]] == NULL) {
			m[arr[i]] = i;
		}
		else {
			arr[m[arr[i]]] = "";
			m[arr[i]] = i;
		}
	}
	int i = 1;
	int cnt = 0;
	while (cnt < n&&i<=num) {
		if (arr[i] != "") {
			cout<<arr[i]<<"\n";
			cnt++;
		}
		i++;
	}
}