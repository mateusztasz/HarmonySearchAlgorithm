#include "optimization_problem.hh"
#include "harmony.hh"

#include <iostream>
using namespace std;

extern mt19937 u;
extern bool Before_Problem;

/*! \brief Constructor of Problem Optimization.    */
Optimization_Problem::Optimization_Problem(double &HMS, double &PAR, int &problem_size, double & HMCR, double &repeat, double &bandwidth){
    Before_Problem = false;

    _HMS = HMS;
    _PAR = PAR;
    _problem_size = problem_size;
    _HMCR = HMCR;
    _repeat = repeat;
    _bandwidth = bandwidth;
    isInitialized = true;
    _progress_of_search = 0;
    _algorithm_stop = false;

    // write_to_text_file = true;

    VariableLimits = new Boundary[problem_size];

    for(int i = 0; i < HMS; ++i){
        Harmony Har(problem_size);
        Harmony_Memory.push_back(Har);
    }

    constants["pi"] = 3;

    cout<<"Optimization problem has been created."<<endl;
}


/*! \brief Constructor of Problem Optimization.    */
Optimization_Problem::Optimization_Problem(){
    Before_Problem = false;
    cout<<"Optimization problem has been created."<<endl;
}

void Optimization_Problem::Initialize(double &HMS, double &PAR, int &problem_size, double & HMCR, double &repeat,double &bandwidth){
    _HMS = HMS;
    _PAR = PAR;
    _problem_size = problem_size;
    _HMCR = HMCR;
    _repeat = repeat;
    _bandwidth = bandwidth;
    isInitialized = true;
    _progress_of_search = 0;
    _algorithm_stop = false;

    VariableLimits = new Boundary[problem_size];

    for(int i = 0; i < HMS; ++i){
        Harmony Har(problem_size);
        Harmony_Memory.push_back(Har);
    }
    cout<<"Optimization problem has been initialized."<<endl;
}


/*! \brief Calculate a value of objective function.   */
double Optimization_Problem::Object_function(Harmony &H){

    // Lep.expression = Lep.P.parse(_equation).createCompiledExpression();

    //  Lep.namesOfVariables = Lep.expression.getVariables();
    // _problem_size = Lep.namesOfVariables.size();

    int ii = 0;
    for(string it:Lep.namesOfVariables){
        double &x =  Lep.expression.getVariableReference(it);
        x = H.GetVarX_of(ii);
        ii++;
    }
    return   Lep.expression.evaluate();
}

/*! \brief Setting limits for every variable.   */
void Optimization_Problem::SetVariableLimits(){

    for(int i=0; i<_problem_size; ++i){
        VariableLimits[i].Set(-10.0,10.0);
    }
}

void Optimization_Problem::SetVariableLimits(string var,double Low, double Up){

    //  Lep.namesOfVariables = Lep.expression.getVariables();
    //  _problem_size = Lep.namesOfVariables.size();
    std::set<string>::iterator current;
    current = Lep.namesOfVariables.find(var);
    if (current != Lep.namesOfVariables.end()){
        int index_of_element = std::distance(Lep.namesOfVariables.begin(), current);
        VariableLimits[index_of_element].Set(Low,Up);
    }

    this->InitHarmonyMemory();

}
void Optimization_Problem::SetVariableLimitLow(string var,double Low){

    std::set<string>::iterator current;
    current = Lep.namesOfVariables.find(var);
    if (current != Lep.namesOfVariables.end()){
        int index_of_element = std::distance(Lep.namesOfVariables.begin(), current);
        VariableLimits[index_of_element].SetLower(Low);
    }

    this->InitHarmonyMemory();

}

void Optimization_Problem::SetVariableLimitUpper(string var,double Low){
    std::set<string>::iterator current;
    current = Lep.namesOfVariables.find(var);
    if (current != Lep.namesOfVariables.end()){
        int index_of_element = std::distance(Lep.namesOfVariables.begin(), current);
        VariableLimits[index_of_element].SetUpper(Low);
    }

    this->InitHarmonyMemory();

}

/*! \brief Creates all necessary Harmonys and initialize them with random in their limits.    */
void Optimization_Problem::InitHarmonyMemory(){
    for( Harmony &iter:Harmony_Memory){
        iter.InitInBounds(VariableLimits);
        iter.SetValue( Object_function(iter) );
    }
    Harmony_Memory.sort(compareFun);
}

/*! \brief Prints out a list of Harmonys - Harmony Memory.    */
void Optimization_Problem::PrintHarmonyMemory(){
    cout<<"=========================="<<endl;
    cout<<"======Harmony Memory======"<<endl;
    cout<<"=========================="<<endl;
    cout<<setw(5)<<"value"<<setw(15);


    int index=0;
    for(string it:Lep.namesOfVariables){
        cout<<it;
        if(index < Lep.namesOfVariables.size() - 1 )
            cout<<setw(15);
        index++;
    }
    cout<<endl;

    for(Harmony &Zm:Harmony_Memory){
        Zm.Print(); //Print out value of object function
    }
}

/*! \brief Prints all settled limits for variable x1,x2,...,xn.    */
void Optimization_Problem::PrintVariableLimits(){
    cout<<"=========================="<<endl;
    cout<<"======Variable Limits====="<<endl;
    cout<<"=========================="<<endl;


    int index=0;
    for(string it:Lep.namesOfVariables){
        double low,up;
        VariableLimits[index].Get(low,up);
        cout<< it<<" : < "<< low <<","<< up <<" >"<<endl;
        index++;
    }
}

Harmony Optimization_Problem::ReturnBestSolution(){
    return *(this->Harmony_Memory.begin());
}

int Optimization_Problem::ReturnProgress(){
    return this->_progress_of_search;
}

