#ifndef UMatrixSource_CPP
#define UMatrixSource_CPP

#include "UMatrixSource.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSource::UMatrixSource(void)
: DoubleMatrixInput("DoubleMatrixInput",this),
  IntMatrixInput("IntMatrixInput",this),
  DoubleVectorInput("DoubleVectorInput",this),
  IntVectorInput("IntVectorInput",this),

  DoubleMatrix("DoubleMatrix",this),
  IntMatrix("IntMatrix",this),
  DoubleVector("DoubleVector",this),
  IntVector("IntVector",this)
{
}

UMatrixSource::~UMatrixSource(void)
{

}
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UMatrixSource* UMatrixSource::New(void)
{                             
 return new UMatrixSource;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UMatrixSource::ADefault(void)
{
 return ASDefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UMatrixSource::ABuild(void)
{
 return ASBuild();
}

// Сброс процесса счета.
bool UMatrixSource::AReset(void)
{
 return ASReset();
}

// Выполняет расчет этого объекта
bool UMatrixSource::ACalculate(void)
{
 return ASCalculate();
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UMatrixSource::ASDefault(void)
{
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UMatrixSource::ASBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UMatrixSource::ASReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UMatrixSource::ASCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

