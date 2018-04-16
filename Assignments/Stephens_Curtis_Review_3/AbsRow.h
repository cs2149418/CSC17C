/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2018, 8:54 AM
 * Specification for the Abstract Row Array Class
 */

#ifndef ABSROW_H
#define	ABSROW_H

template <class T>
class AbsRow{
    protected:
        int size;
        T *rowData;
    public:
        virtual int getSize()const = 0;
        virtual T getData(int)const = 0;
};

#endif	/* ABSROW_H */

