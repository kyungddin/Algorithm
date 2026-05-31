#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    // Variable Setting
    vector<int> answer;
    string t_year;
    string t_month;
    string t_day;
    int t_year_i;
    int t_month_i;
    int t_day_i;
    int combine_today;
    
    unordered_map<char, int> map1;
    char type;
    int tmp;
    
    string date;
    string year;
    string month;
    string day;
    int year_i;
    int month_i;
    int day_i;
    int combine_date;
    char term_type;
    
    int i, j, k;
    
    // Today Parsing
    t_year = today.substr(0, 4);
    t_month = today.substr(5, 2);
    t_day = today.substr(8, 2);
    t_year_i = stoi(t_year)*336;
    t_month_i = stoi(t_month)*28;
    t_day_i = stoi(t_day);
    combine_today = t_year_i + t_month_i + t_day_i;
    
    // Terms mapping
    for(i=0; i<terms.size(); i++){
        istringstream ss(terms[i]);
        
        ss >> type >> tmp;
        
        map1[type] = tmp;
    }
    
    // Main Logic
    
    for(i=0; i<privacies.size(); i++){
        istringstream ss(privacies[i]);
        ss >> date >> term_type;
        
        year = date.substr(0, 4);
        month = date.substr(5, 2);
        day = date.substr(8, 2);
        year_i = stoi(year)*336;
        month_i = stoi(month)*28;
        day_i = stoi(day);
        combine_date = year_i + month_i + day_i;
        
        combine_date += (map1[term_type]*28);
        cout << combine_today << endl;
        cout << combine_date << endl;
        
        if(combine_today >= combine_date) answer.push_back(i+1);
    }
    
    
    return answer;
}