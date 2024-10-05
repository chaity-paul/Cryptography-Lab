#include <bits/stdc++.h>
using namespace std;

string encrypt(string plain_text, int width){
    string cipher_text = "";

    int len = (int) plain_text.size();
    vector<string> matrix(width);
    for(int i = 0; i < len; i++){
        matrix[i % width] += plain_text[i];
    }
    for(auto it: matrix){
        cipher_text += it;
    }
    return cipher_text;
}

string decrypt(string cipher_text, int width){
    int len = (int) cipher_text.size();
    int extra = len % width;
    int ind = 0;
    int number_of_row = len / width;
    vector<string> matrix(width);
    for(int col = 0; col < extra; col++){
        for(int i = 0; i <= number_of_row; i++){
            matrix[col] += cipher_text[ind++];
        }
        // cout << matrix[col] << endl;
    }
    for(int col = extra; col < width; col++){
         for(int i = 0; i < number_of_row; i++){
            matrix[col] += cipher_text[ind++];
        }
        // cout << matrix[col] << endl;
    }

    string plain_text = "";

    for(int i = 0; i <= number_of_row; i++){
        for(auto it : matrix){
            if((int)it.size() > i){
                plain_text += it[i];
            }
        }
    }
    return plain_text;
}


int main(){
    string plain_text = "abcdef";
    string cipher_text = encrypt(plain_text, 5);
    string original_text = decrypt(cipher_text, 5);

    cout << cipher_text << endl;
    cout << original_text << endl;

    return 0;
}