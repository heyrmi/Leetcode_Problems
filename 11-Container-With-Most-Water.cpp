// { TC: O(n), SC: O(1) }

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;                              //initially 0 unit water is there
        int i=0, j=height.size()-1;                 //first and last index
        while(i<j){                                 //traverse until index go past each other
            int h = min(height[i], height[j]);      //find min height on both index
            water = max(water, (j-i)*h);            //find max water stored
            while(height[i] <= h && i<j) i++;       //if element on i is less than height(which itelf is min) then increase i
            while(height[j] <= h && i<j) j--;       //if element on j is less than height(which itelf is min) then decrease j
        }                                           //basically we are finding the next less element
        return water;                               // return water which in this case will be the max 
    }
};


//in this approach we check by going trough the max-index-gap to min-index-gap