### [Sort Colors](https://leetcode.com/problems/sort-colors/)

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

---

#### Two Pass Solution (Counting Sort) Time: O(n)

First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors_count[3]={0};
        for(int i=0;i<nums.size();i++)
            colors_count[nums[i]] ++;
        
        int i=0;
        for(int color=0;color<3;color++)
        {
            while(colors_count[color] != 0)
            {
                nums[i++] = color;
                colors_count[color] --;
            }
        }
    }
};
```

#### Single Pass Solution: Time: O(n)

Keep throwing color 0 to the beginning and color 2 to the end.

```c++
class Solution {
public:
    void swap(int &a, int &b)
    {  
        if(a != b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        
        for(int k=0;k<nums.size();k++)
        {
            while((k>=i and nums[k] == 0) || (k<=j and nums[k]==2))
            {
                if (nums[k]==0)
                    swap(nums[i++], nums[k]);
                else if(nums[k]==2)
                    swap(nums[j--], nums[k]);
            }
        }
    }
};
```

