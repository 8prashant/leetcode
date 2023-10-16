 /*             _,._      
  .||,       /_ _\\     
 \.`',/      |'L'| |    
 = ,. =      | -,| L    
 / || \    ,-'\"/,'`.   
   ||     ,'   `,,. `.  
   ,|____,' , ,;' \| |  
  (3|\    _/|/'   _| |  
   ||/,-''  | >-'' _,\\ 
   ||'      ==\ ,-'  ,' 
   ||       |  V \ ,|   
   ||       |    |` |   
   ||       |    |   \  
   ||       |    \    \ 
   ||       |     |    \
   ||       |      \_,-'
   ||       |___,,--")_\
   ||         |_|   ccc/
   ||        ccc/       
   ||                hjm*/
class Solution {
public:
    void check(vector<vector<int>>& image,int x,int y , int a,int color){
        if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=a){
            return;
        }
        image[x][y]=color;
        check(image,x-1,y,a,color);
        check(image,x+1,y,a,color);
        check(image,x,y-1,a,color);
        check(image,x,y+1,a,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        int a=image[sr][sc];
        check(image,sr,sc,a,color);
        return image;
    }
};