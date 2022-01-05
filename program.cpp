#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

#define adSoyadSayisi 50
#define soruSayisi 10
#define veriAlani 14

int kisiSayisi;
string adlar[adSoyadSayisi];
string soyadlar[adSoyadSayisi];
string cevapAnahtari[soruSayisi];


void adDosyasiOkuma(){
    //AD DOSYASI OKUMA

    ifstream dosyaOku("ad.txt");
    string satir = "";

    if (dosyaOku.is_open())
    {

        int i = 0;
        while (i, getline(dosyaOku, satir))
        {
            adlar[i] = satir;
            i++;
        }

        dosyaOku.close();
    }

    //----------------------------------------------------------
}

void soyadDosyasiOkuma(){
    //SOYAD DOSYASI OKUMA

    ifstream soyadDosyaOku("soyad.txt");
    string soyadSatir = "";

    if (soyadDosyaOku.is_open())
    {

        int i = 0;
        while (i, getline(soyadDosyaOku, soyadSatir))
        {
            soyadlar[i] = soyadSatir;
            i++;
        }

        soyadDosyaOku.close();
    }
}

void DogruYanlisSorulari(){

    int soruSayilari = 10;

    //DOĞRU YANLIŞ SORULARI

    string sorular[soruSayilari] = {"C++ , backend bir programlama dilidir.", "Dizilerin ilk index numarasi 1'dir", "C++ , kutuphanesi <iostream> 'dir ", "cout kullanicidan veri alir.", "cin ekrana veri basar.", "C++'in dosya uzantisi .cpp 'dir", "C++'da for dongusu kullanilmaz", "for dongusunde dizi kullanilmaz", "fonksiyonlar parametre alabilir", "string sayi alir."};

    for (int i = 0; i < 10; i++)
    {

        dogruYanliSorularinaDon:
        cout << i + 1 << ".Soru : " << sorular[i] << " : ";
        cin >> cevapAnahtari[i];



        if (cevapAnahtari[i] == "d" || cevapAnahtari[i] == "y" || cevapAnahtari[i] == "D" || cevapAnahtari[i] == "Y")
        {

        }
        else
        {
            cout << "Lutfen 'D' veya 'Y' giriniz!" << endl;
            goto dogruYanliSorularinaDon;
        }
    }

}

void VerileriOlustur(string kisiVerileri[][veriAlani]){
    
    //RANDOM YAŞ ÜRETME
    string randomYas[kisiSayisi];
    int enFazla = 60, enAz = 18;
    for (int i = 0; i < kisiSayisi; i++)
    {
        int r = rand() % (enFazla - enAz + 1) + enAz;
        string randomSayi = to_string(r);
        randomYas[i] = randomSayi;
    }

    //----------------------------------------------------------
    //RANDOM KİŞİ ÜRETME

    for (int sutun = 0; sutun < veriAlani; sutun++)
    {
        for (int satir = 0; satir < kisiSayisi; satir++)
        {
            if (sutun == 0)
            {
                int AdRandIndex = rand() % 50; // ad
                kisiVerileri[satir][sutun] = adlar[AdRandIndex];
            }
            else if (sutun == 1)
            {

                for(int a =0;a<satir;a++){
                    if(kisiVerileri[satir][0] == kisiVerileri[a][0]){
                       goto soyadOlustur; 
                    }
                }
                 soyadOlustur:
                 int SoyadRandIndex = rand() % 50; //soyad
                 kisiVerileri[satir][sutun] = soyadlar[SoyadRandIndex];

                
            }
            else if (sutun == 2)
            {
                int YasRandIndex = rand() % kisiSayisi; //yas
                kisiVerileri[satir][sutun] = randomYas[YasRandIndex];
            }
            else if (sutun >= 3 && sutun < 13)
            {
                int RandIndex = rand() % 10;
                kisiVerileri[satir][sutun] = cevapAnahtari[RandIndex];
            }
            else if (sutun == 13)
            {
                int sayac = 0;
                for(int i=3 ; i<13 ; i++){
                    if(kisiVerileri[satir][i] == "D" || kisiVerileri[satir][i] == "d"){
                        sayac += 10;
                    }
                }

                string sayac2 = to_string(sayac);
                kisiVerileri[satir][sutun] = sayac2;
            }
        }
    }


        //HEPSİNİ EKRANA YAZDIRIR
        cout << "----------------------------";
        cout << endl; 
    for (int i = 0; i < kisiSayisi; i++)
    {
        cout << i + 1 << ".kisi | " << "Ad : " << kisiVerileri[i][0] << " | Soyad : " << kisiVerileri[i][1] << " | Yas : " << kisiVerileri[i][2] << endl;
        cout << " | * Soru Cevaplari " << endl;
        for(int j =3;j<13;j++){
            cout << j-2 << ". Soru : " << kisiVerileri[i][j] << " | ";
        }
        cout << " Puan : " << kisiVerileri[i][13] << endl;
        cout << endl; 
        cout << "----------------------------";
        cout << endl; 
        cout << endl; 
    }    
    
}

void adSirala(string kisiVerileri[][veriAlani]){
    for (int i = 0; i < kisiSayisi; i++){
        cout << i+1 << ".Kisinin " << " Adi : " << kisiVerileri[i][0] << endl;
    }
}

void soyadSirala(string kisiVerileri[][veriAlani]){
    for (int i = 0; i < kisiSayisi; i++){
        cout << i+1 << ".Kisinin " << " Soyadi : " << kisiVerileri[i][1] << endl;
    }
}

void yasSirala(string kisiVerileri[][veriAlani]){
    for (int i = 0; i < kisiSayisi; i++){
        cout << i+1 << ".Kisinin " << " Yasi : " << kisiVerileri[i][2] << endl;
    }
}

void puanSirala(string kisiVerileri[][veriAlani]){
    for (int i = 0; i < kisiSayisi; i++){
        cout << i+1 << ".Kisinin " << " Puani : " << kisiVerileri[i][13] << endl;
    }
}


int main(){

        adDosyasiOkuma();
        soyadDosyasiOkuma();
        DogruYanlisSorulari();
        

        basaDon:
        cout << "Kisi sayisini giriniz : ";
        cin >> kisiSayisi;


        if(kisiSayisi <= 0 || kisiSayisi > 2500){
            cout << "Lutfen 1 ile 2500 arasinda bir deger giriniz!" << endl ;
            goto basaDon;
        }else{

        }

        string kisiVerileri[kisiSayisi][veriAlani];
        VerileriOlustur(kisiVerileri);
        string siralama;
        

        while(1==1){
            cout << "Siralamayi yaziniz : ";
            cin >> siralama;
            if(siralama == "Ad" || siralama == "ad" || siralama == "AD"){
                adSirala(kisiVerileri);
            } else if(siralama == "Soyad" || siralama == "soyad" || siralama == "SOYAD"){
                soyadSirala(kisiVerileri);
            }else if(siralama == "Yas" || siralama == "yas" || siralama == "YAS"){
                yasSirala(kisiVerileri);
            }else if(siralama == "Puan" || siralama == "puan" || siralama == "PUAN"){
                puanSirala(kisiVerileri);
            }
        }



}



