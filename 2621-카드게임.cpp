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

vector<pair<int,char>> v;
int main() {
	int b;
	char a;
	for (int i = 1; i <= 5; i++) {
		scanf("%c %d",&a,&b);
		v.push_back({b,a});
		scanf("%c",&a);
	}
	sort(v.begin(),v.end());

	if (v[0].first + 1 == v[1].first && v[1].first + 1 == v[2].first && v[2].first + 1 == v[3].first && v[3].first + 1 == v[4].first &&
		v[0].second == v[1].second && v[1].second  == v[2].second && v[2].second == v[3].second && v[3].second  == v[4].second) {
		cout<<v[4].first +900;
	}
	else if (v[0].first == v[3].first || v[1].first == v[4].first) {
		cout << v[2].first + 800;
	}
	else if (((v[0].first == v[2].first) && (v[3].first == v[4].first)) || (v[0].first == v[1].first && v[2].first == v[4].first)) {
		int temp = v[2].first *10 + 700;
		v[0].first ==v[2].first ? temp+=v[3].first :temp+=v[0].first;
		cout<<temp;
	}else if(v[0].second == v[1].second && v[1].second == v[2].second && v[2].second == v[3].second && v[3].second == v[4].second) {
		cout<<v[4].first +600;
	}
	else if (v[0].first + 1 == v[1].first && v[1].first + 1 == v[2].first && v[2].first + 1 == v[3].first && v[3].first + 1 == v[4].first) {
		cout << v[4].first + 500;
	}
	else if (v[0].first == v[2].first || v[1].first == v[3].first || v[2].first == v[4].first) {
		if (v[0].first == v[2].first) {
			cout<<v[2].first+400;
		}
		else if (v[1].first == v[3].first) {
			cout << v[3].first + 400;
		}
		else {
			cout << v[4].first + 400;
		}
	}
	else if ((v[0].first == v[1].first && v[2].first == v[3].first) || (v[0].first == v[1].first && v[3].first == v[4].first) || (v[1].first == v[2].first && v[3].first == v[4].first)) {
		cout<<v[3].first*10+v[1].first+300;
	}
	else if (v[0].first == v[1].first || v[1].first == v[2].first || v[2].first == v[3].first || v[3].first == v[4].first) {
		if (v[0].first == v[1].first) {
			cout << v[1].first + 200;
		}
		else if (v[1].first == v[2].first) {
			cout << v[2].first + 200;
		}
		else if (v[2].first == v[3].first) {
			cout << v[3].first + 200;
		}
		else {
			cout << v[4].first + 200;
		}
	}
	else {
		cout<<v[4].first+100;
	}
}