bool  Optimization_Problem::AfterUpdate(){


    return true;
}

void  Optimization_Problem::SetEquation(string str){
    _equation = str;
    constants["pi"] = M_PI;
    constants["e"] = M_E;
    Lep.expression = Lep.P.parse(_equation).optimize(constants).createCompiledExpression();
    cout<<"PARSED: "<<Lep.P.parse(_equation).optimize(constants)<<endl;
    Lep.namesOfVariables = Lep.expression.getVariables();

    _problem_size = Lep.namesOfVariables.size();
}


/*! \brief Execute the main work of algoritm. Needs to be completed!    */
bool Optimization_Problem::Search(){

    std::uniform_real_distribution<double> rand_0_1(0.0,1.0);
    std::uniform_real_distribution<double> rand_minus1_1(-1.0,1.0);
    std::uniform_int_distribution<int> rand_0_HMS(0,this->_HMS-1);

    std::list<Harmony>::iterator iter;
    int index_of_drawed_harmony = 0;
    double X_value = 0;
    double Value_of_New_Harmony=0;

    _progress_of_search = 0;
    if(write_to_text_file){
        //    building a name of a file: e.g. "HS_AllSteps_repeat_1000_HMS_40.dat"
        QString filename = "HS_AllSteps_repeat_" + QString::number(_repeat) + "_HMS_" + QString::number(_HMS) + ".dat"; // "HS_AllSteps_repeat_1000_HMS_40.dat"
        //filePlot.open(filename.toStdString());
        filePlot.open(HARMONIES_ALL_FILE);
        fileVisu.open(HARMONIES_PARTICULAR_FILE);
    }
    while(_progress_of_search < _repeat  && !_algorithm_stop){

        QApplication::processEvents();

        Harmony Har(_problem_size);                          //Generate a new Harmony

        for(int var_index=0; var_index<_problem_size; ++var_index){     //Fill the values of variables in Har.
            iter = this->Harmony_Memory.begin();               //Set iterator to the first element in Harmony Memory - list

            if(rand_0_1(u) <= _HMCR){	                         //Choose from Harmony Memory
                index_of_drawed_harmony = rand_0_HMS(u);                  //Draw a number of Harmony from Harmony Memory - list
                std::advance (iter,index_of_drawed_harmony);     //Find a Harmony described by this number

                X_value = (*iter).GetVarX_of(var_index);         //Take a value of x variable
                //Check if it fulfills a condition of adjusting
                if(rand_0_1(u) < _PAR){//Do a adjustment
                    X_value = X_value + _bandwidth*rand_minus1_1(u);
                }
                else{
                    ;//Do nothing
                }
                double low,up;
                VariableLimits[var_index].Get(low,up);
                if(X_value < low) X_value = low;
                else if(X_value > up) X_value = up;


                Har.SetVarX_of(var_index, X_value);              //Write this x variable to our new generated Harmony

            }
            else{
                Har.SetVarX_InBounds(var_index, this->VariableLimits );
                //Har.SetVarX_of(var_index, X_value);
            }
        }
        //Here check if this new solution(new harmony) is better than the worst existing in Harmony Memory
        Value_of_New_Harmony = this->Object_function(Har);
        iter = this->Harmony_Memory.end();

        if( (*iter).GetValue() > Value_of_New_Harmony ){
            Harmony_Memory.pop_back();
            Har.SetValue(Value_of_New_Harmony);
            Harmony_Memory.push_back(Har);
            Harmony_Memory.sort(compareFun);
        }


        // Har.Print()

        if(write_to_text_file)        this->WriteSolution();

        _progress_of_search++;
    }
    if(write_to_text_file){
        filePlot.close();
        fileVisu.close();
    }

    return (_progress_of_search == _repeat);
}


void Optimization_Problem::WriteSolution(){
    int ilosc_przedzialow = 200;
    int tmp = 10;

    int progress = this->_progress_of_search;
    int repeat = this->_repeat;


    //WRITE for plot
    tmp = repeat/(ilosc_przedzialow);

    if(tmp<ilosc_przedzialow) { ilosc_przedzialow = repeat;  tmp = 1;}


    if(( (progress % tmp) == 0 ) || ( progress == (repeat-1) )){

        filePlot  <<progress<<"   "<<(*this->Harmony_Memory.begin()).GetValue()<<endl;
    }

    //WRITE for Visu
    ilosc_przedzialow = 10;
    tmp = (repeat)/(ilosc_przedzialow);
    if(tmp<ilosc_przedzialow) { ilosc_przedzialow = repeat;  tmp = 1;}

    if(progress == 0){
        fileVisu<<" "<<"Id"<<"         "<<"value"<<"           ";

        int index=0;
        for(string it:Lep.namesOfVariables){
            fileVisu<<it;
            if(index < Lep.namesOfVariables.size() - 1 )
                fileVisu<<"        ";
            index++;
        }
        fileVisu<<endl;

    }
    if (((progress % tmp) == 0  ) || ( progress == (repeat-1) )){
        fileVisu << progress<<"           " << (*this->Harmony_Memory.begin()).GetValue()<< "       ";
        for(int i = 0; i< this->_problem_size;++i){
            fileVisu <<  (*this->Harmony_Memory.begin()).GetVarX_of(i);
            if(i<this->_problem_size-1)
                fileVisu << "      ";
            else
                fileVisu<<endl;
        }

    }

}

Optimization_Problem::~Optimization_Problem(){
    cout<<"Optimization problem has been deleted."<<endl;
}


/****************************************************************/
/*! \brief Funtion which compere two elements on the list - Harmony Memory. Its needed to sort that list.    */
bool compareFun (const Harmony &first, const Harmony &second){
    return ( first.GetValue() < second.GetValue() );
}

