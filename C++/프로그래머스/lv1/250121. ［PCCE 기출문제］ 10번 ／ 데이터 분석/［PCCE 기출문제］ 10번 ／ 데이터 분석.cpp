#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int col;

bool compare(const vector<int>& a, const vector<int>& b){
    return a[col] < b[col];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    
    // Variable Setting
    
    int i, j;
    vector<vector<int>> answer;
    int ext_label;
    int sort_label;
    vector<int> filter;
    
    // Label Setting
    if(ext == "code"){
        ext_label = 0;
    }
    else if(ext == "date"){
        ext_label = 1;
    }
    else if(ext == "maximum"){
        ext_label = 2;
    }
    else if(ext == "remain"){
        ext_label = 3;
    }
    
    if(sort_by == "code"){
        sort_label = 0;
    }
    else if(sort_by == "date"){
        sort_label = 1;
    }
    else if(sort_by == "maximum"){
        sort_label = 2;
    }
    else if(sort_by == "remain"){
        sort_label = 3;
    }
    
    // Val_Ext 제거
    
    if(ext_label == 1){
        for(i=0; i<data.size(); i++){
            if(data[i][ext_label] < val_ext) continue;
            else filter.push_back(i);
        }
    }
    else{
        for(i=0; i<data.size(); i++){
            if(data[i][ext_label] < val_ext) continue;
            else{
                filter.push_back(i);
            }
        }
    }
    
    // Filter
    bool tf=0;
    col = sort_label;
    for(i=0; i<data.size(); i++){
        for(j=0; j<filter.size(); j++){
            if(i == filter[j]) tf=1;
        }
        if(tf==1) {
            tf = 0;
            continue;
        }
        else{
            answer.push_back(data[i]);
        }
    }
    
    // Sort
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}