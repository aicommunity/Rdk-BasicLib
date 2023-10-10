#ifndef UMatrixSourceFileSep_H
#define UMatrixSourceFileSep_H

#include "UMatrixSourceFile.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UMatrixSourceFileSep: public UMatrixSourceFile
{
public:
/// Символ-разделитель
ULProperty<std::string,UMatrixSourceFileSep> Separator;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceFileSep(void);
virtual ~UMatrixSourceFileSep(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UMatrixSourceFileSep* New(void);
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

/// Выполняет чтение, декодирование и выдачу данных
virtual bool ReadAndDecode(const std::string &file_name);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

