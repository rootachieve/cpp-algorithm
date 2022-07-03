#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
struct compare {
    bool operator()(string a, string b) {
        if (a.length() > b.length()) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i % b.length()]) {
                    return a[i] < b[i % b.length()];
                }
            }
            if (b.length() == 1) {
                return true;
            }
            else {
                return b[0] < b[1];
            }
            return false;
        }
        else if (b.length() > a.length()) {
            for (int i = 0; i < b.length(); i++) {
                if (a[i % a.length()] != b[i]) {
                    return a[i % a.length()] < b[i];
                }
            }
            if (a.length() == 1) {
                return false;
            }
            else {
                return a[0] > a[1];
            }
        }
        else {
            return a < b;
        }
    }
};
priority_queue<string, vector<string>, compare> pq;

string solution(vector<ll> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        pq.push(to_string(numbers[i]));
    }
    string answer = "";
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    if (answer[0] == '0') {
        return "0";
    }
    return answer;
}

int main() {
    vector<ll> v;
    ll a;
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&a);
        v.push_back(a);
    }
    string ans = solution(v);

    cout<<ans;
}