class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        
        double kelvin = celsius + 273.15;
        double farenhit = celsius * 1.80 + 32.00;

        return {kelvin,farenhit};
    }
};