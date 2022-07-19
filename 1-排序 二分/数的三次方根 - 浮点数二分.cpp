//浮点数的二分  ==>直接暴力二分，移动区间就行，什么都不用考虑
#include <iostream>

using namespace std;

int main()
{
    
    double x;
    scanf("%lf",&x);
    
    //划分区间 
    double l = -100, r = 100;
    
    while(r - l > 1e-8)
    {
        double mid = (l + r)/2;
        if(mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%.6lf",l);
}
