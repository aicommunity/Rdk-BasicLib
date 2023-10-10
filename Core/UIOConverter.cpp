#ifndef UAIOConverter_CPP
#define UAIOConverter_CPP

#include "UIOConverter.h"
//#include "../../UBinaryEnvSerialize.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIOConverter::UIOConverter(void)
{
}

UIOConverter::~UIOConverter(void)
{

}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
//virtual NNeuronLife* New(void);
// --------------------------


// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UIOConverter::ADefault(void)
{
// SetNumOutputs(1);
 return AIODefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UIOConverter::ABuild(void)
{
 return AIOBuild();
}

// Сброс процесса счета.
bool UIOConverter::AReset(void)
{
 return AIOReset();
}

// Выполняет расчет этого объекта
bool UIOConverter::ACalculate(void)
{
 return AIOCalculate();
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UIOConverter::AIODefault(void)
{
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UIOConverter::AIOBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UIOConverter::AIOReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UIOConverter::AIOCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

