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
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"

namespace RDK {

// ������
// --------------------------
// ������������ � �����������
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
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UModel* UModel::New(void)
{
 return new UModel();
}
// --------------------------



}
#endif


