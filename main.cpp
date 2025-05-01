#include <iostream>
#include <vector>
#include <iomanip>
#define ll long long
using namespace std;

// LCG = (axi + c) % m
class lcg {
public:
    //xi == seed
    static vector<double> LCG(ll xi, ll a, ll c, ll m, int count) {
        vector<ll> numbers(count + 1, 0);
        numbers[0] = xi;

        for (int i = 1; i <= count; i++) {
            numbers[i] = (a * numbers[i - 1] + c) % m; //x1,x2,x3,....
        }

        vector<double> ansVector(count, 0.0);
        for (int i = 1; i <= count; i++) {
            ansVector[i - 1] = static_cast<double>(numbers[i]) / m;
        }

        return ansVector;
    }
};

int main() {
   /*
     test case
    ll xi = 5;
    ll a = 1664525;
    ll c = 1013904223;
    ll m = 4294967296;
    int count = 10;
    */
    ll xi,a,c,m,count;
    cin>>xi>>a>>c>>m>>count;
    vector<double> ans = lcg::LCG(xi, a, c, m, count);

    cout << fixed << setprecision(6);
    for (double num : ans) {
        cout << num << endl;
    }

    return 0;
}
