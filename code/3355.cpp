#include <bits/stdc++.h>
using namespace std;
const int  N=1e5+10;
class Solution {
public:
    int a[N];
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size=nums.size();
        memset(a,0,sizeof(0));
        for(auto val:queries){
            int l=val[0],r=val[1];
            a[l]++;
            if(r!=size-1)a[r+1]--;
        }
        int sum=0;
        for(int i=0;i<size;++i){
            sum+=a[i];
            if(sum<nums[i])return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,0,1};
    vector<vector<int>> queries={{0,2}};
s.isZeroArray(nums,queries);
}