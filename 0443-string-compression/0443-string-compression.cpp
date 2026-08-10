class Solution {
public:
    int compress(vector<char>& chars) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = chars.size(), idx = 0;
        for (int i = 0; i < n;) {
            char ch = chars[i];
            int count = 0;
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }
            
            chars[idx++] = ch;
            if (count > 1) {
                for (const auto& c : to_string(count)) {
                    chars[idx++] = c;
                }
            }
        }
        return idx;
    }
};