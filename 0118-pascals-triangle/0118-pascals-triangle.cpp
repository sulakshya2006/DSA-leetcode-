class Solution {
public:
vector<int>generaterows(int row){
    long long ans=1;
    vector<int> ansrow;
    ansrow.push_back(1);
    for(int i=1;i<=row;i++){
        ans = ans *(row-i+1);
        ans=ans/i;
        ansrow.push_back(ans);
    }
    return ansrow;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(generaterows(i));
        }
        return ans;
    }
};