class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();                        //size of nums
        if(n == 0) return -1;                       //if size is 0 return -1
        int low = 0, high = n-1;                    //define low and high
        int first = nums[0];                        //take first value for reference
        bool to_find = target >= first;             //check if target is greater than first  
        
        while(low <= high){                         //while they do not match
            int mid = (low + high) /2;              //find mid
            int value = nums[mid];                  //store mid index elemnt in value
            if(value == target){                    //check if mid element is target
                return mid;                         //if true retun mid index
            }
            
            bool is_big = value >= first;           //check if value is greater than first
              
            
            if(is_big == to_find)                   //both on the "greater" size
                if(value < target)                  //check target greater than value
                    low = mid+1;                    //check on left of left side
                else                                //check value greater than the target
                    high = mid-1;                   //check on the right of left side
            else                                    //both on the "opposition" size
                if(is_big)                          //if value is greater but target is not
                    low = mid+1;                    //search on right of left side
                else                                //if value is also on the left side of left side eith target
                    high = mid-1;                   //search on the right of right side 
            
        }
        return -1;
    }
};


/* eg 
Target = 3
num = {4,5,6,7,8,0,1,2,3}

1. First                                            //first = 4 
2. Target >= first                                  //false
3. value                                            //value = 8
4. is_big                                           //fasle

as 3 is smaller than value it will go to first else
then last else will be executed because 3 is the extreme right.