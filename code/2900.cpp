#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int num0=0,num1=0;
    vector<string> a,b;
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        for(int i=0;i<groups.size();++i){
            if(groups[i]){
                if(num0+1>num1){
                    num1=num0+1;
                    a.push_back(words[i]);
                    b=a;
                    a.pop_back();
                }
            }
            else{
                if(num1+1>num0){
                    num0=num1+1;
                    b.push_back(words[i]);
                    a=b;
                    b.pop_back();
                }
            }
        }
        if(num0>num1)return a;
        else return b;
    }
};
int main(){
    vector<int> t={1};
    vector<string> s={"d"};
    Solution p;
    p.getLongestSubsequence(s,t);
}