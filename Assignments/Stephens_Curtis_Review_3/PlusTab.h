/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2018, 8:54 AM
 * Specification for the Table addition operator
 */

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

template <class T>
class PlusTab:public Table<T>
{
    public:
        PlusTab(unsigned int r,unsigned int c):Table<T>(r,c){};
        T &operator+(const Table<T> &);
};

#endif	/* PLUSTAB_H */