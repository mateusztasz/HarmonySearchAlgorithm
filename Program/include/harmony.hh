#ifndef HARMONY_HH
#define HARMONY_HH

#include <iostream>
#include <string>
#include <iomanip>

#include <ctime>
#include <random>
#include <chrono>

#include "boundary.hh"


using namespace std;

/*!
 * \file
 * \brief The file contains a definition of Harmony Class.
 *
 */


/*!
 * \brief Models every generated harmonics.
 */
class Harmony{
private:
    /*! \brief Represent size of problem (in literature usually names as ,,n''.)    */
    int _problem_size;
    /*! \brief A member keeping a value of objective function.    */
    double _obj_value;
    /*! \brief A dynamic table with value of all arguments x1,x2,....xn  .  */
    double *VarX;


public:
    /*! \brief Constructor of Harmony.    */
    Harmony(int &problem_size);
    /*! \brief Setting value of _obj_value (value of objective functions).    */
    void SetValue(double val);
    /*! \brief Returns an _obj_value (value of objective functions).    */
    double GetValue() const;
    /*! \brief Returns problem size.    */
    double GetProblemSize();
    /*! \brief Returns an argument of VarX table.
   * An argument is choosen by numberOfArgument.    */
    double GetVarX_of(int numberOfArgument);

    bool SetVarX_of(int numberOfArgument,double value);

    /*! \brief Initialize VarX with random values in such bounds given as whole table VarLim.    */
    void InitInBounds(Boundary VarLim[]);

    void SetVarX_InBounds(int VarIndex, Boundary VarLim[]);
    /*! \brief  to print out whole Harmony.    */
    void Print();
    /*! \brief Desctructor of Harmony.    */
    ~Harmony();
};





#endif
