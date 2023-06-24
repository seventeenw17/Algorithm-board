#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &a, vector<int> &b) {
	vector<int> sum;
	int t = 0;
	for (int i = 0 ;i < a.size() || i < b.size() ; i++) {
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		sum.push_back(t % 10);
		t /= 10;
	}
	if (t > 0) sum.push_back(1);
	return sum;
}

int main() {
	string s1, s2;
	vector<int> a, b;
	cin >> s1 >> s2;
	for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
	for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

	vector<int> c=add(a, b);
	for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
	return 0;
}
