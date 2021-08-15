#include<iostream>
#include<vector>
#include<string.h>


#define _USE_MATH_DEFINES
using namespace std;



bool neighbors (string s){
    bool flag = false;
    string alphabet("abcdefghijklmnopqrstuvwxyz");
    int n_al = alphabet.size();
    int n_s = s.size();
    for (int i=0; i<n_al; i++){
      for (int j=0; j<n_s; j++){
          if ((alphabet[i]==s[j]) && (alphabet[i+1]==s[j+1]) ){
              flag = true;
          }

        }
    }
    return flag;
}


int main() {
    cout << boolalpha << neighbors("hsgafkroduitjsla") << endl;
    cout << boolalpha << neighbors("krstuoinnaqwlp") <<  endl;
}