/*The Wizard
              _,._      
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
   ||                hjm
*/
class Solution {
public:
    int check(vector<int>&arr, int start,unordered_set<int>&m){
        if(start<0 || start>=arr.size()|| m.find(start)!=m.end()){
            return 0;
        }
        if(arr[start]==0){
            return 1;
        }
        m.insert(start);
        int ans=check(arr,start+arr[start],m);
        ans+=check(arr,start-arr[start],m);
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int>m;
        int ans=check(arr,start,m);
        if(ans==0){
            return false;
        }
        return true;
    }
};