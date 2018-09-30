#### [Set-Matrix-Zero](https://leetcode.com/problems/set-matrix-zeroes/)

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place. Devise a constant space solution.

##### Solution

- The idea is to find the first element in the matrix that is zero say matrix[p][q]. 
- Since the **pth** row and **qth** column need to be zero finally. We can use them as arrays to store which other rows and columns need to be set zero.

##### C++ Code

```c++
#define vi vector<int>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i,j;
        
        int memr = -1;
        int memc = -1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(matrix[i][j] == 0 and memr == -1)
                {
                    memr = i;
                    memc = j;
                }
                else if(matrix[i][j] == 0)
                {
                    matrix[memr][j] = 0;
                    matrix[i][memc] = 0;
                }
            }
        }
        if (memr != -1)
        {
            for(i=0;i<r;i++)
            {
                if(i!=memr)
                {
                    for(j=0;j<c;j++)
                    {
                        if(j!=memc)
                        {
                            if(matrix[memr][j] == 0)
                                matrix[i][j] = 0;
                            else if(matrix[i][memc] == 0)
                                matrix[i][j] = 0;
                        }
                    }
                }
            }
            
            for(int i=0;i<r;i++)
                matrix[i][memc] = 0;
            for(int i=0;i<c;i++)
                matrix[memr][i] = 0;
        }
    }
};
```