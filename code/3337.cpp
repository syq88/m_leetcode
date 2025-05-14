#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
struct martix{
    ll a[26][26];
    martix(vector<int>& nums){
       for(int i=0;i<26;++i){
        for(int j=0;j<26;++j){
            if(j==i)a[i][j]=0;
            if(j<i){
                if(nums[j]>=i-j)a[i][j]=1;
                else a[i][j]=0;
            }
            if(j>i){
                if(nums[j]>=26-(j-i))a[i][j]=1;
                else a[i][j]=0;
            }
        }
       }
    }
    martix(){
        memset(a,0,sizeof(a));
        for(int i=0;i<26;++i){
            a[i][i]=1;
        }
    }
    martix operator*(martix b){
        martix res;
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                ll sum=0;
                for(int k=0;k<26;++k)sum=(sum+a[i][k]*b.a[k][j]%mod)%mod;
                res.a[i][j]=sum%mod;
            }
        }
        return res;
    }
    vector<int> operator*(const vector<int>&b){
        vector<int> res(26);
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                res[i]=(res[i]+a[i][j]*b[j]%mod)%mod;
            }
        }
        return res;
    }
};
martix qpow(martix p,int t){
    martix res;
    while(t){
        if(t&1){
            res=res*p;
        }
        t>>=1;
        p=p*p;
    }
    return res;
}
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        martix p(nums);
        martix res=qpow(p,t);
        vector<int> ss(26);
        for(auto val:s){
            ss[val-'a']++;
        }
        vector<int> res2=res*ss;
        ll res3=0;
        for(auto val: res2){
            res3=(res3+val)%mod;
        }
        return res3;
    }
};
int main(){
    Solution s;
    string ss="azbk";
    int t=1;
    vector<int> nums={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    s.lengthAfterTransformations(ss,t,nums);
}