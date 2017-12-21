//Solution to Leetcode problem. Given a time, find the next closest time
class Solution {
public:
    int stepForwardOneMinute(int time)
    {
        int hours = time/100;
        int minutes = time%100;
        minutes = minutes + 1;
        if(minutes >= 60)
        {
            minutes = minutes - 60;
            hours = hours + 1;
        }
        if(hours >= 24)
        {
            hours = hours - 24;
        }
        return hours*100+minutes;
    }
    bool checkTimeValid(int time, vector<bool> allowedNumbers)
    {
        if(allowedNumbers.at(time%10) && allowedNumbers.at(time/10%10)  && allowedNumbers.at(time/100%10) &&
           allowedNumbers.at(time/1000%10))
        {
            return true;
        }
        return false;
    }
    string nextClosestTime(string time) {
        vector<bool> allowedNumbers(10,false);
        int placeVal = 1000;
        int intTime = 0;
        for(int i = 0; i < time.size(); i++)
        {
            if(i!=2)
            {
                intTime = intTime + (time.at(i) - '0')*placeVal;
                placeVal = placeVal/10;
                allowedNumbers.at(time.at(i) - '0') = true;
            }

        }
        bool timeFound = false;
        while(timeFound == false)
        {
            intTime = stepForwardOneMinute(intTime);
            if(checkTimeValid(intTime, allowedNumbers))
            {
                string minuteString = to_string(intTime%100);
                if(minuteString.size() < 2)
                {
                    minuteString.insert(0,"0");
                }
                string returnString =  to_string(intTime/100) + ":" + minuteString;
                if(returnString.size() == 4)
                {
                    returnString.insert(0,"0");
                }
                return returnString;
            }
        }
    }
};
