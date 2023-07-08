class Solution {
public:
    /*
        Fibbonacci Problem
        The concurent is f[n]=f[n-1]+f[n-2]
    */
    int climbStairs(int n) {
        int fib[n+1];
        fib[0]=1;
        fib[1]=1;
        for(int i=2; i<=n; i++) fib[i]=fib[i-2]+fib[i-1];
        return fib[n];
    }
};