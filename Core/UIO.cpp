#ifndef UAIO_CPP
#define UAIO_CPP

#include "UIO.h"
//#include "../../UBinaryEnvSerialize.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIO::UIO(void)
 : Direction("Direction", this)
{
}

UIO::~UIO(void)
{

}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UIO::ADefault(void)
{
 Direction=1;
 return AIODefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UIO::ABuild(void)
{
 return AIOBuild();
}

// Сброс процесса счета.
bool UIO::AReset(void)
{
 return AIOReset();
}

// Выполняет расчет этого объекта
bool UIO::ACalculate(void)
{
 return AIOCalculate();
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UIO::AIODefault(void)
{
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UIO::AIOBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UIO::AIOReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UIO::AIOCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

