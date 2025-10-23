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

UBasicLib BasicLibrary;

// --------------------------
// ������������ � �����������
// --------------------------
UBasicLib::UBasicLib(void)
 : ULibrary("BasicLib","1.0", GetGlobalVersion())
{
}
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
void UBasicLib::CreateClassSamples(UStorage *storage)
{
 std::shared_ptr<RDK::UContainer> cont;

 cont=std::make_shared<UModel>();
 cont->SetName("Model");
 cont->Default();
 UploadClass("UModel",cont);


 cont=std::make_shared<UStatisticMatrix<int>>();
 cont->SetName("StatisticIntMatrix");
 cont->Default();
 UploadClass("UStatisticIntMatrix",cont);

 cont=std::make_shared<UStatisticMatrix<double>>();
 cont->SetName("StatisticDoubleMatrix");
 cont->Default();
 UploadClass("UStatisticDoubleMatrix",cont);

     /*
 UContainer *cont;
 cont=new UFileIO;
 cont->SetName("FileIO");
 cont->Default();
 UploadClass("UFileIO",cont);

 cont=new UIOTextConverter;
 cont->SetName("IOTextConverter");
 cont->Default();
 UploadClass("UIOTextConverter",cont);*/

 cont=std::make_shared<UNoiseGen<double>>();
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGenDouble",cont);

 cont=std::make_shared<UNoiseGen<double>>();
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGen",cont);

 cont=std::make_shared<UNoiseGen<int>>();
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGenInt",cont);

  cont=std::make_shared<UMatrixSource>();
 cont->SetName("MatrixSource");
 cont->Default();
 UploadClass("UMatrixSource",cont);

 cont=std::make_shared<UScalarSource>();
 cont->SetName("ScalarSource");
 cont->Default();
 UploadClass("UScalarSource",cont);

 //UMatrixSourceTimeSeries
 cont=std::make_shared<UMatrixSourceTimeSeries>();
 cont->SetName("MatrixSourceTimeSeries");
 cont->Default();
 UploadClass("UMatrixSourceTimeSeries",cont);

 //UMatrixSourceDataFile
 cont=std::make_shared<UMatrixSourceDataFile>();
 cont->SetName("UMatrixSourceDataFile");
 cont->Default();
 UploadClass("UMatrixSourceDataFile",cont);


#ifdef WIN32
 cont=std::make_shared<UMatrixSourceFile>();
 cont->SetName("UMatrixSourceFile");
 cont->Default();
 UploadClass("UUMatrixSourceFile",cont);

 cont=std::make_shared<UMatrixSourceFileSep>();
 cont->SetName("MatrixSourceFileSep");
 cont->Default();
 UploadClass("UMatrixSourceFileSep",cont);

 cont=std::make_shared<UFileDataset>();
 cont->SetName("FileDataset");
 cont->Default();
 UploadClass("UFileDataset",cont);
#endif
}
// --------------------------


}

#endif

