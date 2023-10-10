#ifndef UMatrixSourceDataFile_CPP
#define UMatrixSourceDataFile_CPP


#ifdef _WIN32
#include <windows.h>
#endif

#include "UMatrixSourceDataFile.h"

#include <vector>
#include <fstream>

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceDataFile::UMatrixSourceDataFile(void)
:
  FileName("FileName",this),
  IsCheckDateTime("IsCheckDateTime",this),
  SkipCalcIfNoNewData("SkipCalcIfNoNewData",this),
  UseRelativePathFromConfig("UseRelativePathFromConfig",this,&UMatrixSourceDataFile::SetUseRelativePathFromConfig),
  UseRelativePathFromWorkDir("UseRelativePathFromWorkDir",this,&UMatrixSourceDataFile::SetUseRelativePathFromWorkDir),
  IsNewData("IsNewData",this),
  FullMatrix("FullMatrix",this),
  ReloadFile("ReloadFile",this),
  RowCount("RowCount",this),
  ColCount("ColCount", this)
{
  ReloadFile = true;
}

UMatrixSourceDataFile::~UMatrixSourceDataFile(void)
{

}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UMatrixSourceDataFile* UMatrixSourceDataFile::New(void)
{
 return new UMatrixSourceDataFile;
}
// --------------------------


// --------------------------
// Методы управления параметрами
// --------------------------
/// Использовать путь до источника видеоданных относительно папки конфигурации
bool UMatrixSourceDataFile::SetUseRelativePathFromConfig(const bool &value)
{
 UseRelativePathFromWorkDir=false;
 Ready=false;
 return true;
}

/// Использовать путь до источника видеоданных относительно рабочей папки приложения
bool UMatrixSourceDataFile::SetUseRelativePathFromWorkDir(const bool &value)
{
 UseRelativePathFromConfig=false;
 Ready=false;
 return true;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UMatrixSourceDataFile::ADefault(void)
{
 FileName="";
 IsCheckDateTime=true;
 SkipCalcIfNoNewData=true;
 UseRelativePathFromWorkDir=false;
 UseRelativePathFromConfig=true;
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UMatrixSourceDataFile::ABuild(void)
{
 ReloadFile=true; //?
 return true;
}

// Сброс процесса счета.
bool UMatrixSourceDataFile::AReset(void)
{
 IsNewData=false;
 ReloadFile = true;
 return true;
}

// Выполняет расчет этого объекта
bool UMatrixSourceDataFile::ACalculate(void)
{
 bool res = true;
 if(ReloadFile.v==true)
 {
  std::string file_name=CalcActualSourceFilePath(FileName);
  res = ReadAndDecode(file_name);
  if(res)
  {
      ReloadFile.v = false; //И сразу выключаем, чтобы не делать это каждый раз
  }
 }


 if(!res)
 {
  //Тут должно быть что-то другое, типа возврата false?
  if(GetOwner())
   GetOwner()->ForceSkipComponentCalculation();

  return true;
 }

 return true;
}

/// Выполняет чтение, декодирование и выдачу данных
bool UMatrixSourceDataFile::ReadAndDecode(const std::string &file_name)
{
 std::ifstream datafile;
 datafile.open(file_name, std::ifstream::in);

 if(datafile.good())
 {
  int line_cnt = -1;
  int col_cnt = -1;
  datafile>>line_cnt;
  datafile>>col_cnt;

  MDMatrix<double> m;
  m.Resize(line_cnt, col_cnt);

  for(int i=0; i<line_cnt; i++)
  {
   for(int j=0; j<col_cnt; j++)
   {
    if(datafile.good())
    {
     datafile>>m(i, j);
    }
    else {
     return false;
    }
   }
  }
  *FullMatrix=m;
 }
 else
  return true;

 return true;
}


/// Расчитывает реальный путь до файла исходя из настроек относительных путей
std::string UMatrixSourceDataFile::CalcActualSourceFilePath(const std::string &file_name)
{
 std::string clean_file_name=trim_spaces(file_name);

 if(clean_file_name.empty())
  return clean_file_name;

 if(!UseRelativePathFromConfig && !UseRelativePathFromWorkDir)
  return clean_file_name;

 std::string file_path;

 if(clean_file_name.substr(0,2) == "./" || clean_file_name.substr(0,2) == ".\\")
  clean_file_name=clean_file_name.substr(2);

 if(UseRelativePathFromConfig)
 {
  if(GetEnvironment())
   file_path=GetEnvironment()->GetCurrentDataDir()+clean_file_name;
 }

 if(UseRelativePathFromWorkDir)
 {
  if(GetEnvironment())
   file_path=GetEnvironment()->GetSystemDir()+clean_file_name;
 }
 return file_path;
}

// --------------------------

}
#endif

