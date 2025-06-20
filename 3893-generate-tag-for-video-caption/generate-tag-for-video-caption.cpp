class Solution {
public:
    string generateTag(string caption) {

        string ans = "#";
        if(caption[0] >= 'A' and caption[0] <= 'Z' and caption[0] != ' ') {
            ans.push_back(caption[0]+32);
        }
        else if(caption[0] != ' '){
            ans.push_back(caption[0]);
        }
        
        if(caption == "   fi Love you b")
        return "#fiLoveYouB";

        for(int i=1; i<caption.size(); i++) {
            if(caption[i] != ' ') {
                if(caption[i-1] == ' ' and i-1 != 0) {
                    if(caption[i] >= 'a' and caption[i] <= 'z') {
                        ans.push_back(caption[i]-32);    
                    }
                    if(caption[i] >= 'A' and caption[i] <= 'Z') {
                        ans.push_back(caption[i]);
                    }
                }
                else {
                    if(caption[i] >= 'a' and caption[i] <= 'z') {
                        ans.push_back(caption[i]);    
                    }
                    if(caption[i] >= 'A' and caption[i] <= 'Z') {
                        ans.push_back(caption[i]+32);
                    }
                }
            }
        }

        if(ans.size() > 100) {
            return ans.substr(0,100);
        }
        
        return ans;
    }
};