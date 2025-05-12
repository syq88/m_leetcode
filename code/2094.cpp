#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> res;
    unordered_set<int> use;
    int change(int a,int b,int c){
        // printf("%d,%d,%d,%d\n",a,b,c,a*100+b*10+c);
        return a*100+b*10+c;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        if(digits.size()<2)return res;
        bool flag=false;
        for(auto val:digits){
            if(val%2==0)flag=true;
        }
        if(!flag)return res;
        int size=digits.size();
        for(int i=0;i<size;++i){
            if(digits[i]%2!=0)continue;
            for(int j=0;j<size;++j){
                if(j==i)continue;
                for(int k=0;k<size;++k){
                    if(digits[k]==0||k==i||k==j)continue;
                    int p=change(digits[k],digits[j],digits[i]);
                    if(use.count(p)==0)
                    {
                        use.insert(p);
                        res.push_back(p);
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
int main(){
    Solution s;
    vector<int> digits={2,1,3,0};
    s.findEvenNumbers(digits);
}