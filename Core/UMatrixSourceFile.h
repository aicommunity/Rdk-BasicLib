#ifndef UMatrixSourceFile_H
#define UMatrixSourceFile_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UMatrixSourceFile: public UNet
{
public: // Параметры
/// Имя файла с данными
ULProperty<std::string, UMatrixSourceFile> FileName;

/// Флаг необходимости проверки даты-времени обновления файла
ULProperty<bool, UMatrixSourceFile> IsCheckDateTime;

/// Флаг необходимости пропуска расчета если не было свежих данных
ULProperty<bool, UMatrixSourceFile> SkipCalcIfNoNewData;

/// Флаг наличия новых данных
ULProperty<bool, UMatrixSourceFile, ptPubState> IsNewData;

/// Использовать путь до источника видеоданных относительно папки конфигурации
ULProperty<bool, UMatrixSourceFile> UseRelativePathFromConfig;

/// Использовать путь до источника видеоданных относительно рабочей папки приложения
ULProperty<bool, UMatrixSourceFile> UseRelativePathFromWorkDir;

public: // Входные и выходные данные
/// Матрица double
UPropertyOutputData<MDMatrix<double>, UMatrixSourceFile, ptPubParameter | ptOutput> Matrix;


protected:

FILETIME LastWriteTime;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceFile(void);
virtual ~UMatrixSourceFile(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UMatrixSourceFile* New(void);
// --------------------------


// --------------------------
// Методы управления параметрами
// --------------------------
/// Использовать путь до источника видеоданных относительно папки конфигурации
bool SetUseRelativePathFromConfig(const bool &value);

/// Использовать путь до источника видеоданных относительно рабочей папки приложения
bool SetUseRelativePathFromWorkDir(const bool &value);
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

/// Расчитывает реальный путь до файла исходя из настроек относительных путей
std::string CalcActualSourceFilePath(const std::string &file_name);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

