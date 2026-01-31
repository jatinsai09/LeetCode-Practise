class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;

        int mid, lo = 0, hi = n - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return letters[lo % n];
    }
}