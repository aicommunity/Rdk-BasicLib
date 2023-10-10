#ifndef UScalarSource_H
#define UScalarSource_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UScalarSource: public UNet
{
protected: // Параметры

public: // Входные и выходные данные
/// double
UPropertyOutputData<double, UScalarSource, ptPubParameter | ptOutput> Double;

/// long double
UPropertyOutputData<long double, UScalarSource, ptPubParameter | ptOutput> LDouble;

/// float
UPropertyOutputData<float, UScalarSource, ptPubParameter | ptOutput> Float;

/// int
UPropertyOutputData<int, UScalarSource, ptPubParameter | ptOutput> Int;

/// long
UPropertyOutputData<long, UScalarSource, ptPubParameter | ptOutput> Long;

/// unsigned long
UPropertyOutputData<unsigned long, UScalarSource, ptPubParameter | ptOutput> ULong;

/// long long
UPropertyOutputData<long, UScalarSource, ptPubParameter | ptOutput> LongLong;

/// unsigned long long
UPropertyOutputData<unsigned long, UScalarSource, ptPubParameter | ptOutput> ULongLong;


public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UScalarSource(void);
virtual ~UScalarSource(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UScalarSource* New(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
/// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ADefault(void);

/// Обеспечивает сборку внутренней структуры объекта
/// после настройки параметров
/// Автоматически вызывает метод Reset() и выставляет Ready в true
/// в случае успешной сборки
virtual bool ABuild(void);

/// Сброс процесса счета.
virtual bool AReset(void);

/// Выполняет расчет этого объекта
virtual bool ACalculate(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
/// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ASDefault(void);

/// Обеспечивает сборку внутренней структуры объекта
/// после настройки параметров
/// Автоматически вызывает метод Reset() и выставляет Ready в true
/// в случае успешной сборки
virtual bool ASBuild(void);

/// Сброс процесса счета.
virtual bool ASReset(void);

/// Выполняет расчет этого объекта
virtual bool ASCalculate(void);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

