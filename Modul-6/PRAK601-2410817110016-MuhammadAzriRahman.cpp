#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int random(int bil){
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize(){
    srand(time(NULL));
}

void clrscr(){
    system("cls");
}

int SequentialSearching(){
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++){
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++){
        if(data[i] == cari){
            counter++;
            flag = 1;
            save = i;
        }
    }
    if (flag == 1){
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    }
    else{
        printf("Data tidak ada!\n");
    }
    return 0;
}

int BinarySearching() {
    int n,kiri,kanan,tengah,temp,key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for(int i=0 ; i<n ; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for(int i=0; i<n ; i++) {
        for(int j = 0 ; j < n - 1 ; j++) {
            if(angka[j] > angka[j+1]) {
                temp = angka[j];
                angka[j] = angka[j+i];
                angka[j+1] = temp;
            }
        }
    }
    cout << "==================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for(int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n=================================================\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while(kiri <= kanan) 
    {
        tengah = (kiri + kanan) / 2;
        if(key == angka[tengah]) {
            ketemu = true;
            break;
        }
        else if(key < angka[tengah]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }
    if(ketemu == true) 
    {
        cout << "Angka ditemukan! ";
    }
    else
        cout << "Angka tidak ditemukan!";
    return 0;
}

int main() {
    int Pilihan;

    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> Pilihan;
        system("cls");

            switch(Pilihan) {
                case 1:
                    SequentialSearching();
                    break;
                case 2 :
                    BinarySearching();
                    break;
                case 3 :
                    cout << "Sequential Searching dan Binary Searching adalah dua metode pencarian data dengan karakteristik berbeda." << endl << endl;
                    cout << "Sequential Searching bekerja dengan memeriksa setiap elemen data satu per satu dari awal hingga akhir, cocok untuk data yang tidak terurut dan berukuran kecil karena kesederhanaannya, namun menjadi tidak efisien (waktu O(n)) pada data besar." << endl << endl;
                    cout << "Sebaliknya, Binary Searching memerlukan data yang sudah terurut terlebih dahulu. Metode ini membagi kumpulan data menjadi dua secara berulang, mempercepat pencarian secara signifikan (waktu O(log n)) karena hanya memeriksa sebagian kecil data di setiap langkah. Meskipun sedikit lebih kompleks dalam implementasi, Binary Searching jauh lebih efisien untuk mencari data dalam kumpulan besar yang sudah terurut." << endl << endl;
                    break;
                default :
                    cout << "\nTERIMA KASIH" << endl;                    
            }
        getch();
        clrscr();

    }
    while(Pilihan < 4);

} 