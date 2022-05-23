#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
string in;
bool check(int ty,int loc) {
	if (ty == 1) {
		if (in[loc] == 'X' && in[loc + 1] == 'X' && in[loc + 2] == 'X' && in[loc + 3] == 'X') {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (in[loc] == 'X' && in[loc + 1] == 'X') {
			return true;
		}
		else {
			return false;
		}
	}
}


int main() {
	cin>>in;
	bool err =false;
	for (int i = 0; i < in.size(); i++) {
		if(in[i]!='.'){
			if (i <= in.size() - 4 && check(1, i)) {
				in[i] = 'A';
				in[i + 1] = 'A';
				in[i + 2] = 'A';
				in[i + 3] = 'A';
				i+=3;
			}
			else if(i <= in.size() - 2&&check(2,i)) {
				in[i] = 'B';
				in[i+1] = 'B';
				i++;
			}
			else {
				err = true;
				break;
			}
		}
	}

	if (err) {
		printf("-1");
	}
	else {
		cout<<in;
	}
}