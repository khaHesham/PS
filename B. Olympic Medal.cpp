#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x_n(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x_n[i];
    }

    int m;
    cin >> m;
    vector<int> y_m(m);
    for (int i = 0; i < m; i++)
    {
        cin >> y_m[i];
    }

    int k;
    cin >> k;
    vector<int> z_k(k);
    for (int i = 0; i < k; i++)
    {
        cin >> z_k[i];
    }

    int A, B;
    cin >> A >> B;

    double r1 = *max_element(x_n.begin(), x_n.end());
    double p1 = *max_element(y_m.begin(), y_m.end());
    double p2 = *min_element(z_k.begin(), z_k.end());

    cout <<setprecision(10) << sqrt(((pow(r1, 2)) * B) / (A * (p2 / p1) + B));

    return 0;
}