#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
class Solution {
public:
    int dp0[N],from0[N],dp1[N],from1[N];
    bool check(int i,int j,const vector<string>&words,const vector<int>&groups){
        if(groups[i]==groups[j]||words[i].size()!=words[j].size())return false;
        int cnt=0;
        for(int k=0;k<min(words[i].size(),words[j].size());++k){
            if(words[i][k]!=words[j][k])cnt++;
        }
        // cnt+=abs((int)words[i].size()-(int)words[j].size());
        if(cnt!=1)return false;
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        memset(dp0,0,sizeof(dp0));
        memset(dp1,0,sizeof(dp1));
        memset(from0,-1,sizeof(from0));
        memset(from1,-1,sizeof(from1));
        dp1[0]=1;
        for(int i=1;i<words.size();++i){
            if(dp0[i-1]>dp1[i-1]){
                dp0[i]=dp0[i-1];
                from0[i]=from0[i-1];
            }
            else dp0[i]=dp1[i-1],from0[i]=i-1;
            int mmax =0,res=-1;
            for(int j=0;j<i;++j){
                if(!check(i,j,words,groups))continue;
                if(dp1[j]>mmax)mmax=dp1[j],res=j;
            }
            dp1[i]=mmax+1,from1[i]=res;
        }
        vector<string> res1;
        int size=words.size();
        // for(int i=0;i<size;++i){
        //     cout<<dp0[i]<<" ";
        // }
        // cout<<endl;
        //  for(int i=0;i<size;++i){
        //     cout<<dp1[i]<<" ";
        // }
        // cout<<endl;
        //          for(int i=0;i<size;++i){
        //     cout<<from0[i]<<" ";
        // }
        // cout<<endl;
        //          for(int i=0;i<size;++i){
        //     cout<<from1[i]<<" ";
        // }
        // cout<<endl;
        if(dp1[size-1]>dp0[size-1]){
           int i=size-1;
           while(i!=-1){
                res1.push_back(words[i]);
                i=from1[i];
           }
            
        }
        else{
            int i=from0[size-1];
            while (i!=-1)
            {
                res1.push_back(words[i]);
                i=from1[i];
            }
            
        }
        reverse(res1.begin(),res1.end());
        return res1;
        
    }   
};
// int main(){
//     Solution s;
//     vector<string>vec={"bab","dab","cab"};
//     vector<int> groups={1,2,2};
//     s.getWordsInLongestSubsequence(vec,groups);
// }