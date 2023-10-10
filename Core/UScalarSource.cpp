#ifndef UScalarSource_CPP
#define UScalarSource_CPP

#include "UScalarSource.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UScalarSource::UScalarSource(void)
: Double("Double",this),
  LDouble("LDouble",this),
  Float("Float",this),
  Int("Int",this),
  Long("Long",this),
  ULong("ULong",this),
  LongLong("LongLong",this),
  ULongLong("ULongLong",this)
{
}

UScalarSource::~UScalarSource(void)
{

}
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UScalarSource* UScalarSource::New(void)
{                             
 return new UScalarSource;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UScalarSource::ADefault(void)
{
 return ASDefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UScalarSource::ABuild(void)
{
 return ASBuild();
}

// Сброс процесса счета.
bool UScalarSource::AReset(void)
{
 return ASReset();
}

// Выполняет расчет этого объекта
bool UScalarSource::ACalculate(void)
{
 return ASCalculate();
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UScalarSource::ASDefault(void)
{
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UScalarSource::ASBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UScalarSource::ASReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UScalarSource::ASCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

