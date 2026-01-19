class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), swaps = 0;
        vector<int> pos(n);

        // Map each person to their seat number (position)
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        // Process each pair of seats
        for (int i = 0; i < n; i += 2) {
            int f = row[i]; // first person
            int got = row[i + 1]; // Present partner of first person (second person)
            int req = f ^ 1; // Required partner of first person 

            if (req != got) {
                swaps++;
                int partnerIndex = pos[req];

                // Swap second person with the required partner
                swap(row[i + 1], row[partnerIndex]);

                // Update the positions after swap
                pos[req] = i + 1;
                pos[got] = partnerIndex;
            }
        }

        return swaps;
    }
};