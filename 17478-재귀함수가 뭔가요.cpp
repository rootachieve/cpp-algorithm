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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int n;
void back(int num) {
	for (int i = 1; i <= num; i++) {
		cout << "____";
	}
	cout << "\"재귀함수가 뭔가요?\"" << endl;;
	for (int i = 1; i <= num; i++) {
		cout << "____";
	}
	if (num == n) {

		cout<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;

	}
	else {
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
		for (int i = 1; i <= num; i++) {
			cout << "____";
		}
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
		for (int i = 1; i <= num; i++) {
			cout << "____";
		}
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
		back(num+1);
	}
	for (int i = 1; i <= num; i++) {
		cout << "____";
	}
	cout << "라고 답변하였지." << endl;
}
int main() {
	cin>>n;
	cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	cout << "\"재귀함수가 뭔가요?\"" << endl;
	cout <<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
	back(1);

	cout << "라고 답변하였지." << endl;
}