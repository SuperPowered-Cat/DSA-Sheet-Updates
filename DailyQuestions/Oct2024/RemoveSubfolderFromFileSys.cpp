// leetcode 1233

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // sorting lexicographically
        sort(folder.begin(), folder.end());
        vector<string> cleanfolder; // ans folder
        cleanfolder.push_back(folder[0]); // first elemeent always added as smallest folder

        // checking for each element aside from 1st
        for (int i = 1; i < folder.size(); i++) {
            string currfolder = cleanfolder.back(); // using last element as refernce
            
            if (folder[i].size() >= currfolder.size() + 1) { 
            // next element should be greater to be able to be a subfolder
                
                if (folder[i].substr(0, currfolder.size() + 1) == currfolder + "/") 
                // if its length is more and its the previous element + / then subfolder    
                    
                    continue; // so we will not add
            }
            cleanfolder.push_back(folder[i]); // otherwise we will add
            // so adding if the next elements length is shorter
            // or if length is longer, iots not a subfolder
        }

        return cleanfolder; 
    }
};
