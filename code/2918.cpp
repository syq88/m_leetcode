#include <bits/stdc++.h>
#define ll long long 
using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1=0;
        bool flag=false;
        for(auto val:nums1){
            if(val==0)sum1+=1,flag=true;
            else sum1+=val;
        }
        ll sum2=0;
        bool flag2=false;
        for(auto val:nums2){
            if(val==0)sum2+=1,flag2=true;
            else sum2+=val;
        }
        if(sum1==sum2)return sum1;
        if(sum1<sum2&&flag==false)return -1;
        if(sum2<sum1&&flag2==false)return -1;
        return max(sum1,sum2);
    }
};