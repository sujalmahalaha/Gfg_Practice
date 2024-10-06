//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int bfs(int row_number, int column_number, int row, int col, vector<vector<int>>&visited , vector<vector<char>>& grid){
        visited[row][col]=1;
        queue<pair<int,int>>bfs_queue;
        bfs_queue.push({row, col});
        
        while(!bfs_queue.empty()){
            //extracting the elements
            int curr_row = bfs_queue.front().first;
            int curr_col = bfs_queue.front().second;
            bfs_queue.pop();
            
            // checking for nearest element left,right,up and down + diagonally direction ( total = 8 direction)
            // when i = 0 and j = 0 the if statement will be false showing the current position so at max the below code execute for only 
            // 8 times
            for(int i = -1 ; i <=1 ; i++){
                for (int j = -1 ; j<=1 ; j++){
                    int del_row = curr_row + i;
                    int del_col = curr_col + j;
                    
                    if(del_row >= 0 && del_row < row_number  && del_col >= 0 && del_col < column_number 
                    && visited[del_row][del_col] == 0 && grid[del_row][del_col] == '1'){
                       visited[del_row][del_col] =1;
                       bfs_queue.push({del_row, del_col});
                    } 
                }
            }
        }
    }
    
    // main function
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        //getting size of grid
        int row_number = grid.size();
        int column_number = grid[0].size();
        //creating grid for track the visited and unvisited element
        vector<vector<int>> visited(row_number, vector<int> ( column_number , 0 ));
        int count = 0 ;
        
        for(int i = 0 ; i< row_number ; i++){
            for(int j = 0 ; j<column_number ; j++){
                // checking if element is not visited and part of a island
                if(visited[i][j]==0  && grid[i][j] =='1' ){
                    bfs(row_number, column_number, i,j, visited,grid);
                    count++;
                }
            }
        }
        return count++;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends