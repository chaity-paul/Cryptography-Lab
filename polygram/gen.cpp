#include <bits/stdc++.h>
using namespace std;

string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(){
    int n = (int) A.size();
    vector<string> comb_3, comb_2, comb_1;

    for(int i = 0; i < n; i++){
            string block = "";
            block += A[i];
            comb_1.push_back(block);
        for(int j = 0; j < n; j++){
            
            block = "";
            block += A[i];
            block += A[j];
            comb_2.push_back(block);
            
            for (int k = 0; k < n; k++){
                
                block = "";
                block += A[i];
                block += A[j];
                block += A[k];
                comb_3.push_back(block);
            }
        }
    }

    int len_1 = comb_1.size();
    for(int i = 0 ; i < len_1; i++){
        cout << comb_1[i] << " " << comb_1[len_1 - 1 - i] << " ";
    } 

    int len_2 = comb_2.size();
    for(int i = 0 ; i < len_2; i++){
        cout << comb_2[i] << " " << comb_2[len_2 - 1 - i] << " ";
    } 
    int len_3 = comb_3.size();
    for(int i = 0 ; i < len_3; i++){
        cout << comb_3[i] << " " << comb_3[len_3 - 1 - i] << " ";
    } 

    return 0;
}