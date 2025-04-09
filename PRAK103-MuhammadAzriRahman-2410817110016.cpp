#include<iostream>
using namespace std;

struct DataInput{
    char huruf; 
    string kata; 
    int angka;
};

int main(){
    DataInput dataUser;
    cout << "Masukkan sebuah huruf = "; cin >> dataUser.huruf;
    cout << "Masukkan sebuah kata = " ; cin >> dataUser.kata;
    cout << "Masukkan Angka = "; cin >> dataUser.angka;

    cout << "Huruf yang Anda masukkan adalah " << dataUser.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << dataUser.kata << endl;
    cout << "Angka yang Anda masukkan adalah " << dataUser.angka << endl;

    return 0;
}