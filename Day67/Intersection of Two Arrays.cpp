class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> visited;    
        vector<int> ans;
        
        for(int i = 0;i<nums1.size();i++){
            visited[nums1[i]] = true;   
        }
        
        for(int j = 0;j<nums2.size();j++){   
            if(visited[nums2[j]]){     
                ans.push_back(nums2[j]);
                visited[nums2[j]] = false;      
            }   
        }
        
        return ans;
    }
};
