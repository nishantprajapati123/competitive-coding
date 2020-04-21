#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<int> find_steps(const vector<int>& a) {
    vector<int> steps;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 1 && a[i + 1] == 0) steps.push_back(i);
    }
    return steps;
}


int main() {
    cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = (s[i] == 'L') ? 0 : 1;
    int maxi = 0, mini = 0;
    int cnt = 0;
    int last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            ++cnt;
        } else {
            if (cnt == 0) continue;
            maxi += cnt;
            mini = max(cnt, last + 1);
            last = mini;
        }
    }
    if (k < mini || k > maxi) {
        cout << -1;
        return 0;
    }
    bool is_min = false;
    vector<int> have_step;
    for (int i = 0; i < k; ++i) {
        if (!is_min) {
            auto steps = find_steps(a);
            cout << min(int(steps.size()), maxi - k + i + 1) << ' ';
            int cur = 0;
            while (k - i - 1 < maxi && cur < steps.size()) {
                cout << steps[cur] + 1 << ' ';
                a[steps[cur]] = 0;
                a[steps[cur] + 1] = 1;
                ++cur;
                --maxi;
            }
            if (maxi == k - i - 1) {
                is_min = true;
                have_step = find_steps(a);
            }
        } else {
            int v = have_step.back();
            have_step.pop_back();
            cout << "1 " << v + 1;
            a[v] = 0;
            a[v + 1] = 1;
            if (v > 0 && a[v - 1] == 1) {
                have_step.push_back(v - 1);
            }
            if (v + 2 < n && a[v + 2] == 0) {
                have_step.push_back(v + 1);
            }
        }
        cout << '\n';
    }
}