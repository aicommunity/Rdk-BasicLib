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

#include "rdk.h"

#include "UModel.h"

namespace RDK {

class RDK_LIB_TYPE UBCLLibrary: public ULibrary
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
virtual void CreateClassSamples(UStorage *storage);
// --------------------------
};          

extern RDK_LIB_TYPE UBCLLibrary BCLLibrary;

}


#endif
