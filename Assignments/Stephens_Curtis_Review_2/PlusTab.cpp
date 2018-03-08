/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlusTab.cpp
 * Author: curtisstephens
 * 
 * Created on March 6, 2018, 8:35 PM
 */

#include "PlusTab.h"


PlusTab PlusTab::operator +(const PlusTab &rhs)
{
  PlusTab temp(this->szRow,this->szCol); 
  for(int i=0;i<szCol;i++)
      for(int j=0;j<szRow;j++)
          temp.setData(i,j,rhs.getData(i,j)*2);
  return temp;
}

