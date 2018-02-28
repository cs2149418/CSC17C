/* 
 * File:   RowAray.h
 * Author: Curtis Stephens
 * Created on February 22nd, 2018, 8:36 PM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

class RowAray{
    private:
        int size;
        int *rowData;
    public:
        RowAray(int);
        ~RowAray();
        int getSize();
        int getData(int i);
};

#endif	/* ROWARAY_H */