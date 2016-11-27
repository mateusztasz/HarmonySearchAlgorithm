#ifndef BOUNDARY_HH
#define BOUNDARY_HH

/*!
 * \file
 * \brief The file contains a definition of Boundary Class
 *
 */


/*!
 * \brief Models the boundary for every variable x1,x2,....,xn .
 */
class Boundary{
private:

    double lower; /*!< \brief Minimum of possible variable value.  */
    double upper; /*!< \brief Maximimum of possible variable value.     */

public:
    /*! \brief Constructor of Boundary    */
    Boundary();
    /*! \brief Giving an access to member lower and upper.     */
    void Get(double &low, double &up);
    /*! \brief Setting lower and upper boundary as given argument    */
    void Set(double low, double up);

    void SetLower(double low);

    void SetUpper(double up);
    ~Boundary();
};


#endif
