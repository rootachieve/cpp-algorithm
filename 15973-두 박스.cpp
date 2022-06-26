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

string arr[4][4] = {{"FACE","LINE","FACE","NULL"},{"LINE","POINT","LINE","NULL"},{"FACE","LINE","FACE","NULL"},{"NULL","NULL","NULL","NULL"}};
vector<pair<int,int>> x;

vector<pair<int, int>> y;
int main() {

	int LBx1,LBy1,RUx1,RUy1;
	cin>>LBx1>>LBy1>>RUx1>>RUy1;
	x.push_back({LBx1,1});
	x.push_back({RUx1,1}); 
	y.push_back({ LBy1,1 });
	y.push_back({ RUy1,1 });
	int LBx2, LBy2, RUx2, RUy2;
	cin >> LBx2 >> LBy2 >> RUx2 >> RUy2;
	x.push_back({ LBx2,2 });
	x.push_back({ RUx2,2 });
	y.push_back({ LBy2,2 });
	y.push_back({ RUy2,2 });

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	int X = 0;
	int Y = 0;



	if (x[0].first == x[1].first || x[2].first == x[3].first) {
		X=1;
	}
	else if (x[1].first == x[2].first) {
		X=2;
	}
	else if (x[0].second == x[3].second) {
		X=1;
	}
	else if (x[0].second == x[2].second) {
		X=3;
	}
	else if (x[0].second == x[1].second) {
		X=4;
	}
	

	if (y[0].first == y[1].first || y[2].first == y[3].first) {
		Y = 1;
	}
	else if (y[1].first == y[2].first) {
		Y = 2;
	}
	else if (y[0].second == y[3].second) {
		Y = 1;
	}
	else if (y[0].second == y[2].second) {
		Y = 3;
	}
	else if (y[0].second == y[1].second) {
		Y = 4;
	}


	cout<<arr[X-1][Y-1];
}