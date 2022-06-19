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
set<string> s;
int h1,h2,h3,m1,m2,m3;
int nowH,nowM;
int ans;
int main() {
	string temp;
	cin>>temp;
	h1 = (temp[0]-48)*10 + (temp[1] -48);
	m1 = (temp[3]-48)*10 + (temp[4] -48);
	cin >> temp;
	h2 = (temp[0] - 48) * 10 + (temp[1] - 48);
	m2 = (temp[3] - 48) * 10 + (temp[4] - 48);
	cin >> temp;
	h3 = (temp[0] - 48) * 10 + (temp[1] - 48);
	m3 = (temp[3] - 48) * 10 + (temp[4] - 48);

	while (!cin.eof()) {
		cin>>temp;
		nowH = (temp[0] - 48) * 10 + (temp[1] - 48);
		nowM = (temp[3] - 48) * 10 + (temp[4] - 48);
		cin>>temp;
		if (nowH < h1 || (nowH == h1 && nowM <= m1)) {
			if (s.find(temp) == s.end()) {
				s.insert(temp);
			}
		}
		else if (nowH > h2 || (nowH == h2 && nowM >= m2)) {
			if (nowH < h3 || (nowH == h3 && nowM <= m3)) {
				if (s.find(temp) != s.end()) {
					s.erase(temp);
					ans++;
				}
			}
		}
	}

	cout<<ans;
}
