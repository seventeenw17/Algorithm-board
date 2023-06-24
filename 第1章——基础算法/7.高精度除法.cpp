#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> &a, int b, int &r) {
    vector<int> ans;
    r = 0;
    for (int i = a.size() - 1; i>=0; i--) {
    	r = r * 10 + a[i];
    	ans.push_back(r / b);
    	r %= b;
	}
	reverse(ans.begin(), ans.end());

	while (ans.size() > 1 && ans.back() == 0) {
		ans.pop_back();
	}
	return ans;
}

int main() {
    string s1;
    int b;
    vector<int> a;
    cin >> s1 >> b;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    int r;

    vector<int> c = div(a, b, r);
    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    printf("\n%d\n", r);
    return 0;
}
