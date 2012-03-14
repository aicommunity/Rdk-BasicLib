/* ***********************************************************
@Copyright Alexander V. Bakhshiev, 2012.
E-mail:         alexab@ailab.ru
url:            http://ailab.ru
Version:        1.0.0

This file - part of the project: RDK

File License:        BSD License
See file license.txt for more information
*********************************************************** */

#ifndef UBCLLibraryH
#define UBCLLibraryH

#include "../../UALibrary.h"

#include "UNet.h"
#include "UModel.h"

namespace RDK {

class UBCLLibrary: public UALibrary
{
public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UBCLLibrary(void);
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
virtual void CreateClassSamples(UAStorage *storage);
// --------------------------
};          

extern UBCLLibrary BCLLibrary;

}


#endif
