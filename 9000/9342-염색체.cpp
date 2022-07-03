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
int main(){
	int t;
	cin>>t;
	string in;
	while (t--) {
		cin>>in;
		string temp ="";
		char now ='0';
		for (int i = 0; i <= in.size(); i++) {
			if (now != in[i]) {
				temp+=in[i];
				now = in[i];
			}
		}

		if (temp.size() == 3) {
			if (temp[0] == 'A' && temp[1] == 'F' && temp[2] == 'C') {
				cout<<"Infected!\n";
			}
			else {
				cout << "Good\n";
			}
		}
		else if (temp.size() == 4) {
			if (temp[0] == 'A' && temp[1] == 'F' && temp[2] == 'C' && temp[3] - 65 <= 5) {

				cout << "Infected!\n";
			}
			else if (temp[1] == 'A' && temp[2] == 'F' && temp[3] == 'C' && temp[0] - 65 <= 5) {

				cout << "Infected!\n";
			}
			else {

				cout << "Good\n";
			}
		}
		else if (temp.size() == 5) {
			if (temp[1] == 'A' && temp[2] == 'F' && temp[3] == 'C'&&temp[0]-65<=5&&temp[4]-65<=5) {
				
				cout << "Infected!\n";
			}
			else {
				cout << "Good\n";
			}
		}
		else {
			cout<<"Good\n";
		}
	}
}