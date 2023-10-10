//---------------------------------------------------------------------------

#ifndef UIOTextConverterH
#define UIOTextConverterH

#include "UIOConverter.h"
#include <string>

namespace RDK{

class RDK_LIB_TYPE UIOTextConverter: public UIOConverter
{
public: // Параметры
/// Режим ввода данных
/// 0 - двоичный
/// 1 - текстовый, считывать столбцы - каждый стобец->выходной вектор
/// 2 - текстовый, считывать строки - каждая строка->выходной вектор
ULProperty<int, UIOTextConverter> InputMode;

/// Режим вывода данных
/// 0 - двоичный
/// 1 - текстовый, записывать столбцы - каждый выходной вектор->стобец
/// 2 - текстовый, записывать строки - каждый выходной вектор->строка
ULProperty<int, UIOTextConverter> OutputMode;

/// Максимальное число обрабатываемых строк/столбцов
ULProperty<int, UIOTextConverter> MaxColumns;

public: // Входы и выходы
/// Записываемые данные
UPropertyInputData<MDMatrix<double>, UIOTextConverter> Input;

/// Прочитанные данные
UPropertyOutputData<MDMatrix<double>, UIOTextConverter> Output;

protected: // Временные переменные
std::string OutData;
std::vector<string> Separate1;
std::vector<string> Separate2;

std::vector<UItemData> DataAfterRead;


public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIOTextConverter(void);
virtual ~UIOTextConverter(void);
// --------------------------

// --------------------------
// Методы управления параметрами
// --------------------------
bool SetInputMode(const int &value);

bool SetOutputMode(const int &value);

bool SetMaxColumns(const int &value);
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UIOTextConverter* New(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool AIODefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool AIOBuild(void);

// Сброс процесса счета.
virtual bool AIOReset(void);

// Выполняет расчет этого объекта
virtual bool AIOCalculate(void);
// --------------------------

// --------------------------
// Вспомогательные методы расчета
// --------------------------
protected:
// Преобразовываем строку текста в прототип стандартных входных данных
void ConvertFromTextColumns(const string &text, std::vector<UItemData> &data);
void ConvertFromTextRows(const string &text, std::vector<UItemData> &data);

// Преобразовываем стандартные входные данные в строку текста
void ConvertToTextColumns(const std::vector<UItemData> &data, string &text);
void ConvertToTextRows(const std::vector<UItemData> &data, string &text);
// --------------------------

};




//---------------------------------------------------------------------------
}
#endif

