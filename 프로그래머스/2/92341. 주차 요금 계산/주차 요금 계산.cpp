#include <string>
#include <vector>

#include <map>
#include <cmath>
#include <iostream>

using namespace std;

struct Record
{
    string time;
    int fee;
    bool isIn;
    int totalTime;
    
    Record()
    {
        time = "";
        fee = 0;
        isIn = false;
        totalTime = 0;
    }
    
    Record(string t, bool in)
    {
        time = t;
        fee = 0;
        isIn = in;
        totalTime = 0;
    }
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    //   car    Record
    map<string, Record> mCar;
    for (auto& r : records)
    {
        string time = r.substr(0, 5);
        bool isIn = r.substr(11) == "IN" ? true : false;
        string carNum = r.substr(6, 4);
        
        if (isIn)
        {
            auto iter = mCar.find(carNum);
            if (iter == mCar.end())
            {
                mCar[carNum] = Record(time, true);
            }
            else
            {
                mCar[carNum].time = time;
                mCar[carNum].isIn = true;
            }
        }
        else
        {
            int inH = stoi(mCar[carNum].time.substr(0, 2));
            int inM = stoi(mCar[carNum].time.substr(3, 2));
            
            int inTimeToMin = inH * 60 + inM;
            
            int outH = stoi(time.substr(0, 2));
            int outM = stoi(time.substr(3, 2));
            
            int outTimeToMin = outH * 60 + outM;
            
            int total = outTimeToMin - inTimeToMin;
            
            mCar[carNum].totalTime += total;
            mCar[carNum].isIn = false;
        }
    }
    
    answer.resize(mCar.size());
    int idx = 0;
    for (auto iter = mCar.begin(); iter != mCar.end(); ++iter)
    {
        if (iter->second.isIn)
        {
            int inH = stoi(iter->second.time.substr(0, 2));
            int inM = stoi(iter->second.time.substr(3, 2));
            
            int inTimeToMin = inH * 60 + inM;
            
            int outH = 23;
            int outM = 59;
            
            int outTimeToMin = outH * 60 + outM;
            
            int total = outTimeToMin - inTimeToMin;
            iter->second.totalTime += total;
        }
        
        iter->second.fee += fees[1];
        iter->second.totalTime -= fees[0];

        int count = ceil((float)iter->second.totalTime / (float)fees[2]);
        count = count < 0 ? 0 : count;
        iter->second.fee += fees[3] * count;
        
        answer[idx] = iter->second.fee;
        ++idx;
    }
    
    return answer;
}