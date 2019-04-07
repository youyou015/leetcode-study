#pragma once

// No. 50 Pow(x, n)
// ¿ìËÙÃİËã·¨
double myPow(int x, int n)
{
    double res = 1, base = x;
    while (n != 0)
    {
        if ((n & 1) != 0)
        {
            res *= base;
        }
        n >>= 1;
        base *= base;
    }
    return res;
}
