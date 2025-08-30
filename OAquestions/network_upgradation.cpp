#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm_ll(long long a, long long b) { return a / gcd(a,b) * b; }

long long min_time(long long t1, long long req1, long long t2, long long req2) {
    long long lo = 0, hi = (t1 + t2) * max(req1, req2) + 5; // safe upper bound
    long long L = lcm_ll(req1, req2);
    auto ok = [&](long long T){
        long long A1 = T - T/req1;
        long long A2 = T - T/req2;
        long long U  = T - T/L;
        return (A1 >= t1) && (A2 >= t2) && (U >= t1 + t2);
    };
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(){
    long long t1=3, req1=2, t2=1, req2=3;
    cout << min_time(t1, req1, t2, req2) << "\n"; // prints 5
}
