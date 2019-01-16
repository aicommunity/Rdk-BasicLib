/* ***********************************************************
@Copyright Alexander V. Bakhshiev, 2012.
E-mail:         alexab@ailab.ru
url:            http://ailab.ru
Version:        1.0.0

This file - part of the project: RDK

File License:        BSD License
See file license.txt for more information
*********************************************************** */
#ifndef UBCLLibraryCPP
#define UBCLLibraryCPP

#include "UBCLLibrary.h"

namespace RDK {

UBCLLibrary BCLLibrary;

// --------------------------
// ������������ � �����������
// --------------------------
UBCLLibrary::UBCLLibrary(void)
 : ULibrary("BCLLibrary","1.0", GetGlobalVersion())
{
}
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
void UBCLLibrary::CreateClassSamples(UStorage *storage)
{
 RDK::UContainer *cont;

 /*cont=new UNet;
 cont->SetName("Net");
 cont->Default();
 UploadClass("UNet",cont);
   */
 cont=new UModel;
 cont->SetName("Model");
 cont->Default();
 UploadClass("UModel",cont);
}
// --------------------------


}

#endif

