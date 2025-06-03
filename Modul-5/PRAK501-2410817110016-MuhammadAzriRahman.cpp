#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int bubbleSort();
int selectionSort();
int quickSort();
int insertionSort();
int mergeSort();
int shellSort();

int main() {
    int menuPilihan;

    do {
        cout << "SORTING" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Shell Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Bubble Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Exit" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> menuPilihan;
        system("cls");

        switch(menuPilihan) {
            case 1: insertionSort(); break;
            case 2: mergeSort(); break;
            case 3: shellSort(); break;
            case 4: quickSort(); break;
            case 5: bubbleSort(); break;
            case 6: selectionSort(); break;
            default: cout << "TERIMA KASIH" << endl;
            return 0;
        }
        getch();
        system("cls");
    } while(menuPilihan < 8);
}

int bubbleSort() {
    string teksInput;
    int nilaiTukar;

    cout << "========Bubble Sort========" << endl;
    cout << "Masukkan Data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int indeks = 0; indeks < teksInput.length(); indeks++) {
        cout << setw(3) << teksInput[indeks];
    }
    cout << endl;

    for (int i = 0; i < teksInput.length() - 1; i++) {
        for (int j = 0; j < teksInput.length() - 1; j++) {
            if (teksInput[j] > teksInput[j + 1]) {
                nilaiTukar = teksInput[j];
                teksInput[j] = teksInput[j + 1];
                teksInput[j + 1] = nilaiTukar;
            }
        }
    }

    cout << "Data setelah diurutkan :" << endl;
    for (int indeks = 0; indeks < teksInput.length(); indeks++) {
        cout << setw(3) << teksInput[indeks];
    }
    return 0;
}

int selectionSort() {
    string teksInput;
    int indeksTerkecil;

    cout << "========Selection Sort========" << endl;
    cout << "Masukkan data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    cout << endl;

    for (int i = 0; i < teksInput.length(); i++) {
        indeksTerkecil = i;
        for (int j = i + 1; j < teksInput.length(); j++) {
            if (teksInput[indeksTerkecil] > teksInput[j]) {
                indeksTerkecil = j;
            }
        }
        if (indeksTerkecil != i) {
            int sementara = teksInput[i];
            teksInput[i] = teksInput[indeksTerkecil];
            teksInput[indeksTerkecil] = sementara;
        }
    }

    cout << "Data setelah diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    return 0;
}

int Partition(string& dataTeks, int batasKiri, int batasKanan) {
    int pivot = dataTeks[batasKanan];
    int i = batasKiri - 1;

    for (int j = batasKiri; j < batasKanan; j++) {
        if (dataTeks[j] <= pivot) {
            i++;
            int sementara = dataTeks[i];
            dataTeks[i] = dataTeks[j];
            dataTeks[j] = sementara;
        }
    }
    int sementara = dataTeks[i + 1];
    dataTeks[i + 1] = dataTeks[batasKanan];
    dataTeks[batasKanan] = sementara;

    return (i + 1);
}

void QuickSort(string& dataTeks, int batasKiri, int batasKanan) {
    if (batasKiri < batasKanan) {
        int partisi = Partition(dataTeks, batasKiri, batasKanan);
        QuickSort(dataTeks, batasKiri, partisi - 1);
        QuickSort(dataTeks, partisi + 1, batasKanan);
    }
}

int quickSort() {
    string teksInput;
    int indeksAwal = 0;

    cout << "========Quick Sort========" << endl;
    cout << "Masukkan data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    cout << endl;

    QuickSort(teksInput, indeksAwal, teksInput.length() - 1);

    cout << "Data setelah diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    return 0;
}

int insertionSort() {
    string teksInput;
    int i, kunci, j;

    cout << "========Insertion Sort========" << endl;
    cout << "Masukkan data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    cout << endl;

    for (i = 1; i < teksInput.length(); i++) {
        kunci = teksInput[i];
        j = i - 1;

        while (j >= 0 && teksInput[j] > kunci) {
            teksInput[j + 1] = teksInput[j];
            j = j - 1;
        }
        teksInput[j + 1] = kunci;
    }

    cout << "Data setelah diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    return 0;
}

void Merge(string& dataTeks, int kiri, int tengah, int kanan) {
    int panjangKiri = tengah - kiri + 1;
    int panjangKanan = kanan - tengah;
    char L[panjangKiri], R[panjangKanan];

    for (int i = 0; i < panjangKiri; i++) {
        L[i] = dataTeks[kiri + i];
    }
    for (int j = 0; j < panjangKanan; j++) {
        R[j] = dataTeks[tengah + 1 + j];
    }

    int i = 0, j = 0, k = kiri;
    while (i < panjangKiri && j < panjangKanan) {
        if (L[i] <= R[j]) {
            dataTeks[k++] = L[i++];
        } else {
            dataTeks[k++] = R[j++];
        }
    }

    while (i < panjangKiri) {
        dataTeks[k++] = L[i++];
    }

    while (j < panjangKanan) {
        dataTeks[k++] = R[j++];
    }
}

void MergeSort(string& dataTeks, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        MergeSort(dataTeks, kiri, tengah);
        MergeSort(dataTeks, tengah + 1, kanan);
        Merge(dataTeks, kiri, tengah, kanan);
    }
}

int mergeSort() {
    string teksInput;
    int indeksAwal = 0;

    cout << "========Merge Sort========" << endl;
    cout << "Masukkan data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    cout << endl;

    MergeSort(teksInput, indeksAwal, teksInput.length() - 1);

    cout << "Data setelah diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    return 0;
}

int shellSort() {
    string teksInput;

    cout << "========Shell Sort========" << endl;
    cout << "Masukkan data : ";
    cin >> teksInput;

    cout << "Data sebelum diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    cout << endl;

    for (int jarak = teksInput.length() / 2; jarak > 0; jarak /= 2) {
        for (int i = jarak; i < teksInput.length(); i++) {
            char sementara = teksInput[i];
            int j;
            for (j = i; j >= jarak && teksInput[j - jarak] > sementara; j -= jarak) {
                teksInput[j] = teksInput[j - jarak];
            }
            teksInput[j] = sementara;
        }
    }

    cout << "Data setelah diurutkan :" << endl;
    for (int i = 0; i < teksInput.length(); i++) {
        cout << setw(3) << teksInput[i];
    }
    return 0;
}
