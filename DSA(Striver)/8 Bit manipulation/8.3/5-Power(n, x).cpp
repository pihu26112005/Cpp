class Solution {
public:
    double myPow(double x, int n) {
        if(n == -1)
        {
            double t = 1.0/x;
            return t;
        }
        if((int)x == 1)
            return 1;

        int m = n;
        n = abs(n);
        double ans = 1;
        while(n>0)
        {
            if(n%2 == 0)
            {
                x = x*x;
                n = n/2;
            }
            else
            {
                ans = ans*x;
                n = n-1;
            }
        }
        if(m>0)
            return ans;
        else
            return 1.0/ans;
    }
};

// ye kuch cases me chal nhi rha hai 
// puchunga final code 