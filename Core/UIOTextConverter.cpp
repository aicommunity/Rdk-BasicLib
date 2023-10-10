#ifndef UIOTEXT_CONVERTER_CPP
#define UIOTEXT_CONVERTER_CPP

#include <iostream>
#include <fstream>
#include "UIOTextConverter.h"

namespace RDK {

// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIOTextConverter::UIOTextConverter(void)
: InputMode("InputMode",this,&UIOTextConverter::SetInputMode),
  OutputMode("OutputMode",this,&UIOTextConverter::SetOutputMode),
  MaxColumns("MaxColumns",this,&UIOTextConverter::SetMaxColumns),
  Input("Input", this),
  Output("Output", this)
{
}

UIOTextConverter::~UIOTextConverter(void)
{

}
// --------------------------

// --------------------------
// Методы управления параметрами
// --------------------------
bool UIOTextConverter::SetInputMode(const int &value)
{
 return true;
}

bool UIOTextConverter::SetOutputMode(const int &value)
{
 return true;
}

bool UIOTextConverter::SetMaxColumns(const int &value)
{
 return true;
}
// --------------------------


// --------------------------
// Методы управления данными
// --------------------------
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
UIOTextConverter* UIOTextConverter::New(void)
{
 return new UIOTextConverter;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UIOTextConverter::AIODefault(void)
{
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UIOTextConverter::AIOBuild(void)
{
 return true;
}

// Сброс процесса счета.
bool UIOTextConverter::AIOReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool UIOTextConverter::AIOCalculate(void)
{
 // Вырожденный случай, вход тождественен выходу
 if(InputMode == OutputMode)
 {
  if(Input.IsConnected())
  {
   *Output=*Input;
  }
  else
  {
   SetNumOutputs(NumInputs);
   for(int i=0;i<NumInputs;i++)
   {
	SetOutputDataSize(i,MMatrixSize(1,GetInputData(i)->GetSize()));
	if(GetInputData(i)->GetSize())
	 memcpy(GetOutputData(i).Void,GetInputData(i)->Void,GetInputData(i)->GetByteSize());
   }
   *Output=POutputData[0];
  }
  return true;
 }

 DataAfterRead.clear();
 switch(InputMode)
 {
 case 0: // Случай двоичных данных - просто считываем всё как есть
 {
  if(Input.IsConnected())
  {
   DataAfterRead.resize(1);
   DataAfterRead[0]=*Input;
  }
  else
  {
   DataAfterRead.resize(NumInputs);
   for(int i=0;i<NumInputs;i++)
    DataAfterRead[i]=*GetInputData(i);
  }
 }
 break;

 case 1:
 {
  UEPtr<const MDMatrix<double> > input;
  if(Input.IsConnected())
  {
   input=Input.operator ->();
  }
  else
  {
   input=GetInputData(0);
  }

  OutData.resize(input->GetByteSize());
  if(!OutData.empty())
   memcpy(&OutData[0],input->Char,OutData.size()*sizeof(char));
  ConvertFromTextColumns(OutData, DataAfterRead);
 }
 break;

 case 2:
 {
  UEPtr<const MDMatrix<double> > input;
  if(Input.IsConnected())
  {
   input=Input.operator ->();
  }
  else
  {
   input=GetInputData(0);
  }

  OutData.resize(input->GetByteSize());
  if(!OutData.empty())
   memcpy(&OutData[0],input->Char,OutData.size()*sizeof(char));

  // Преобразовываем входы последовательно в DataAfterRead
  ConvertFromTextRows(OutData, DataAfterRead);
 }
 break;
 }

 switch(OutputMode)
 {
 case 0: // Случай двоичных данных - просто выводим всё как есть
 {
  SetNumOutputs(int(DataAfterRead.size()));
  for(int i=0;i<NumOutputs;i++)
  {
   SetOutputDataSize(i,MMatrixSize(1,DataAfterRead[i].GetSize()));
   Build();
   if(DataAfterRead[i].GetSize())
	memcpy(GetOutputData(i).Void,DataAfterRead[i].Void,DataAfterRead[i].GetByteSize());
  }
  *Output=POutputData[0];
 }
 break;

 case 1:
  // Выводим во все выходы одинаково преобразованный DataAfterRead
  ConvertToTextColumns(DataAfterRead, OutData);

  for(int i=0;i<NumOutputs;i++)
  {
//   SetOutputDataElementSize(i,sizeof(char));
   int result_size=int(OutData.size())/GetOutputData(i).GetElementByteSize();
   if(OutData.size() % GetOutputData(i).GetElementByteSize())
	result_size++;
   SetOutputDataSize(i,MMatrixSize(1,result_size));
   if(OutData.size())
	memcpy(GetOutputData(i).Char,&OutData[0],OutData.size()*sizeof(char));
  }
  *Output=POutputData[0];
 break;

 case 2:
  // Выводим во все выходы одинаково преобразованный DataAfterRead
  ConvertToTextRows(DataAfterRead, OutData);

  for(int i=0;i<NumOutputs;i++)
  {
   int result_size=int(OutData.size())/GetOutputData(i).GetElementByteSize();
   if(OutData.size() % GetOutputData(i).GetElementByteSize())
	result_size++;
//   SetOutputDataElementSize(i,sizeof(char));
   SetOutputDataSize(i,MMatrixSize(1,int(OutData.size())));
   if(OutData.size())
    memcpy(GetOutputData(i).Char,&OutData[0],OutData.size()*sizeof(char));
  }
  *Output=POutputData[0];
 break;
 }

 return true;
}
// --------------------------

// --------------------------
// Вспомогательные методы расчета
// --------------------------
// Преобразовываем строку текста в прототип стандартных входных данных
void UIOTextConverter::ConvertFromTextColumns(const string &text, std::vector<UItemData> &data)
{
 size_t num_str1=0, num_str2=0;

 num_str2=separatestring(text, Separate1, '\n');
 num_str1=separatestring(Separate1[0], Separate2, '\t');
 size_t start=data.size();
 data.resize(start+num_str1);
 for(size_t i=start;i<data.size();i++)
 {
 // data[i].SetDataSize(sizeof(double));
 }

 for(size_t i=0; i<num_str1; i++)
 {
  for(size_t j=0; j<num_str2; j++)
  {
   data[start+i].Resize(1, data[start+i].GetSize()+1);

   separatestring(Separate1[j], Separate2, '\t');
   data[start+i].Double[data[start+i].GetSize()-1]=atof(Separate2[i]);
  }
 }
}

void UIOTextConverter::ConvertFromTextRows(const string &text, std::vector<UItemData> &data)
{
 size_t num_str1=0, num_str2=0;

 num_str1=separatestring(text, Separate1, '\n');
 size_t start=data.size();
 data.resize(start+num_str1);
 for(size_t i=start;i<data.size();i++)
 {
//  data[i].SetDataSize(sizeof(double));
 }

 for(size_t i=0; i<num_str1; i++)
 {
  num_str2=separatestring(Separate1[i], Separate2, '\t');
  data[start+i].Resize(1, data[start+i].GetSize()+1);
  for(size_t j=0; j<num_str2; j++)
  {
   data[start+j].Double[data[start+j].GetSize()-1]=atof(Separate2[j]);;
  }
 }
}

// Преобразовываем стандартные входные данные в строку текста    Возможно тут наиндусил, посмотрите пожалуйста!
void UIOTextConverter::ConvertToTextColumns(const std::vector<UItemData> &data, string &text)
{
 string Temp_digit;
 size_t data_size, temp, k=0, max_size=0;

 text.clear();
 data_size=data.size();

 for(size_t i=0; i<data_size;i++)
 {
  temp=data[i].GetSize();
  if(temp>max_size) {max_size=temp; k=i;}
 }

 for(int i=0; i<data[k].GetSize();i++)
 {
  for(size_t j=0; j<data_size; j++)
  {
   Temp_digit.clear();
   if(i<data[j].GetSize()) Temp_digit=sntoa(data[j].Double[i]);
   if((j+1)<data_size) Temp_digit+='\t';
   text+=Temp_digit;
  }
  text+='\n';
 }
}

void UIOTextConverter::ConvertToTextRows(const std::vector<UItemData> &data, string &text)
{
 string Temp_digit;
 size_t data_size;

 text.clear();

 for(size_t i=0; i<data.size();i++)
 {
  data_size=data[i].GetSize();
  for(size_t j=0; j<data_size; j++)
  {
   Temp_digit.clear();
   Temp_digit=sntoa(data[i].Double[j]);
   if((j+1)<data_size) Temp_digit+='\t';
   text+=Temp_digit;
  }
  text+='\n';
 }
}
// --------------------------

}
#endif


