#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll dp[750][45][15];
class Solution {
    public:
    int a[10];
    int s[11]={0};
    ll c[85][85]={0};
        void init(){
            memset(dp,0,sizeof(dp));
            for(int i=9;i>=0;--i){
                s[i]=a[i]*i+s[i+1];
            }
            for(int i = 0; i < 85; ++i){
                c[i][0] = 1;
                for(int j = 1; j <= i; ++j){
                    c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
                }
            }
        }
        int b[10];
        ll ans=0;
        bool check(int sum1,int cnt1,int p,int t){
            for(int i=9;i>=p&&cnt1;--i){
                int tmp=cnt1<a[i]?cnt1:a[i];
                sum1+=tmp*i;
                cnt1-=tmp;
            }
            if(sum1<t)return false;
            return true;
        }
        bool check2(int sum1,int cnt1,int p,int t){
            for(int i=p;i<=9&&cnt1;++i){
                int tmp=cnt1<a[i]?cnt1:a[i];
                sum1+=tmp*i;
                cnt1-=tmp;
            }
            if(sum1>t)return false;
            return true;
        }
        ll dfs(int p,int sum,int cnt1,int cnt2,int t,int size){
            if(p==10&&sum==t&&cnt1==(size+1)/2){
                return 1;
            }
            if(p==10)return 0;
            if(sum>t)return 0;
            if(sum+s[p]<t)return 0;
            if(!check(sum,(size+1)/2-cnt1,p,t)||!check2(sum,(size+1)/2-cnt1,p,t))return 0;
            if(cnt1>(size+1)/2||cnt2>size/2)return 0;
            if(dp[sum][cnt1][p])return dp[sum][cnt1][p];
            ll tmp=0;
            for(int i=0;i<=a[p];++i){
                b[p]=i;
                ll qq=c[cnt1+i][i]*c[cnt2+a[p]-i][a[p]-i]%mod;
                tmp=(tmp+(qq*dfs(p+1,sum+i*p,cnt1+i,cnt2+a[p]-i,t,size)%mod))%mod;
            }
            return dp[sum][cnt1][p]=tmp;
        }
        int countBalancedPermutations(string num) {
            int sum=0;
            for(auto val:num){
                a[val-'0']++;
                sum+=val-'0';
            }
            if(sum%2==1)return 0;
            init();
            return dfs(0,0,0,0,sum/2,num.size());
             }
    };
int main(){
    Solution s;
    string num;
    // cin>>num;
    cout<<s.countBalancedPermutations("112");
}