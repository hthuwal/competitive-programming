/* -------------------------------------------------------------------------- */
/*   https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor   */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

#define M 1000000007

class Solution {
   public:
    int numberOfWays(string corridor) {
        int seatCountInCurrentSection = 0;
        int possibleValues = 0;
        
        long ans = 0;
        for (int i = 0; i < corridor.size(); i++) {    
            
            // If the current section already has 2 seats
            if (seatCountInCurrentSection == 2) {
      
                // We can place a divider before current element (plant or seat)
                possibleValues++;

                // If this is a seat, the current section must end before this and we can start a new section
                if (corridor[i] == 'S') {
                    
                    ans = (ans == 0) ? possibleValues: (ans * possibleValues) % M;

                    // Reset the current section
                    seatCountInCurrentSection = 1;
                    possibleValues = 0;
                }

            } else if (corridor[i] == 'S') {
                seatCountInCurrentSection++;
            }
        }

        //  If the last section has 1 seat, this is invalid
        if (seatCountInCurrentSection == 1) {
            return 0;
        }
        
        // Edge case when there is only one section
        if (seatCountInCurrentSection == 2 && ans == 0) {
            ans = 1;
        }

        return ans;
    }
};
