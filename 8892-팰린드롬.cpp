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
vector<string>v;
int main(){
	int t;
	cin>>t;
	string in;
	while (t--) {
		v.clear();
		int n;
		cin>>n;
		for (int i = 1; i <= n; i++) {
			cin>>in;
			v.push_back(in);
		}

		bool Find = false;
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < n; j++) {
				if(i==j) continue;
				string temp = v[i]+v[j];
				bool err =false;
				int a = 0;
				int b = temp.size()-1;
				while (a <= b) {
					if (temp[a] != temp[b]) {
						err = true;
						break;
					}
					a++;
					b--;
				}

				if (!err) {
					cout<<temp<<"\n";
					Find = true;
					break;
				}
			}
			if (Find) {
				break;
			}
		}

		if (!Find) {
			cout<<"0\n";
		}
	}
}