#ifndef MYLEPTON_HH
#define MYLEPTON_HH

#include "Lepton.h"

#include <set>

/*!
 * \file
 * \brief The file contains a definition of MyLepton class.
 *
 */


/*!
 * \brief
 */
class MyLepton{
public:
    Lepton::Parser P;
    Lepton::CompiledExpression expression;
    std::set<string> namesOfVariables;
};



#endif
