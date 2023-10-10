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
// Конструкторы и деструкторы
// --------------------------
UBCLLibrary::UBCLLibrary(void)
 : ULibrary("BCLLibrary","1.0", GetGlobalVersion())
{
}
// --------------------------

// --------------------------
// Методы заполенения бибилиотеки
// --------------------------
// Заполняет массив ClassSamples готовыми экземплярами образцов и их именами.
// Не требуется предварительная очистка массива и уборка памяти.
void UBCLLibrary::CreateClassSamples(UStorage *storage)
{
 RDK::UContainer *cont;

 cont=new UModel;
 cont->SetName("Model");
 cont->Default();
 UploadClass("UModel",cont);


 cont=new UStatisticMatrix<int>;
 cont->SetName("StatisticIntMatrix");
 cont->Default();
 UploadClass("UStatisticIntMatrix",cont);

 cont=new UStatisticMatrix<double>;
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

 cont=new UNoiseGen<double>;
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGenDouble",cont);

 cont=new UNoiseGen<double>;
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGen",cont);

 cont=new UNoiseGen<int>;
 cont->SetName("NoiseGen");
 cont->Default();
 UploadClass("UNoiseGenInt",cont);

  cont=new UMatrixSource;
 cont->SetName("MatrixSource");
 cont->Default();
 UploadClass("UMatrixSource",cont);

 cont=new UScalarSource;
 cont->SetName("ScalarSource");
 cont->Default();
 UploadClass("UScalarSource",cont);

 //UMatrixSourceTimeSeries
 cont=new UMatrixSourceTimeSeries;
 cont->SetName("MatrixSourceTimeSeries");
 cont->Default();
 UploadClass("UMatrixSourceTimeSeries",cont);

 //UMatrixSourceDataFile
 cont=new UMatrixSourceDataFile;
 cont->SetName("UMatrixSourceDataFile");
 cont->Default();
 UploadClass("UMatrixSourceDataFile",cont);


#ifdef WIN32
 cont=new UMatrixSourceFile;
 cont->SetName("UMatrixSourceFile");
 cont->Default();
 UploadClass("UUMatrixSourceFile",cont);

 cont=new UMatrixSourceFileSep;
 cont->SetName("MatrixSourceFileSep");
 cont->Default();
 UploadClass("UMatrixSourceFileSep",cont);

 cont=new UFileDataset;
 cont->SetName("FileDataset");
 cont->Default();
 UploadClass("UFileDataset",cont);
#endif
}
// --------------------------


}

#endif

