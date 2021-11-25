#include <iostream>
#include<cmath>
using namespace std;

class Solution1{
public:
    int mySqrt(int x){
        if(x == 0){
            return 0;
        }
        int ans = exp(0.5*log(x));
        return ((long long)(ans+1)*(ans+1) > x ? ans : ans+1);
    }
};

class Solution{
public:
    int mySqrt(int x){
        if(x == 0){
            return 0;
        }
        int left = 0 ;
        int right = x;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if((long long)mid * mid > x){
                right = mid - 1;
            }
            else{
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    int a = 30;
    Solution s;
    cout<<s.mySqrt(a)<<endl;
}