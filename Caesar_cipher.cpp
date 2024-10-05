#include<bits/stdc++.h>
using namespace std;
string encrypt(string text){
    int len = text.size();
    for(int i = 0; i < len; i++){
        if(text[i] >= 'a' && text[i] <='z'){
            text[i] -= 'a';
            text[i] = (text[i] + 3) % 26;
            text[i] += 'a'; 
        }
        else if(text[i] >= 'A' && text[i] <='Z'){
            text[i] -= 'A';
            text[i] = (text[i] + 3) % 26;
            text[i] += 'A'; 
        }
    }
    return text;
}

string decrypt(string text){
    int len = text.size();
    for(int i = 0; i < len; i++){
        if(text[i] >= 'a' && text[i] <='z'){
            text[i] -= 'a';
            text[i] = ((text[i] - 3) + 26) % 26;
            text[i] += 'a'; 
        }
        else if(text[i] >= 'A' && text[i] <='Z'){
            text[i] -= 'A';
            text[i] = ((text[i] - 3) + 26) % 26;
            text[i] += 'A'; 
        }
    }
    return text;
}

int main(){
    cout<<"Enter the text : ";
    string text;
    getline(cin, text);
    string encrypted_text = encrypt(text);
    cout<<"Encrypted text is : "<<encrypted_text<<endl;

    string decrypted_text = decrypt(encrypted_text);
    cout<<"Decrypted text is : "<<decrypted_text<<endl;
}