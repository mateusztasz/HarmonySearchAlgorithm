#include "boundary.hh"

#include <iostream>
using namespace std;

/*! \brief Initialize member values with default values.    */
Boundary::Boundary(){
    lower = -10;
    upper = 10;
}

/*! \brief Giving an access to member lower and upper.     */
void Boundary::Get(double &low, double &up){
    low = Boundary::lower;
    up = Boundary::upper;
}
/*! \brief Setting lower and upper boundary as given argument    */
void Boundary::Set(double low, double up){
    Boundary::lower = low;
    Boundary::upper = up;
}

void Boundary::SetLower(double low){
    Boundary::lower = low;
}
void Boundary::SetUpper(double up){
    Boundary::upper = up;
}

Boundary::~Boundary(){
    std::cout<<"Boundary structure has been deleted.";
}
