#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
class Solution {
public:
    ll a[26]={0};
    int lengthAfterTransformations(string s, int t) {
        for(auto ch:s){
            a[ch-'a']++;
        }
        while(t--){
            ll tmp=a[25];
            for(int i=24;i>=0;--i){
                a[i+1]=a[i];
            }
            a[0]=tmp>=mod?tmp-mod:tmp;
            a[1]=(a[1]+tmp)%mod;
        }
        int ans=0;
        for(int i=0;i<26;++i){
            ans=(ans+a[i])%mod;
        }
        return ans;
    }
};
int main(){
    Solution s;
    string t="abcyy";
    int p=2;
    s.lengthAfterTransformations(t,p);
}