 vector<int> findTwoElement(vector<int>& a) {
        // code here
         long long n = a.size(); 

    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    // X-Y = t1
    long long t1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long t2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    // X+Y = t2
    t2 = t2 / t1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = t1 and X+Y = t2:
    long long x = (t1 + t2) / 2;
    long long y = x - t1;
    return {x,y};
    }