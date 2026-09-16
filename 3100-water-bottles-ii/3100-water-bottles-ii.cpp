class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles, emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            
            res++;
            emptyBottles++;

            numExchange++;
        }

        return res;
    }
};