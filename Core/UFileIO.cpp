#ifndef UAFileIO_CPP
#define UAFileIO_CPP

#include <iostream>
#include <fstream>
#include "UFileIO.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UFileIO::UFileIO(void)
: BinFlag("BinFlag", this, &UFileIO::SetBinFlag),
 ClearFlag("ClearFlag", this, &UFileIO::SetClearFlag),
 ReadPartSize("ReadPartSize", this, &UFileIO::SetReadPartSize),
 FileName("FileName", this, &UFileIO::SetFileName),
 Input("Input", this),
 Output("Output", this)
{
}

UFileIO::~UFileIO(void)
{

}
// --------------------------

// --------------------------
// Методы управления параметрами
// --------------------------
bool UFileIO::SetBinFlag(const int &bin_flag)
{
 return true;
}

bool UFileIO::SetFileName(const std::string& file_name)
{
 return true;
}

bool UFileIO::SetClearFlag(const int &clear_flag)
{
 return true;
}

bool UFileIO::SetReadPartSize(const std::streamsize &value)
{
 return true;
}
// --------------------------


// --------------------------
// Методы управления данными
// --------------------------
const std::string& UFileIO::GetDataString(void) const
{
 return DataString;
}

bool UFileIO::SetDataString(const std::string& data_string)
{
 if(DataString == data_string)
  return true;
 DataString = data_string;
  return true;
}

bool UFileIO::WriteData()
{
 std::fstream ofs;

 if(BinFlag)
  {
   if(ClearFlag) ofs.open(FileName->c_str(), ios::out| ios::trunc | ios::binary);
   if(!ClearFlag) ofs.open(FileName->c_str(), ios::out| ios::app | ios::binary);
  }
 else
  {
   if(ClearFlag) ofs.open(FileName->c_str(), ios::out| ios::trunc);
   if(!ClearFlag) ofs.open(FileName->c_str(), ios::out| ios::app);
  }

 if(!ofs)
  return false;

 ofs.write(&DataString[0], DataString.size());
 ofs.close();
 return true;
}

char UFileIO::ReadData()
{
 // Позиция по которой будет проведен следующий этап записи
 std::streamsize readindex=0;

 std::fstream ofs;
 DataString.resize(0);

 if(BinFlag)
  ofs.open(FileName->c_str(), ios::in | ios::binary);
 else
  ofs.open(FileName->c_str(), ios::in);

 if(!ofs)
  return false;

 while(!ofs.eof())
 {
  DataString.resize(readindex+ReadPartSize);
  ofs.read(&DataString[readindex],ReadPartSize);
  std::streamsize readsize=ofs.gcount();
  if(readsize < ReadPartSize)
   DataString.resize(DataString.size()-(ReadPartSize-readsize));
  readindex+=ReadPartSize;
 }

 ofs.close();
 return true;
}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UFileIO* UFileIO::New(void)
{
 return new UFileIO;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UFileIO::AIODefault(void)
{
 SetReadPartSize(2048);
 SetBinFlag(0);
 SetClearFlag(0);
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UFileIO::AIOBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UFileIO::AIOReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UFileIO::AIOCalculate(void)
{
 if(Direction == 0)
 {
  ReadData();
  // Используем свойство Output напрямую
  MDMatrix<double> output_data;
  output_data.Resize(1, static_cast<int>(DataString.size()));
  if(DataString.size())
   memcpy(output_data.Char, &DataString[0], DataString.size());
  *Output = output_data;
 }
 else
 if(Direction == 1)
 {
  if(!Input.IsConnected())
  {
   const MDMatrix<double>* input_ptr = Input.operator ->();
   if(!input_ptr || input_ptr->GetByteSize() == 0)
   {
	DataString.resize(0);
	WriteData();
	return true;
   }
  }
  
  UEPtr<const MDMatrix<double> > input;
  if(Input.IsConnected())
  {
   input=Input.operator ->();
  }
  else
  {
   input = Input.operator ->();
  }
  if(input)
  {
   DataString.resize(input->GetByteSize());
   if(input->GetByteSize())
	memcpy(&DataString[0],input->Char,DataString.size());
  }
  WriteData();
 }
 return true;
}
// --------------------------

}
#endif


