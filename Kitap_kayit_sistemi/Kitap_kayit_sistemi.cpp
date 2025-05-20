#include <iostream>
#include <string>
using namespace std;

struct Kitap {
    int id = 0;
    string ad;
    string yazar;
    int sayfaSayisi;
};
void kitapSil(int& kitapAdet, Kitap urunler[]) {
    int silId;
    bool bulundu = false;
    cout << "Silmek istediginiz kitabin ID numarasini giriniz: ";
    cin >> silId;
    for (int i = 0; i < kitapAdet; i++) {
        if (urunler[i].id == silId) {
            for (i; i < kitapAdet - 1; i++) {
                urunler[i] = urunler[i + 1];
            }
            kitapAdet--;
            bulundu = true;
            system("cls");
            cout << "Kitap silindi." << endl;
            break;
        }
    }
    if (bulundu == false) {
        cout << "Girmis oldugunuz ID bulunamadi." << endl;
    }
}
void kitapListesi(int kitapAdet, Kitap urunler[]) {
    system("cls");
    cout << "----Kitap Listesi----" << endl;
    for (int i = 0; i < kitapAdet; i++) {
        cout << i + 1 << ". Kitap" << endl;
        cout << "Kitap ID: " << urunler[i].id << endl;
        cout << "Kitap Ad:" << urunler[i].ad << endl;
        cout << "Yazar Ad: " << urunler[i].yazar << endl;
        cout << "Sayfa Sayisi: " << urunler[i].sayfaSayisi << endl;
        cout << "----------------------------------------------" << endl;
    }
}
void kitapKayit(int kitapAdet, Kitap urunler[], int& idNo) {// int& idNo adres üzerinden işlem yapar
    for (int i = 0; i < kitapAdet; i++) {
        urunler[i].id = idNo;
        cout << i + 1 << ". Kitap" << endl;
        cout << "Kitabin adi: ";
        getline(cin, urunler[i].ad);
        cout << "Yazarin adi: ";
        getline(cin, urunler[i].yazar);
        cout << "Sayfa sayisi: ";
        cin >> urunler[i].sayfaSayisi; cin.ignore();
        cout << "Kayit yapildi, kitabin ID numarasi: " << idNo << endl;
        cout << "----------------------------------------------" << endl;
        idNo += 1;
    }
}
void kitapBul(int searchID, Kitap urunler[], int kitapAdet) {
    system("cls");
    cout << "Bilgilerini bulmak istediginiz kitabin ID numarasini giriniz: ";
    cin >> searchID;
    for (int i = 0; i < kitapAdet; i++) {
        if (searchID == urunler[i].id) {
            cout << i + 1 << ". Kitap" << endl;
            cout << "Kitap ID: " << urunler[i].id << endl;
            cout << "Kitap Ad:" << urunler[i].ad << endl;
            cout << "Yazar Ad: " << urunler[i].yazar << endl;
            cout << "Sayfa Sayisi: " << urunler[i].sayfaSayisi << endl;
            cout << "----------------------------------------------" << endl;
            break;
        }
    }
};
void kitapMenu(int kitapAdet, Kitap urunler[], int searchID) {
    int menuSecim;
    do {

        cout << "---Menu---" << endl;
        cout << "1 - Kitap Listesi" << endl;
        cout << "2 - ID ile ara" << endl;
        cout << "3 - Kitap Sil" << endl;
        cout << "4 - Cikis Yap" << endl;
        cout << "Islem: ";
        cin >> menuSecim;
        cout << "----------------------------------------------" << endl;
        if (menuSecim == 1) { kitapListesi(kitapAdet, urunler); }
        else if (menuSecim == 2) { kitapBul(searchID, urunler, kitapAdet); }
        else if (menuSecim == 3) { kitapSil(kitapAdet, urunler); }


    } while (menuSecim != 4);
}


int main() {
    int kitapAdet;
    int idNo = 100;
    int searchID = 0;

    cout << "---Kitap Kayit Sistemine Hos Geldin---" << endl;
    cout << "Kaydetmek istediginiz kitap sayisini giriniz: ";
    cin >> kitapAdet; cin.ignore();
    cout << "----------------------------------------------" << endl;
    Kitap* urunler = new Kitap[kitapAdet];
    kitapKayit(kitapAdet, urunler, idNo);
    kitapMenu(kitapAdet, urunler, searchID);



    delete[] urunler;
}

