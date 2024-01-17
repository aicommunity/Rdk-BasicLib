#ifndef UFileDataset_CPP
#define UFileDataset_CPP

#include "UFileDataset.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UFileDataset::UFileDataset(void)
: NumSamples("NumSamples",this),
  CurrentSample("CurrentSample",this),
  SampleData("SampleData",this)
{
}

UFileDataset::~UFileDataset(void)
{

}
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UFileDataset* UFileDataset::New(void)
{                             
 return new UFileDataset;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UFileDataset::ADefault(void)
{
 if(!UMatrixSourceFileSep::ADefault())
  return false;

 CurrentSample=0;
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UFileDataset::ABuild(void)
{
 if(!UMatrixSourceFileSep::ABuild())
  return false;

 return true;
}

// Сброс процесса счета.
bool UFileDataset::AReset(void)
{
 if(!UMatrixSourceFileSep::AReset())
  return false;

 NumSamples=Matrix->GetRows();

 if(CurrentSample>=0 && CurrentSample.v<NumSamples.v)
  SampleData=Matrix->GetRow(CurrentSample);
 else
  SampleData->Resize(0,0);

 return true;
}

// Выполняет расчет этого объекта
bool UFileDataset::ACalculate(void)
{
 if(!UMatrixSourceFileSep::ACalculate())
  return false;

 NumSamples=Matrix->GetRows();
 if(CurrentSample.v>=0 && CurrentSample.v<NumSamples.v)
  SampleData=Matrix->GetRow(CurrentSample);
 else
  SampleData->Resize(0,0);


 return true;
}

// --------------------------

}
#endif

