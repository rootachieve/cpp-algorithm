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

string arr[51];
bool check[51];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			ans++;
			for (int j = i + 1; j <= n; j++) {
				if(!check[j]){
					if (arr[j].size() == arr[i].size()) {
						string temp = arr[j]+arr[j];
						for (int k = 0; k < arr[i].size(); k++) {
							bool err = false;
							for (int g = 0; g < arr[i].size(); g++) {
								if (arr[i][g] != temp[k + g]) {
									err = true;
									break;
								}
							}

							if (!err) {
								check[j] = true;
								break;
							}
						}

					}
				}
			}
		}
	}

	cout<<ans;
}