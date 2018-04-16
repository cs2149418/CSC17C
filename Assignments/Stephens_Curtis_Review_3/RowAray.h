/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2018, 8:54 AM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return this->size;}
        T getData(int i)const{
            if(i>=0&&i<this->size)return this->rowData[i];
            else return 0;}
        void setData(int,T);
};

#endif	/* ROWARAY_H */
