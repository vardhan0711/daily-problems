class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle=30*hour+(0.5)*minutes;
        double min_angle=minutes*6;
        double diff= abs(hour_angle-min_angle);
        double res=min(diff,360-diff);
        return res;
        
    }
};