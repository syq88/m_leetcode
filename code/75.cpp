#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k=1;
        int a=0,b=nums.size()-1;
        int i=0;
        while (i<=b)
        {
            if(nums[i]<k){
                swap(nums[i],nums[a]);
                a++;
                i++;
            }
            else if(nums[i]>k){
                swap(nums[i],nums[b]);
                b--;
            }
            else i++;
        }
        
    }
};