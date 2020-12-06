#include <iostream>
#include <process.h>
#include <stdlib.h>
#include "accountType.h"
#include "SpecialAccount.h"
#include "ShortTermAccount.h"
#include "LongTermAccount.h"
#include "CurrentAccount.h"
#include "Bank.h"

using namespace std;

Bank b;

void Menu()
{
    int ozelHesapLen=0;
    int secim;
    cout << "------------------------" << endl;
    cout << "Hesap Eklemek Icin 1:"
    <<"\nPara Cekmek Icin 2:"
    <<"\nPara Yatirmak Icin 3: "
    <<"\nHesaplarin ID ve son 5 islemini gormek icin 4:"
    << "\nHesaplarin ID'sini gormek icin 5:"
    << "\nSistemin su anki tarihini degismek icin 6:"
    << "\nOzel hesaplar arasinda cekilis yapmak icin 7:"
    << "\nCikmak icin 0:";

    cin >> secim;
    cout << endl;
    switch(secim)
    {
    accountType *pt;
    case 0:
    {
        exit(0);
    }
    case 1:
        {
            bool dogruMu=true;
            string ad,soyad;
            int hesapTur,id,balance;
            cout << "Kisa vadeli hesap icin 1\nUzun vadeli hesap icin 2\nOzel hesap icin 3\nVadesiz hesap icin 4: ";
            cin >> hesapTur;
            cout << endl;
            cout << "Isim giriniz: ";
            cin >> ad;
            cout << "Soyisim giriniz: ";
            cin >> soyad;
            while(dogruMu)
            {
                cout << "ID giriniz: ";
                cin >> id;
                dogruMu=b.IDSorgula(id);
                if(dogruMu)
                {
                    cout << "girdiginiz ID baska bir kullanici tarafından kullanilmaktadır!!"
                    << "\n lutfen baska bir ID giriniz"<<endl;
                }
                else
                {
                    cout << "ID'niz dogrulanmistir."<<endl;
                }
            }
            cout << "Bakiye giriniz: ";
            cin >> balance;
            cout << endl;
            if(hesapTur==1)
            {
                if (balance>=1000)
                {
                    ShortTermAccount shortt(ad,soyad,balance,id);
                    shortt.benefit(b.getDate());
                    pt = &shortt;
                    b.addAccount(*pt);
                }
                else
                {
                    cout<< "kisa vadeli hesap acmak icin minimum bakiye 1000 TL dir"<<endl;
                }
            }
            else if(hesapTur==2)
            {
                if (balance >=1500)
                {
                    LongTermAccount longt(ad,soyad,balance,id);
                    longt.benefit(b.getDate());
                    pt = &longt;
                    b.addAccount(*pt);
                }
                else
                {
                    cout<< "uzun vadeli hesap acmak icin minimum bakiye 1500 TL dir"<<endl;
                }

            }
            else if(hesapTur==3)
            {
                ozelHesapLen++;
                SpecialAccount specialt(ad,soyad,balance,id);
                specialt.benefit(b.getDate());
                pt = &specialt;
                b.addAccount(*pt);
            }
            else if(hesapTur==4)
            {
                CurrentAccount currentt(ad,soyad,balance,id);
                pt = &currentt;
                b.addAccount(*pt);
            }
            break;
        }
    case 2:
        {
            int id,miktar;
            cout << "Para cekilecek hesabin ID'sini giriniz: ";
            cin >> id;
            cout << "Cekilecek miktari giriniz: ";
            cin >> miktar;
            b.withDraw(id,miktar);
            b.getAccount();
            break;
        }
    case 3:
        {
            int id,miktar;
            cout << "Para yatirilacak hesabin ID'sini giriniz: ";
            cin >> id;
            cout << "Yatirilacak miktari giriniz: ";
            cin >> miktar;
            b.deposit(id,miktar);
            b.getAccount();
            break;
        }
    case 4:
        {
            b.sonBesIslem();
            break;
        }
    case 5:
        {
            b.getAccount();
            break;
        }
    case 6:
        {
            char ch;
            int d,m,y;
            cout << "tarihiler arasina ':' girerek yaziniz:";
            cin>>d;
            cin.get(ch);
            cin >> m;
            cin.get(ch);
            cin >> y;
            y -= 1900;
            m -= 1;
            b.setDate(y,m,d);
            break;
        }
    case 7:
        {
            /*
            int kazanan=b.sortition(ozelHesapLen);
            b.deposit(kazanan,10000);
            */
            break;
        }
    }
    Menu();
}

int main()
{
    Menu();
    return 0;
}
