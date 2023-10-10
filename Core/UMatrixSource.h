#ifndef UMatrixSource_H
#define UMatrixSource_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UMatrixSource: public UNet
{
protected: // Параметры

public: // Входные и выходные данные
/// Матрица double
UPropertyInputData<MDMatrix<double>, UMatrixSource> DoubleMatrixInput;

/// Матрица int
UPropertyInputData<MDMatrix<int>, UMatrixSource> IntMatrixInput;

/// Вектор double
UPropertyInputData<MDVector<double>, UMatrixSource> DoubleVectorInput;

/// Вектор int
UPropertyInputData<MDVector<int>, UMatrixSource> IntVectorInput;

/// Матрица double
UPropertyOutputData<MDMatrix<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleMatrix;

/// Матрица int
UPropertyOutputData<MDMatrix<int>, UMatrixSource, ptPubParameter | ptOutput> IntMatrix;

/// Вектор double
UPropertyOutputData<MDVector<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleVector;

/// Вектор int
UPropertyOutputData<MDVector<int>, UMatrixSource, ptPubParameter | ptOutput> IntVector;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSource(void);
virtual ~UMatrixSource(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UMatrixSource* New(void);
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

