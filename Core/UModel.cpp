/* ***********************************************************
@Copyright Alexander V. Bakhshiev, 2012.
E-mail:		alexab@ailab.ru
url:            http://ailab.ru

This file - part of the project: RDK

File License:        BSD License
Project License:     BSD License
See file license.txt for more information
*********************************************************** */
#ifndef UMODEL_CPP
#define UMODEL_CPP

#include "UModel.h"

namespace RDK {

// Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UModel::UModel(void)
//: NANet(name)
{
}

UModel::~UModel(void)
{
}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UModel* UModel::New(void)
{
 return new UModel;
}
// --------------------------



}
#endif


