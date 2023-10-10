#ifndef UFileDataset_H
#define UFileDataset_H

#include "UMatrixSourceFileSep.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UFileDataset: public UMatrixSourceFileSep
{
public:
/// Число примеров в датасете
ULProperty<int, UFileDataset, ptPubState> NumSamples;

/// Индекс текущего примера
ULProperty<int, UFileDataset> CurrentSample;

/// Текущий пример
ULProperty<MDMatrix<double>, UFileDataset, ptPubOutput | ptState> SampleData;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UFileDataset(void);
virtual ~UFileDataset(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UFileDataset* New(void);
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


};


}






//---------------------------------------------------------------------------
#endif

