class Spreadsheet {
public:

    vector<vector<int>> v;
    Spreadsheet(int rows) {
        v = vector<vector<int>>(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        
        int col = cell[0]-'A';
        string rowstr = cell.substr(1);
        int row = stoi(rowstr);

        v[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        string rowstr = cell.substr(1);
        int row = stoi(rowstr);

        v[row][col] = 0;
    }
    
    int getValue(string formula) {
        
        string part1;
        string part2;

        int i=1;
        while(i < formula.size() && formula[i] != '+') {
            part1.push_back(formula[i]);
            i++;
        }

        i++;
        while(i < formula.size()) {
            part2.push_back(formula[i]);
            i++;
        }

        int val1,val2;
        if(part1[0] >= 'A' && part1[0] <= 'Z') {
            int col = part1[0]-'A';
            string rowstr = part1.substr(1);
            int row = stoi(rowstr);

            val1 = v[row][col];
        }
        else {
            val1 = stoi(part1);
        }

        if(part2[0] >= 'A' && part2[0] <= 'Z') {
            int col = part2[0]-'A';
            string rowstr = part2.substr(1);
            int row = stoi(rowstr);

            val2 = v[row][col];
        }
        else {
            val2 = stoi(part2);
        }

        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */