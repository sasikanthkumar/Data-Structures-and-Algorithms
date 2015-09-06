#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n;  // number of records
    int m;  // number of attributes
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    
    vector<string> attr_names(m);
    
    map<string,int> *attr_values = new map<string,int>[m];
    //attr_values[0].insert(pair<string,int>("sss",1));
    string temp_line;
    string temp;
    char ch;
    int line_length = 0;
    int start = 0;
    for (int i = 0; i<m; i++) {
        cin >> attr_names[i];
        scanf("%c",&ch);
        getline(cin,temp_line);
        line_length = temp_line.length();
        start = 0;
        //cout << temp_line << endl;
        //cout << temp_line.substr(6,12) <<endl;
        int key = 1;
        for (int j = 0; j<line_length; j++) {
            
            if (temp_line[j] == ' ' || j == line_length-1) {
                if (temp_line[j] == ' ') {
                    //cout << j << start <<endl;
                    temp = temp_line.substr(start,j-start);
                    start = j+1;
                    //cout << temp <<endl;
                    attr_values[i].insert(pair<string,int>(temp,key));
                    key++;
                }else{
                    //cout << j << start<< endl;
                    temp = temp_line.substr(start,j-start+1);
                    //cout << temp << endl;
                    attr_values[i].insert(pair<string,int>(temp,key));
                    key++;
                }
            }
        }
    }
    
    
    /**
    map<string,int>::iterator it;
    for (int i = 0; i<attr_names.size(); i++) {
        for (it = attr_values[i].begin(); it != attr_values[i].end(); it++) {
            cout << it->first << " " << it->second <<endl;
        }
    }
    **/
    
    set<vector<int> > specific_boundary,generic_boundary;
    vector<int> curr_data;
    curr_data.clear();
    for (int i = 0; i<(m-1); i++) {
        curr_data.push_back(0);
    }
    specific_boundary.insert(curr_data);
    curr_data.clear();
    for (int i = 0; i<(m-1); i++) {
        curr_data.push_back(-2);
    }
    generic_boundary.insert(curr_data);
    curr_data.clear();
    
    
    string curr_trng_exmp;
    for(int i = 0; i<n; i++) {
        curr_data.clear();
        getline(cin,curr_trng_exmp);
        line_length = curr_trng_exmp.length();
        start = 0;
        int attr_index = 0;
        for (int j = 0; j<line_length; j++) {
            if (curr_trng_exmp[j] == ' '|| j == line_length-1) {
                if (curr_trng_exmp[j] == ' ') {
                    temp = curr_trng_exmp.substr(start,j-start);
                    start = j+1;
                    //cout << temp <<endl;
                    curr_data.push_back(attr_values[attr_index][temp]);
                    attr_index++;
                }else{
                    temp = curr_trng_exmp.substr(start,j-start+1);
                    curr_data.push_back(attr_values[attr_index][temp]);
                    attr_index++;
                }
            }
        }
        //printing curreent data
        
        for (int k = 0; k<curr_data.size(); k++) {
            cout << curr_data[k] << " ";
        }
        cout << endl;
        
        vector<int> first_step;
        first_step.clear();
        if(curr_data.back() == attr_values[m-1]["Yes"]){    //positive example
            // removing from generic border any hypothesis inconsistent with the given training example
            for (set<vector<int> >::iterator it = generic_boundary.begin(); it != generic_boundary.end() ; it++) {
                first_step = *it;
                int flag = 0;
                for (int j = 0; j<(m-1); j++) {
                    if (first_step[j] != curr_data[j] && first_step[j] != -2) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    generic_boundary.erase(first_step);
                }
                first_step.clear();
            }
            
            
            
        }else{          // negative example
            //cout << "Negative example" <<endl;
            //removing from specfic border any hypothesis inconsistent with given training example
            for (set<vector<int> >::iterator it = specific_boundary.begin(); it != specific_boundary.end() ; it++) {
                first_step = *it;
                int flag = 0;
                for (int j = 0; j<(m-1); j++) {
                    if (first_step[j] == 0 || ((first_step[j] != curr_data[j])&&(first_step[j] != -2))) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    specific_boundary.erase(first_step);
                }
                first_step.clear();
            }
            
            
            
            
        }
        
    }
    
    
    
    return 0;
}