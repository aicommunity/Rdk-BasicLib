#ifndef UMatrixSourceFileSep_CPP
#define UMatrixSourceFileSep_CPP

#include "UMatrixSourceFileSep.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UMatrixSourceFileSep::UMatrixSourceFileSep(void)
: Separator("Separator",this)
{
}

UMatrixSourceFileSep::~UMatrixSourceFileSep(void)
{

}
// --------------------------    

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UMatrixSourceFileSep* UMatrixSourceFileSep::New(void)
{                             
 return new UMatrixSourceFileSep;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UMatrixSourceFileSep::ADefault(void)
{
 if(!UMatrixSourceFile::ADefault())
  return false;

 Separator=",";
 IsCheckDateTime=true;
 SkipCalcIfNoNewData=false;
 UseRelativePathFromWorkDir=false;
 UseRelativePathFromConfig=true;
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UMatrixSourceFileSep::ABuild(void)
{
 if(!UMatrixSourceFile::ABuild())
  return false;

 return true;
}

// Сброс процесса счета.
bool UMatrixSourceFileSep::AReset(void)
{
 if(!UMatrixSourceFile::AReset())
  return false;

 return true;
}

// Выполняет расчет этого объекта
bool UMatrixSourceFileSep::ACalculate(void)
{
 if(!UMatrixSourceFile::ACalculate())
  return false;

 return true;
}

/// Выполняет чтение, декодирование и выдачу данных
bool UMatrixSourceFileSep::ReadAndDecode(const std::string &file_name)
{
 std::string buffer;
 Matrix->Resize(0,0);
 if(SkipCalcIfNoNewData.v == true)
 {
  if(!LoadFile(file_name, buffer) || Separator->empty())
  {
   if(GetOwner())
	GetOwner()->ForceSkipComponentCalculation();
   return true;
  }
 }
 else
 if(!LoadFile(file_name, buffer) || Separator->empty())
  return true;

 std::vector<std::string> lines;
 separatestring(buffer,lines,'\n');

 int rows=int(lines.size());
 Matrix->Resize(rows,1);

 for(int i=0;i<int(lines.size());i++)
 {
  std::vector<std::string> elems;
  separatestring(lines[i],elems,Separator.v[0]);
  int cols=int(elems.size());
  Matrix->Resize(rows,cols);
  for(int j=0;j<int(elems.size());j++)
   Matrix(i,j)=atoi(elems[j]);
 }

 return true;
}

// --------------------------

}
#endif

