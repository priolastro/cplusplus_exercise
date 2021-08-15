// Ordinær eksamen 1. juni 2018
// Task 1 - programming in C ++ (estimated time consumption 60 minutes)

#include<iostream>
#include<vector>

#define _USE_MATH_DEFINES
using namespace std;


class Country {
    string country;
    public:
        Country(string country_in): country(country_in) {}
};

class Coin {
    Country Count;
    double CatalogueNumber;
    double YearIssued;
    string Motive;
    double FaceValue;
    double Value;
    public:
        Coin(const Country Cout_in, double CatalogueNumber_in, double YearIssued_in, string Motive_in, double FaceValue_in, double Value_in):Count(Cout_in), CatalogueNumber(CatalogueNumber_in), YearIssued(YearIssued_in), Motive(Motive_in), FaceValue(FaceValue_in), Value(Value_in) {}
        
        double get_value (){
            return Value;
        };
        double get_YearIssued (){
            return YearIssued;
        };
        void changeValue(double amount){
            Value=Value + amount;
        };
};

class CoinCollection {
    public:
        vector<Coin> Array;
        CoinCollection(vector<Coin>& Array_in):Array(Array_in) {};
    void addCoin(Coin c){
        Array.push_back(c);
    }
    double getTotalValue(){
        double total_value;
        for (int i=0; i<Array.size()+1; i++){
            total_value += Array[i].get_value();
        }
        return total_value;
    }
    double getTotalValueDecade(int decade){
        double total_value_decade;
        for (int i=0; i<Array.size()+1; i++){
            int year = Array[i].get_YearIssued()/10;
            if (year == decade){
                total_value_decade += Array[i].get_value();
            }        
        };
        return total_value_decade;
    }

    // double getTotalValueDecade()

};



int main() {
    vector<Coin> Array;
    CoinCollection coinC(Array);
    Country d("Denmark");
    Coin c1(d, 12, 1953, "Frederik 9.", 2, 23);    
    coinC.addCoin(c1);
    Coin c2(d, 12, 1945, "Christian 10.", 1, 38);
    coinC.addCoin(c2);
    Coin c4(d, 12, 1988, "Margrethe 2.", 10, 15);
    coinC.addCoin(c4);
    Coin c5(d, 12, 1999, "Margrethe 2.", 20, 24);
    coinC.addCoin(c5);
    Coin c6(d, 12, 1948, "Frederik 9.", 1, 56);
    coinC.addCoin(c6);
    Coin c3(d, 12, 1965, "Frederik 9.", 5, 17);
    c3.changeValue(-5);
    coinC.addCoin(c3);

    cout << "Total value:    "      << coinC.getTotalValue() << endl;  // 168
    cout << "Decade value 1940's: " << coinC.getTotalValueDecade(195) << endl; // 94
    return 1;
}