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
vector<string> v;

string in;
pair<int,int> back(int s) {
	int num = 0;
	int endpoint = 0;
	for (int i = s + 1; ; i++) {
		if (in[i] == 'C') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num+=12*(in[i+1]-48);
				i++;
			}
			else {
				num+=12;
			}
		}
		else if (in[i] == 'O') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num += 16 * (in[i + 1] - 48);
				i++;
			}
			else {
				num += 16;
			}
		}
		else if (in[i] == 'H') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num += 1 * (in[i + 1] - 48);
				i++;
			}
			else {
				num += 1;
			}
		}
		else if (in[i] == '(') {
			pair<int,int> b = back(i);
			if (in[b.second + 1] >= 48 && in[b.second + 1] <= 58) {
				num += b.first * (in[b.second + 1] - 48);
				i = b.second + 1;
			}
			else {
				num += b.first;
				i = b.second;
			}
		}
		else if(in[i]==')'){
			endpoint = i;
			break;
		}
	}

	return {num,endpoint};
}
int main(){
	cin>>in;

	int num = 0;
	int endpoint = 0;
	for (int i = 0;i<in.size(); i++) {
		if (in[i] == 'C') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num += 12 * (in[i + 1] - 48);
				i++;
			}
			else {
				num += 12;
			}
		}
		else if (in[i] == 'O') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num += 16 * (in[i + 1] - 48);
				i++;
			}
			else {
				num += 16;
			}
		}
		else if (in[i] == 'H') {
			if (in[i + 1] >= 48 && in[i + 1] <= 58) {
				num += 1 * (in[i + 1] - 48);
				i++;
			}
			else {
				num += 1;
			}
		}
		else if (in[i] == '(') {
			pair<int, int> b = back(i);
			if (in[b.second + 1] >= 48 && in[b.second + 1] <= 58) {
				num += b.first * (in[b.second + 1] - 48);
				i = b.second + 1;
			}
			else {
				num += b.first;
				i = b.second;
			}
		}
	}

	cout<<num;
}