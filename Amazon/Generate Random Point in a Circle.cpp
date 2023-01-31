class Solution {
public:
    double rad;
    double x;
    double y;
    double pi = 3.14;
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        x = x_center;
        y = y_center;
    }
    double getrandom() {
        return rand()/(double)RAND_MAX;
    }
    
    vector<double> randPoint() {
        double theta = getrandom() * 2 * pi;
        double len = sqrt(getrandom()) * rad;
        double newx = x + len * cos(theta);
        double newy = y + len * sin(theta);
        return {newx,newy};
    }
};