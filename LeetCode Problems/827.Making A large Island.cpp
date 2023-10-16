class Solution {
public:
int dfs(int i, int j, vector<vector<int>> &grid, int & color,int rows,int cols)
{      
    if(i < 0 || j < 0 || i >= rows || j >= cols)//invalid case
         return 0;
    
    if(grid[i][j] == 0 || grid[i][j] ==  color)//invalid case
         return 0;
    
    grid[i][j] = color;//just assign the value of color to all adjacent 1's of grid and increment the count everytime
    
    int count = 1;
    count += dfs(i + 1, j, grid,color,rows,cols);
    count += dfs(i - 1, j , grid,color,rows,cols);
    count += dfs(i, j + 1, grid,color,rows,cols);
    count += dfs(i, j - 1, grid,color,rows,cols);
    
    return count;
}


int largestIsland(vector<vector<int>>& grid) 
{
    int rows=grid.size();
    int cols=grid[0].size();
    
    int color = 2;//after visiting any 1, we change that one by color val and then move to its adjacent element, when their is no adjacent increment the color val
    
    unordered_map<int,int>mp;
    
     for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 1)
            {
                int count = dfs(i, j, grid,color,rows,cols);//insert the value of particular area in map with its 1's count
                    mp[color] = count;
                    color++;
                 
            }
        }
    }
    //Now we are changing one 0 to 1 and checking for every case and find max island with 1's
    int result=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]==0)
            {
                set<int> st;//here i use set because we want to store connected values of different color counts,checking all the adjacent values
                
                if(i-1>=0 && grid[i-1][j]!=0)
                {
                    st.insert(grid[i-1][j]);
                }
                if(i+1<rows && grid[i+1][j]!=0) 
                {
                    st.insert(grid[i+1][j]);
                }
                if(j-1>=0 && grid[i][j-1]!=0) 
                {
                    st.insert(grid[i][j-1]);
                }
                if(j+1<cols && grid[i][j+1]!=0) 
                {
                    st.insert(grid[i][j+1]);
                }
                
                int sum = 1;
                for(auto i:st)
                    sum += mp[i];
                
                result = max(result, sum);
                
            }
        }
    }
    return result==0?(rows*cols):result; 
}
};