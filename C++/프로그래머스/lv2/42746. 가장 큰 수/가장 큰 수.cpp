#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    for(int i=0; i<numbers.size(); i++){
        tmp.push_back(to_string(numbers[i]));
    }
    
    sort(tmp.begin(), tmp.end(), compare);
    
    if (tmp.at(0) == "0") return "0";
    
    for(int i=0; i<tmp.size(); i++){
        answer += tmp[i];
    }
    
    return answer;
}