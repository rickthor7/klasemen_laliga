#include <iostream>
#include <string>
using namespace std;

const int MAX_CLUBS = 20; 

struct Club {
    string nama;
    int poin;
    int selisihGol;
};

int inputData(Club liga[]) {
    int jumlah;
    cout << "Masukkan jumlah klub (maksimal " << MAX_CLUBS << "): ";
    cin >> jumlah;
    cin.ignore();

    if (jumlah > MAX_CLUBS) {
        cout << "Jumlah klub melebihi batas! Diubah menjadi " << MAX_CLUBS << endl;
        jumlah = MAX_CLUBS;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nKlub " << i + 1 << endl;
        cout << "Nama Club: ";
        getline(cin, liga[i].nama);
        cout << "Poin: ";
        cin >> liga[i].poin;
        cout << "Selisih Gol: ";
        cin >> liga[i].selisihGol;
        cin.ignore(); 
    }
    return jumlah; 
}

int partition(Club liga[], int low, int high) {
    Club pivot = liga[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (liga[j].poin > pivot.poin || 
           (liga[j].poin == pivot.poin && liga[j].selisihGol > pivot.selisihGol)) {
            i++;
            swap(liga[i], liga[j]);
        }
    }
    swap(liga[i + 1], liga[high]);
    return (i + 1);
}

void quickSort(Club liga[], int low, int high) {
    if (low < high) {
        int pi = partition(liga, low, high);
        quickSort(liga, low, pi - 1);  
        quickSort(liga, pi + 1, high); 
    }
}


void printKlasemen(Club liga[], int jumlah) {
    cout << "\n--------------------------------------------------" << endl;
    cout << "| No. | Nama Club       | Poin | Selisih Gol    |" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << i + 1 << "   | " << liga[i].nama;
        if (liga[i].nama.length() < 10) cout << "\t";
        cout << "\t| " << liga[i].poin << "   | " << liga[i].selisihGol << "\t\t|" << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    Club liga[MAX_CLUBS]; 
    int jumlahKlub = 0;
    int pilihan;

    do {
        cout << "\nMenu Klasemen La Liga:" << endl;
        cout << "1. Input Data Klub" << endl;
        cout << "2. Tampilkan Klasemen (Belum Sorting)" << endl;
        cout << "3. Urutkan Klasemen (Quick Sort)" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                jumlahKlub = inputData(liga);
                break;
            case 2:
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    printKlasemen(liga, jumlahKlub);
                }
                break;
            case 3:
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    quickSort(liga, 0, jumlahKlub - 1);
                    cout << "Klasemen setelah diurutkan:" << endl;
                    printKlasemen(liga, jumlahKlub);
                }
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
