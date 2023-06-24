#include <bits/stdc++.h>
using namespace std;

//高精度 X int
vector<int> mul(vector<int> &a, int b) {
    vector<int> ans;
    int t = 0;
    for (int i = 0;i < a.size() || t; i++) {
    	if(i < a.size()) t += a[i]*b;
    	ans.push_back(t % 10);
    	t /= 10;
	}

	while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
	return ans;
}

int main() {
    string s1;
    int b;
    vector<int> a;
    cin >> s1 >> b;
    if (b == 0) {
		cout << "0" << endl;
		return 0;
	}
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');

    vector<int> c = mul(a, b);
    for (int i = c.size() - 1; i>=0; i--) printf("%d", c[i]);
    return 0;
}

//高精度 X 高精度
vector<int> mul(vector<int> &a, vector<int> &b) {
	vector<int> ans;
	int t[100010] = {0};
	for (int i = 0;i < b.size(); i++) {
		int beg = i;
		for (int j = 0; j < a.size(); j++) {
			t[beg++] += a[j] * b[i];
		}
	}
	for (int i = 0; i < a.size() + b.size(); i++) {
		if (t[i] > 9) {
			t[i + 1] += t[i] / 10;
			t[i] %= 10;
		}
		ans.push_back(t[i]);
	}
	while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
	return ans;
}

int main() {
	string s1, s2;
	vector<int> a;
	vector<int> b;
	cin >> s1 >> s2;
	for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
	for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

	vector<int> c = mul(a, b);
	for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
	return 0;
}

