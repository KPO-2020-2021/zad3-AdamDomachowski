#include <iostream>
#include <cstdlib>
#include <cmath>

#include "size.hh"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"

rectangle rectangle::rotacja(double angle, int times){
Matrix macierz = Matrix();
int i=0;
angle = angle*M_PI/180;
macierz(0,0)  = cos(angle);
macierz(0,1)  = -sin(angle);
macierz(1,0)  = sin(angle);
macierz(1,1)  = cos(angle);
//std::cout << macierz;
while (i<times)
{
wierzcholki[0][0] = macierz * wierzcholki[0][0];
wierzcholki[0][1] = macierz * wierzcholki[0][1];
wierzcholki[1][0] = macierz * wierzcholki[1][0];
wierzcholki[1][1] = macierz * wierzcholki[1][1];
i++; 
}



return wierzcholki;
}


/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
rectangle::rectangle() {
double tab[2] = {0.0, 0.0};
    for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
            wierzcholki[i][j] = tab;
            }
    }
}




/******************************************************************************
 |  Przeciążenie dodawania prostokata i wektora                               |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
rectangle rectangle::operator + (Vector tmp) {
    rectangle result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->wierzcholki[i][j] + tmp;
        }
    }
    return result;
}



/******************************************************************************
 |  Konstruktor parametryczny klasy rectangle.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
rectangle::rectangle(Vector tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            wierzcholki[i][j] = tmp[i][j];
        }
    }
}



/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      rec - prostokat.                                                         |
 */
std::istream &operator>>(std::istream &in, rectangle &rec) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> rec(i, j);
        }
    }
    return in;
}



/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      rec - ptostokat.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const rectangle &rec) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << rec(i, j) << std::endl; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
    //std::cout << std::endl;
    }
    return out;
}





/******************************************************************************
 |  Funktor prostokata                                                         |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
Vector &rectangle::operator ()( int row,  int column) {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return wierzcholki[row][column];
}



/******************************************************************************
 |  Funktor prostokata                                                        |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const Vector &rectangle::operator() ( int row,  int column) const {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return wierzcholki[row][column];
}


void rectangle::check_length(){

double b1=wierzcholki[0][0].length(wierzcholki[0][1]);
double b2=wierzcholki[1][0].length(wierzcholki[1][1]);
double b3=wierzcholki[0][0].length(wierzcholki[1][0]);
double b4=wierzcholki[0][1].length(wierzcholki[1][1]);
if(b1==b2){
    std::cout<<"sa rowne"<<std::endl;
}
else{
    std::cout<<"nie sa rowne"<<std::endl;
}
    //std::cout<<b1<<std::endl;
    //std::cout<<b2<<std::endl;
if(b3==b4){
    std::cout<<"sa rowne"<<std::endl;
}
else{
    std::cout<<"nie sa rowne"<<std::endl;
}
    //std::cout<<b3<<std::endl;
    //std::cout<<b4<<std::endl;

}
        
