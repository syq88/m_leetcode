#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
class Solution {
public:
    int mmax=0;
    vector<int> validans;
    bool check(int num,int m){
        vector<int> tmp;
        for(int i=0;i<m;++i){
            tmp.push_back(num%3);
            num/=3;
        }
        for(int i=1;i<tmp.size();++i){
            if(tmp[i]==tmp[i-1])return false;
        }
        return true;
    }
    bool check2(int a,int b,int m){
        for(int i=0;i<m;++i){
            int aa=a%3,bb=b%3;
            if(aa==bb)return false;
            a/=3,b/=3;
        }
        return true;
    }
    vector<vector<int>> validans2;
    vector<vector<ll>> dp;
     int colorTheGrid(int m, int n) {
        mmax=pow(3,m);
        for(int i=0;i<mmax;++i){
            if(check(i,m))validans.push_back(i);
        }
        validans2.resize(validans.size());
        int size=validans.size();
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                if(check2(validans[i],validans[j],m))validans2[i].push_back(j);
            }
        }
        dp.resize(n+1,vector<ll>(size,0));
        for(int i=0;i<size;++i){
            dp[0][i]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<size;++j){
                for(auto val:validans2[j]){
                    dp[i][j]=(dp[i][j]+dp[i-1][val])%mod;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<size;++i){
            ans=(ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};
int main(){
    Solution s;
    int m=5;
    int n=5;
    s.colorTheGrid(m,n);
}