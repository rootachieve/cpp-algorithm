#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (int)((double)((a + 1) * (b + 1)) / (double)(c + 1)-1);
}