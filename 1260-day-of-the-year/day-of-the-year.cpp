class Solution {
public:
    int dayOfYear(string date) {

        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

        int c = 0;

        for(int i = 1; i < m; i++) {   // ❗ only till previous month
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                c += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11) {
                c += 30;
            } 
            else if(i == 2) {
                if(leap) c += 29;
                else c += 28;
            }
        }

        c += d;
        return c;
    }
};