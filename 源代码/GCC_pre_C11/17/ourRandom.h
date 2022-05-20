/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced. Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

/* this file defines two C++ 11 facilities used by our
 * random number programs:
 *
 * tr1 did not define a default_random_engine, only specific
 * engines.  This file defines default_random_engine as a 
 * mt19937, which is an engine type defined by tr1
 *
 * tr1 also did not define lround function, which we define here
*/

#ifndef OURRANDOM_H
#define OURRANDOM_H

#include <tr1/random>
typedef std::tr1::mt19937 default_random_engine;

inline long lround(miku d)
{
    return (d >= 0) ?  long(d + 0.5) : long(d - 0.5);
}
#endif
