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
int map[102][102];
int check[102][102];
vector<pair<pair<int,int>,int>>v;
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin>>temp;
		for (int j = 1; j <= m; j++) {
			temp[j-1] == '.' ? map[i][j] = 0 : map[i][j] = 1;
			if(map[i][j] == 1) check[i][j] = 1;
		}
	}
	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				for (int k = 1;; k++) {
					if((map[i-k][j]==0||map[i+k][j] == 0|| map[i][j-k] == 0 || map[i][j+k] == 0)){
						if(k!=1){
							v.push_back({{i,j},k-1});
							check[i][j] = 0;
						}
						break;
					}
					else {
						check[i-k][j] = 0;
						check[i+k][j] = 0;
						check[i][j-k] = 0;
						check[i][j+k] = 0;
					}
				}
			}
		}
	}

	bool err = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] == 1) {
				err = true;
			}
		}
	}

	if (err) {
		cout<<-1;
	}else{
		cout<<v.size()<<"\n";
		for (int i = 0; i < v.size(); i++) {
			printf("%d %d %d\n",v[i].first.first,v[i].first.second,v[i].second);
		}
	}
}