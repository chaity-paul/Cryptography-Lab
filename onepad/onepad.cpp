#include <bits/stdc++.h>
using namespace std;

string get_key(){
    freopen("key.txt", "r", stdin);
    string key;
    cin >> key;
    return key;
}
string encrypt(string plain_text, string key){
    string cipher_text;
    int len = (int) plain_text.size();

    for(int i = 0; i < len; i++){
        char ch = plain_text[i];
        if(islower(ch)){
            int c = ch - 'a' + key[i] - 'A';
            c %= 26 ;
            ch = c + 'a';
            cipher_text += ch;
        }else if(isupper(ch)){
            int c = ch - 'A' + key[i] - 'A';
            c %= 26 ;
            ch = c + 'A';
            cipher_text += ch;
        }else {
            cipher_text += ch;
        }
    }

    return cipher_text;
}


string decrypt(string cipher_text, string key){
    string plain_text;
    int len = (int) cipher_text.size();

    for(int i =0; i < len; i++){
        char ch = cipher_text[i];
        if(islower(ch)){
            int c = ch - 'a' - (key[i] - 'A');
            c %= 26;
            c += 26;
            c%= 26;
            ch = c + 'a';
            plain_text += ch;
        }else if(isupper(ch)){
             int c = ch - 'A' - (key[i] - 'A');
            c %= 26;
            c += 26;
            c%= 26;
            ch = c + 'A';
            plain_text += ch;
        }else{
            plain_text += ch;
        }
    }
    return plain_text;
}

int main(){

    string plain_text = "Chaity hates me.";
    string key = "AVKLUKGFDTHKUFGHLKJ"; // key = get_key();

    string cipher_text = encrypt(plain_text, key);
    string original_text = decrypt(cipher_text, key);

    cout << cipher_text << endl;
    cout << original_text << endl;


    return 0;

}