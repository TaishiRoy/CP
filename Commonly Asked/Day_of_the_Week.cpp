

// Day of the Week
// Given a date, return the corresponding day of the week for that date.
// more at https://leetcode.com/problems/day-of-the-week/
// (Tomohiko Sakamoto’s Algorithm.)

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
            static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
            y -= m < 3;
            int day = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
            if(day==0)  return "Sunday";
            if(day==1)  return "Monday";
            if(day==2)  return "Tuesday";
            if(day==3)  return "Wednesday";
            if(day==4)  return "Thursday";
            if(day==5)  return "Friday";
            else  return "Saturday";
    }
};
