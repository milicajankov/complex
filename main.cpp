#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct Complex{
    double re;
    double im;

    Complex(double a=0., double b=0.) : re(a), im(b) { }
};
Complex zbir(const Complex &c1, const Complex &c2){ // ovo vraca neki kompleksan broj takodje, tako da je povratni tip strukture
    Complex rez;
    rez.re = c1.re + c2.re;
    rez.im = c1.im + c2.im;
    return rez;
}
Complex razlika(const Complex &c1, const Complex &c2){
    Complex rez;
    rez.re = c1.re - c2.re;
    rez.im = c1.im - c2.im;
    return rez;
}
Complex proizvod(const Complex &c1, const Complex &c2){
    Complex rez;
    rez.re = c1.re * c2.re - c1.im * c2.im;
    rez.im = c1.re * c2.im + c1.re * c2.im;
    return rez;
}
Complex kolicnik(const Complex &c1, const Complex &c2){
    Complex rez;
    rez.re = (c1.re*c2.re + c1.im*c2.im) / (c2.re*c2.re + c2.im*c2.im);
    rez.im = (c1.im*c2.re - c1.re*c2.im) / (c2.re*c2.re + c2.im*c2.im);
    return rez;
}
int main(){
   Complex c1, c2;
   char odg;
   int izbor;
       do{
            cout << "Program za izracunavanje osnovnih aritmetickih operacija nad kompleksnim brojevima." << endl;
            cout << "Izaberite redni broj operacije: " << endl;
            cout << "1.Sabiranje" << endl;
            cout << "2.Oduzimanje"<< endl;
            cout << "3.Mnozenje" << endl;
            cout << "4.Deljenje" << endl;
            cout << "5 Rad sa kompleksnim nizovima " << endl;
            cin >> izbor;

                switch(izbor){
                    case 1:{
                        cout << "Unesite realni i imaginarni deo prvog broja:" << endl;
                        cin >> c1.re >> c1.im ;
                        cout << "Unesite realni i imaginarni deo drugog broja:" << endl;
                        cin >> c2.re >> c2.im ;

                        Complex c;
                        c=zbir(c1,c2);
                        cout << "Zbir 2 broja je: " << c.re << " +j " << c.im << endl;
                        }
                        break;
                    case 2:{
                        cout << "Unesite realni i imaginarni deo prvog broja:" << endl;
                        cin >> c1.re >> c1.im ;
                        cout << "Unesite realni i imaginarni deo drugog broja:" << endl;
                        cin >> c2.re >> c2.im ;
                        Complex c;
                        c=zbir(c1,c2);
                        cout << "Razlika 2 broja je: " << c.re << " +j " << c.im << endl;
                        }
                        break;
                    case 3:{
                        cout << "Unesite realni i imaginarni deo prvog broja:" << endl;
                        cin >> c1.re >> c1.im ;
                        cout << "Unesite realni i imaginarni deo drugog broja:" << endl;
                        cin >> c2.re >> c2.im ;
                        Complex c;
                        c=proizvod(c1, c2);
                        cout << "Proizvod 2 broja je: " << c.re << " +j " << c.im << endl;
                        }
                        break;
                    case 4:{
                        cout << "Unesite realni i imaginarni deo prvog broja:" << endl;
                        cin >> c1.re >> c1.im ;
                        cout << "Unesite realni i imaginarni deo drugog broja:" << endl;
                        cin >> c2.re >> c2.im ;
                        Complex c;
                        c=kolicnik(c1, c2);
                        cout << "Kolicnik 2 broja je: " << c.re << " +j " << c.im << endl;
                        }
                        break;
                    case 5:
                        {
                        int n;
                        cout << "Unesite broj elemenata niza" << endl;
                        cin >> n;
                        Complex niz[n] = {};
                            for(size_t i = 0; i < n; ++i){
                            cout << "Unesite realni i imaginarni deo " << i + 1 <<". elemeneta niza: ";
                            cin >> niz[i].re >> niz[i].im;
                                }
                            for(size_t i=0; i < n; ++i){
                            cout << i+1 << ".clan" << niz[i].re << "+j " << niz[i].im << endl;
                            }

                        Complex Y[n] = {};
                            for(size_t k = 0; k < n; ++k)
                                for(size_t m = 0; m < n; ++m){
                            Complex tmp;
                            tmp.re = cos(2*M_PI*m*k / n);
                            tmp.im = sin(2*M_PI*m*k / n);
                            Y[k] = zbir(Y[k], proizvod(niz[m], tmp));
                            }
                    for(size_t i = 0; i < n; ++i){
                        cout << "Y[" << i+1 << "]:" << Y[i].re << " +j" << Y[i].im << endl;
                            }
                        }
                        break;
                    default:
                        cout << "Izabrali ste nepostojecu opciju. Pokusajte ponovo." << endl;
                        cout << "Program za izracunavanje osnovnih aritmetickih operacija nad kompleksnim brojevima." << endl;
                        cout << "Izaberite redni broj operacije: " << endl;
                        cout << "1.Sabiranje"<< endl;
                        cout << "2.Oduzimanje"<< endl;
                        cout << "3.Mnozenje" << endl;
                        cout << "4.Deljenje" << endl;
                        cin >> izbor;

                }

            cout << "Da li zelite ponovo da unesete 2 kompleksna broja?[d/n]" << endl;
            cin >> odg;
            }while(odg == 'd' || odg == 'D');
    cout << "Kraj programa. " << endl;
    return 0;
}
