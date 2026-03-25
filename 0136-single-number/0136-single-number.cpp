class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int> f;
	   for(auto& x: nums) {
		   f[x]++;
       }

	   for(auto& it: f) {
		   if(it.second == 1) {
			   return it.first;
           }
       }
       
	   return -1;
    }
};