#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> jobs;

    for (int i = 0; i < n; i++) {
        int d, p;
        cin >> d >> p;
        jobs.push_back(make_tuple(p, d, i + 1));
    }

    sort(jobs.begin(), jobs.end(),
         [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
             return get<0>(a) > get<0>(b);
         });

    vector<bool> slot(n + 1, false);
    vector<int> result;
    int profit = 0;

    for (auto &job : jobs) {
        int p = get<0>(job);
        int d = get<1>(job);
        int id = get<2>(job);

        for (int j = min(d, n); j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result.push_back(id);
                profit += p;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int x : result)
        cout << "J" << x << " ";

    cout << "\nMaximum Profit = " << profit << endl;

    return 0;
}
