#include <bits/stdc++.h>
using namespace std;

map<string, string> encoder, decoder;
string get_val(string str){
    string output = "";
    for(char ch : str){
        if(isalnum(ch)) output += ch;
    }
    return output;
}

void set_encoder_decoder(){
    freopen("cipher.txt", "r", stdin);
    
    string x, y;
    // cin.ignore();
    while (cin >> x >> y)
    {
        x = get_val(x);
        y = get_val(y);
        encoder[x] = y;
        decoder[y] = x;
    }
    
}

string encrypt(string plain_text){
    int len = (int) plain_text.size();

    string cipher_text = "";
    for(int i = 0; i < len; i+= 3){
        string block = plain_text.substr(i, 3);
        cipher_text += encoder[block];
    }
    return cipher_text;
}
string decrypt(string cipher_text){
    int len = (int) cipher_text.size();
    string plain_text = "";

    for(int i = 0; i < len; i += 3){
        string block = cipher_text.substr(i, 3);
        plain_text += decoder[block];
    }
    return plain_text;
}


int main(){
    set_encoder_decoder();
    string plain_text = "KAMOLKUMARPAUL";
    string cipher_text = encrypt(plain_text);
    string original_text = decrypt(cipher_text);
    cout << cipher_text << endl;
    cout << original_text << endl;

}