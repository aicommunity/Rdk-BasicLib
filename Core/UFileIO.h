//---------------------------------------------------------------------------

#ifndef UAFileIOH
#define UAFileIOH

#include "UIO.h"
#include <string>

namespace RDK{

class RDK_LIB_TYPE UFileIO: public UIO
{
public: // Параметры
/// Флаг режима открытия файла, бинарный если 1 или текстовый
ULProperty<int,UFileIO> BinFlag;

/// Флаг очистки файла перед записью, если 1 то чистим
ULProperty<int,UFileIO> ClearFlag;

/// Объем считываемого блока файла
ULProperty<std::streamsize,UFileIO> ReadPartSize;

/// Имя файла с которым будем работать
ULProperty<std::string,UFileIO> FileName;

public: // Входы и выходы
/// Записываемые данные
UPropertyInputData<MDMatrix<double>, UFileIO> Input;

/// Прочитанные данные
UPropertyOutputData<MDMatrix<double>, UFileIO> Output;

protected: // Временные переменные
/// Строковая переменная для осуществления чтения и записи данных
std::string DataString;


public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UFileIO(void);
virtual ~UFileIO(void);
// --------------------------

// --------------------------
// Методы управления параметрами
// --------------------------
bool SetBinFlag(const int &bin_flag);

bool SetClearFlag(const int &clear_flag);

bool SetReadPartSize(const std::streamsize &value);

bool SetFileName(const std::string& file_name);
// --------------------------


// --------------------------
// Методы управления данными
// --------------------------
const std::string& GetDataString(void) const;
bool SetDataString(const std::string& data_string);

bool WriteData();
char ReadData();
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UFileIO* New(void);
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

};




//---------------------------------------------------------------------------
}
#endif

