#include <bits/stdc++.h>

using namespace std;

double a, b, v1, v2, l, r, m1, m2, kc;
int t;
double f(double x) {
    double ad = sqrt(a*a+(b-x)*(b-x));
    return ad/v1+x/v2;
}

double f_min(double l, double r) {
    double tmp = (double) 1e15;
    for (int i = 0; i < 100; ++i) {
        double m1 = l+(r-l)/3.0;
        double m2 = r-(r-l)/3.0;
        if (f(m1) > f(m2)) {
            l = m1;
        } else r = m2;
        tmp = min(tmp, min(f(m1), f(m2)));
    }
    return tmp;
}

int main() {
    cin >> t;
    for (int it = 1; it <= t; ++it) {
        cin >> a >> b >> v1 >> v2;
        double c1 = a/v1+b/v2;
        double c2 = sqrt(a*1.0*a*1.0+b*1.0*b*1.0)/v1;
        double ans =min(c1, min(c2, f_min(0.000, b*1.000)));
        cout << setprecision(6) << fixed << ans << "\n";
    }
    return 0;
}
