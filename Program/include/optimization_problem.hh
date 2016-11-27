#ifndef OPTIMIZATION_PROBLEM_HH
#define OPTIMIZATION_PROBLEM_HH

#include "harmony.hh"
#include "boundary.hh"

#include <iostream>
#include <list>

#include "Lepton.h"
#include "mylepton.hh"

#include <cmath>
#define M_E        2.71828182845904523536

#include <set>
#include <iterator>
#include <fstream>
#include <QApplication>
using namespace std;


#define HARMONIES_ALL_FILE          "./Visualisation/HS_AllSteps.dat"
#define HARMONIES_PARTICULAR_FILE   "./Visualisation/HS_Vizualisation.dat"

/*!
 * \file
 * \brief The file contains a definition of Optimization_Problem.
 *
 */



/*!
 * \brief Models the main problem which we are solving.
 */
class Optimization_Problem{
private:

    /*! \brief Harmony Memory is made by a list of Harmony.  */
    list <Harmony> Harmony_Memory;
    /*! \brief Attribute of Harmony Memory Size.    */
    double _HMS;
    /*! \brief Attribute of Harmony Memory Considering Rate.   */
    double _HMCR;
    /*! \brief Attribute of Pitch Adjusting Rate.    */
    double _PAR;
    /*! \brief Condition of algorithm stops : amount of repetiotion.    */
    double _repeat;
    /*! \brief Represent size of problem (in literature usually names as ,,n''.)    */
    int _problem_size;

    double _bandwidth;
    /*! \brief Represent a table with limits for every state variable x1,x2,...xn.   */
    Boundary *VariableLimits;

    int _progress_of_search;
    bool _algorithm_stop;

    /*! \brief Calculate a value of objective function.   */
    double Object_function(Harmony &H);

    ofstream filePlot;
    ofstream fileVisu;

    string _equation;

    bool write_to_text_file;

public:
    friend class MainWindow;
    friend class MeshMainWindow;

    MyLepton Lep;
    std::map<string, double> constants;

    /*! \brief Constructor of Problem Optimization.    */
    Optimization_Problem(double &HMS, double &PAR, int &size, double & HMCR, double &repeat,double &bandwidth);
    /*! \brief Constructor of Problem Optimization.    */
    Optimization_Problem();
    void Initialize(double &HMS, double &PAR, int &size, double & HMCR, double &repeat,double &bandwidth);

    /*! \brief Setting limits for every variable.   */
    void SetVariableLimits();
    /*! \brief Creates all necessary Harmonys and initialize them with random in their limits.    */
    void InitHarmonyMemory();
    /*! \brief Prints out a list of Harmonys - Harmony Memory.    */
    void PrintHarmonyMemory();
    /*! \brief Prints all settled limits for variable x1,x2,...,xn.    */
    void PrintVariableLimits();
    /*! \brief Returns the value of _progress_of_search.    */
    int ReturnProgress();
    /*! \brief Returns the solution value.    */
    Harmony ReturnBestSolution();

    bool isInitialized;

    void SetVariableLimits(string var,double Low, double Up);
    void SetVariableLimitLow(string var,double Low);
    void SetVariableLimitUpper(string var,double Low);
    bool AfterUpdate();
    void SetEquation(string str);

    /*! \brief Execute the main work of algoritm. Needs to be completed!    */
    bool Search();

    void WriteSolution();

    ~Optimization_Problem();

};

/*! \brief Funtion which compere two elements on the list - Harmony Memory. Its needed to sort that list.    */
bool compareFun (const Harmony &first, const Harmony &second);




#endif
