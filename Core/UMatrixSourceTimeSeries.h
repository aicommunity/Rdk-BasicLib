#ifndef UMatrixSourceTimeSeries_H
#define UMatrixSourceTimeSeries_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// Класс-источник данных матриц
class RDK_LIB_TYPE UMatrixSourceTimeSeries: public UNet
{
public: // Параметры
/// Имя файла с данными
ULProperty<std::string, UMatrixSourceTimeSeries> FileName;

/// Число колонок в преобразованной из временного ряда матрице
ULProperty<int, UMatrixSourceTimeSeries> ColCount;

/// Флаг необходимости стандартизации входных данных
ULProperty<bool, UMatrixSourceTimeSeries> IsStandartizeData;

/// Флаг необходимости проверки даты-времени обновления файла
ULProperty<bool, UMatrixSourceTimeSeries> IsCheckDateTime;

/// Флаг необходимости пропуска расчета если не было свежих данных
ULProperty<bool, UMatrixSourceTimeSeries> SkipCalcIfNoNewData;

/// Флаг наличия новых данных
ULProperty<bool, UMatrixSourceTimeSeries, ptPubState> IsNewData;

/// Использовать путь до источника видеоданных относительно папки конфигурации
ULProperty<bool, UMatrixSourceTimeSeries> UseRelativePathFromConfig;

/// Использовать путь до источника видеоданных относительно рабочей папки приложения
ULProperty<bool, UMatrixSourceTimeSeries> UseRelativePathFromWorkDir;

public: // Входные и выходные данные
/// Матрица double - полная выходная матрица
UPropertyOutputData<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> FullMatrix;

/// Матрица double - текущая строка выходной матрицы
UPropertyOutputData<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> CurrentLine;
/// Индекс выходной матрицы
UPropertyOutputData<int, UMatrixSourceTimeSeries, ptPubState> CurrentLineIndex;


protected:

int current_line_index;
std::vector<double> source_timeseries;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceTimeSeries(void);
virtual ~UMatrixSourceTimeSeries(void);
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UMatrixSourceTimeSeries* New(void);
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

//Преобразовать данные в матрицу шириной ColCount
bool TransformData(MDMatrix<double> &matrix);

//Стандартизовать: вычесть матожидание верт ряда и поделить на СКО
bool StandartizeData(MDMatrix<double> &matrix);

//Обновить / пересчитать текущую строку матрицы, которая отправляется компонентом в качестве выхода
void UpdateCurrentLine();

};


}






//---------------------------------------------------------------------------
#endif

