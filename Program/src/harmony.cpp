#include "harmony.hh"

#include <iostream>

using namespace std;
mt19937 u(std::random_device{}() ); //Mersenne Twister: Good quality random number generator


/*! \brief Constructor of Harmony.    */
Harmony::Harmony(int &problem_size){
    _problem_size = problem_size;
    VarX = new double[problem_size];

    //cout<<"Harmony has been created."<<endl;
}

/*! \brief Setting value of _obj_value (value of objective functions).    */
void Harmony::SetValue(double val){
    Harmony::_obj_value = val;
}
/*! \brief Return an _obj_value (value of objective functions).    */
double Harmony::GetValue() const{
    double val = Harmony::_obj_value;
    return val;
}
/*! \brief Return problem size.    */
double Harmony::GetProblemSize(){
    double size = Harmony::_problem_size;
    return size;
}

/*! \brief Returns an argument of VarX table.
 * An argument is choosen by numberOfArgument.    */
double Harmony::GetVarX_of(int numberOfArgument){
    return Harmony::VarX[numberOfArgument];
}

bool Harmony::SetVarX_of(int numberOfArgument,double value){
    Harmony::VarX[numberOfArgument] = value;
    return true;
}

/*! \brief Initialize VarX with random values in such bounds given as whole table VarLim.    */
void Harmony::InitInBounds(Boundary VarLim[]){
    double upperBound=0;
    double lowerBound=0;
    double randomNumber =0;

    for(int i=0; i<_problem_size; ++i ){
        VarLim[i].Get(lowerBound,upperBound);
        std::uniform_real_distribution<double> rand(lowerBound,upperBound);
        randomNumber = rand(u);
        VarX[i] = randomNumber;

    }
}

void Harmony::SetVarX_InBounds(int VarIndex, Boundary VarLim[]){
    double upperBound=0;
    double lowerBound=0;
    //generate rand in bounds
    VarLim[VarIndex].Get(lowerBound,upperBound);
    std::uniform_real_distribution<double> rand(lowerBound,upperBound);

    VarX[VarIndex] =  rand(u);
}

/*! \brief Operator << goes to print out whole Harmony.    */
void Harmony::Print( ){
    cout << fixed << showpoint;
    cout << setprecision(3);

    cout << setw(5) << this->GetValue() ;
    cout<<setw(15);

    for(int i = 0; i< this->GetProblemSize();++i){
        cout<< std::right <<  this->GetVarX_of(i) ;
        if(i<this->GetProblemSize()-1)
            cout << setw(15);
        else
            cout<<endl;
    }

}

/*! \brief Desctructor of Harmony.    */
Harmony::~Harmony(){}


