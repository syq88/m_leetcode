#include <bits/stdc++.h>
#define  lson (id<<1)
#define rson ((id<<1)+1)
using namespace std;
const int N = 1e5 + 10;
struct segment {
    int l, r;
    int mmax;
    int lazy;
}tree[N << 2];

void pushup(int id) {
    tree[id].mmax = max(tree[lson].mmax, tree[rson].mmax);
    return;
}
void buildtree(int l, int r, int id, vector<int>& nums) {
    tree[id].l = l, tree[id].r = r;
    if (l == r) {
        tree[id].mmax = nums[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(l, mid, lson, nums);
    buildtree(mid + 1, r, rson, nums);
    pushup(id);
    return;

}
void pushdown(int id) {
    tree[lson].mmax -= tree[id].lazy;
    tree[rson].mmax -= tree[id].lazy;
    tree[lson].lazy += tree[id].lazy, tree[rson].lazy += tree[id].lazy;
    tree[id].lazy = 0;
    return;
}
void modify(int id, int L, int R, int val) {
    int l = tree[id].l, r = tree[id].r;
    if (l>=L && r <= R) {
        tree[id].mmax -= val;
        tree[id].lazy += val;
        return;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if (mid >= L)modify(lson, L, R, val);
    if (mid < R)modify(rson, L, R, val);
    pushup(id);
    return;
}
class Solution {
public:

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        buildtree(0, n - 1, 1, nums);
        if (tree[1].mmax <= 0)return 0;
        for (int i = 0;i < queries.size();++i) {
            modify(1, queries[i][0], queries[i][1], queries[i][2]);
            if (tree[1].mmax <= 0)return i + 1;
        }
        return -1;
    }
};
int main(){
    Solution s;
  vector<int> nums = { 10,3 };
vector<vector<int>> queries = { {1, 1, 3}, {1, 1, 2}, {1, 1, 1}, {0, 1, 2} };
cout<<s.minZeroArray(nums, queries);

}