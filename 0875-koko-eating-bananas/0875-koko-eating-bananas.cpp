class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            long long hours = 0;        
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + (long long)mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;
                end = mid - 1;         
            } else {
                start = mid + 1;    
            }
        }

        return ans;
    }
};