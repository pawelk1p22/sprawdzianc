#include <iostream>
#include <cmath>

using namespace std;



int nwd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return nwd(b, a % b);
    }
}

void skroc_ulamek(int &licznik, int &mianownik) {
    int nwd_ulamka = nwd(abs(licznik), abs(mianownik));
    licznik /= nwd_ulamka;
    mianownik /= nwd_ulamka;
}

int NWD_odj_rek(int a, int b){
if ( a==b ){
    return a;
} else if( a>b ){
    return NWD_odj_rek(a-b,b);
}  else return NWD_odj_rek(a, b-a) ;
}

int NWD_odj_itr( int a, int b){
while(a!=b){
if( a>b ){
   a-=b; 
} else b-=a;
    }return a;
}

int NWD_mod_rek(int a, int b){
    if( b==0){
        return a;
    } else
        return NWD_mod_rek(b, a%b);
}

int NWD_mod_itr(int a, int b){
    int r ;
    while (b>0){
    r=a % b;
    a=b;
    b=r;
    }
    return a;
}

bool pierwsza_pierwiastek(int n){
	for(int i=2; i<sqrt(n);i++){
        if(n%i == 0){
            return false;
        }else return true;
	}
}

int fib_rek(int n){
    if ((n==1)||(n==2)){
       return 1; 
    } 
    return fib_rek(n-1) + fib_rek(n-2);

}

int fib_itr (int n) {
    int a = 0, b = 1;
    for(int i=0;i<n;i++)
     {
        b += a;
        a = b-a;
     }
     cout<<b<<endl;
}

long long rek_silnia(int n){
 if(n==0){
    return 1;
} else{
    return rek_silnia(n-1)*n; 
}
}

int silnia(int n){
    int liczba = 1;
    int wynik = 1;
    if(n==1 || n==0){
        return n;
    }else{
        for(int i; i<n; i++){
            wynik*= liczba;
            liczba++;
        }
    }
    return wynik;
}

bool pierwsza_naiwna(int n){
for(int i=2; i<n ; i++)
    if(n%i==0){
        return false;
    } else return true;
}

void wieze(int n, char a, char b, char c){
    if(n>0){
        wieze(n-1, a, c, b);
        cout<<a<<" na "<<b<<endl;
        wieze(n-1, c, b, a);
    }
}

int main() {
    cout << pierwsza_pierwiastek(11) << endl;
    cout << pierwsza_naiwna(11) << endl;
    cout << silnia(6) << endl;
    cout << rek_silnia(6) << endl;
    wieze(5, 'A', 'B', 'C');

    int l1, m1, l2, m2, dzialanie;


    cout << "Podaj licznik i mianownik pierwszego ulamka (oddzielone spacja): ";
    cin >> l1 >> m1;

    cout << "Podaj licznik i mianownik drugiego ulamka (oddzielone spacja): ";
    cin >> l2 >> m2;


    cout << "Wybierz dzialanie, ktore chcesz wykonac:" << endl;
    cout << "1. Mnozenie" << endl;
    cout << "2. Dzielenie" << endl;
    cout << "3. Dodawanie" << endl;
    cout << "4. Odejmowanie" << endl;
    cin >> dzialanie;

    int wynik_l, wynik_m;


    switch (dzialanie) {
        case 1:
            wynik_l = l1 * l2;
            wynik_m = m1 * m2;
            break;
        case 2:
            wynik_l = l1 * m2;
            wynik_m = m1 * l2;
            break;
        case 3:
            wynik_l = l1 * m2 + l2 * m1;
            wynik_m = m1 * m2;
            break;
        case 4:
            wynik_l = l1 * m2 - l2 * m1;
            wynik_m = m1 * m2;
            break;
        default:
            cout << "Nieprawidlowy wybor dzialania." << endl;
            return 0;
    }
    skroc_ulamek(wynik_l, wynik_m);

    if(wynik_l==wynik_m){
        cout<<"Wynik: "<<1<<endl;
    }else if(wynik_m == 1){
        cout<<"Wynik: "<<wynik_l<<endl;
    }else if(wynik_l > wynik_m){
        cout<<"Wynik: "<<wynik_l / wynik_m<<" "<<wynik_l-((wynik_l / wynik_m)*wynik_m)<<"/"<<wynik_m<<endl;
    }else if(wynik_l < wynik_m){
        cout << "Wynik: " << wynik_l << "/" << wynik_m << endl;
    }

    return 0;
}

void sito(int T[], int n){
    int i, m;
    for(i=2;i<=n;i++){
        T[i]=1;
    }
    i=2;
    while(i<=n){
        m = 2*i;
        while(m<=n){
            T[m]=0;
        m+=i;
        }
    }
    do i++; while(T[i]== 0 && i <= n);
}
