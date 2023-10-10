#ifndef UMatrixSourceFile_CPP
#define UMatrixSourceFile_CPP


#ifdef _WIN32
#include <windows.h>
#endif
#include "UMatrixSourceFile.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceFile::UMatrixSourceFile(void)
:
  FileName("FileName",this),
  IsCheckDateTime("IsCheckDateTime",this),
  SkipCalcIfNoNewData("SkipCalcIfNoNewData",this),
  UseRelativePathFromConfig("UseRelativePathFromConfig",this,&UMatrixSourceFile::SetUseRelativePathFromConfig),
  UseRelativePathFromWorkDir("UseRelativePathFromWorkDir",this,&UMatrixSourceFile::SetUseRelativePathFromWorkDir),
  IsNewData("IsNewData",this),
  Matrix("Matrix",this)
{
}

UMatrixSourceFile::~UMatrixSourceFile(void)
{

}
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UMatrixSourceFile* UMatrixSourceFile::New(void)
{                             
 return new UMatrixSourceFile;
}
// --------------------------


// --------------------------
// Методы управления параметрами
// --------------------------
/// Использовать путь до источника видеоданных относительно папки конфигурации
bool UMatrixSourceFile::SetUseRelativePathFromConfig(const bool &value)
{
 UseRelativePathFromWorkDir=false;
 Ready=false;
 return true;
}

/// Использовать путь до источника видеоданных относительно рабочей папки приложения
bool UMatrixSourceFile::SetUseRelativePathFromWorkDir(const bool &value)
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
bool UMatrixSourceFile::ADefault(void)
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
bool UMatrixSourceFile::ABuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UMatrixSourceFile::AReset(void)
{
 IsNewData=false;
 return true;
}

// Выполняет расчет этого объекта
bool UMatrixSourceFile::ACalculate(void)
{
 std::string file_name=CalcActualSourceFilePath(FileName);
 if(IsCheckDateTime)
 {
#ifdef _WIN32

  HANDLE file_handle= CreateFileA(
  file_name.c_str(),
  GENERIC_READ,
  FILE_SHARE_READ,
  0,
  OPEN_EXISTING,
  FILE_ATTRIBUTE_NORMAL,
  0);

  if(file_handle != INVALID_HANDLE_VALUE)
  {
   FILETIME newCreationTime;
   FILETIME newLastAccessTime;
   FILETIME newLastWriteTime;

   BOOL res=GetFileTime(file_handle, &newCreationTime, &newLastAccessTime, &newLastWriteTime);
   CloseHandle(file_handle);

   if(res)
   {
	if(memcmp(&newLastWriteTime,&LastWriteTime, sizeof(LastWriteTime)) != 0)
	{
	 LastWriteTime=newLastWriteTime;
	 IsNewData=true;
    }
   }
  }
#endif
 }

 if(SkipCalcIfNoNewData && !IsNewData)
 {
  if(GetOwner())
   GetOwner()->ForceSkipComponentCalculation();

  return true;
 }

 if(!IsNewData)
  return true;
 IsNewData=false;

 return ReadAndDecode(file_name);
}

/// Выполняет чтение, декодирование и выдачу данных
bool UMatrixSourceFile::ReadAndDecode(const std::string &file_name)
{
 USerStorageXML xml;

 if(SkipCalcIfNoNewData.v == true)
 {
  if(!xml.LoadFromFile(file_name,"Matrix"))
  {
   if(GetOwner())
    GetOwner()->ForceSkipComponentCalculation();
   return true;
  }
 }
 else
 if(!xml.LoadFromFile(file_name,"Matrix"))
  return true;


 MDMatrix<double> out;
 xml>>out;
 *Matrix=out;

 return true;
}


/// Расчитывает реальный путь до файла исходя из настроек относительных путей
std::string UMatrixSourceFile::CalcActualSourceFilePath(const std::string &file_name)
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

