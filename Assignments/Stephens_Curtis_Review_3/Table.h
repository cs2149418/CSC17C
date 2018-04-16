/* 
 * File:   Table.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2018, 8:54 AM
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

template <class T>
class Table:public AbsTabl<T>{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return this->szRow;}
        int getSzCol()const {return this->szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
};

#endif	/* TABLE_H */

