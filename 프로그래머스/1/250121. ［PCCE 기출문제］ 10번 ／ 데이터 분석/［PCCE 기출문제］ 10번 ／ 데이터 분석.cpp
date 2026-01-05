#include <string>
#include <vector>

#include <algorithm>

using namespace std;

struct Data
{
    int code;
    int date;
    int maximum;
    int remain;
};

bool sort_by_code(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

bool sort_by_date(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

bool sort_by_maximum(const vector<int>& a, const vector<int>& b)
{
    return a[2] < b[2];
}

bool sort_by_remain(const vector<int>& a, const vector<int>& b)
{
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<Data> dataList;
    dataList.resize(data.size());
    for (int i = 0; i < data.size(); ++i)
    {
        dataList[i].code = data[i][0];
        dataList[i].date = data[i][1];
        dataList[i].maximum = data[i][2];
        dataList[i].remain = data[i][3];
    }
    
    for (auto& d : dataList)
    {
        bool isAddable = false;
        if (ext == "code")
        {
            isAddable = (d.code < val_ext);
        }
        else if (ext == "date")
        {
            isAddable = (d.date < val_ext);
        }
        else if (ext == "maximum")
        {
            isAddable = (d.maximum < val_ext);
        }
        else if (ext == "remain")
        {
            isAddable = (d.remain < val_ext);
        }
        
        if (isAddable)
        {
            vector<int> addData(4);
            addData[0] = d.code;
            addData[1] = d.date;
            addData[2] = d.maximum;
            addData[3] = d.remain;
            
            answer.push_back(addData);
        }
    }
    
    if (sort_by == "code")
    {
        sort(answer.begin(), answer.end(), sort_by_code);
    }
    else if (sort_by == "date")
    {
        sort(answer.begin(), answer.end(), sort_by_date);
    }
    else if (sort_by == "maximum")
    {
        sort(answer.begin(), answer.end(), sort_by_maximum);
    }
    else if (sort_by == "remain")
    {
        sort(answer.begin(), answer.end(), sort_by_remain);
    }
    
    return answer;
}