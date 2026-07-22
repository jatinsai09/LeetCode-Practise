class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<string> res;

        string temp = "";
        for (int i = 0; i < n; i++) {
            int j = i; // pointer that will move

            // run the pointer until the range breaks
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            if (j > i) { // when the range has more than one element
                temp = to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            } else { // only one element as range
                temp += to_string(nums[i]);
            }

            res.push_back(temp); // push one possible answer
            temp = "";           // reinitialize for new possible answers
            i = j;               // for fresh start
        }
        return res;
    }
};