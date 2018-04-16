/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2018, 8:54 AM
 * Specification for the abstract Table Class
 */

#ifndef ABSTABL_H
#define	ABSTABL_H

#include "RowAray.h"

template <class T>
class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual T getData(int,int)const = 0;
};

#endif	/* ABSTABL_H */

