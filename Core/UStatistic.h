/* ***********************************************************
@Copyright Aleksandr Bakshiev, 2012.
E-mail:        alexab@ailab.ru
Url:           http://ailab.ru

This file is part of the project: RDK

File License:       New BSD License
Project License:    New BSD License
See file license.txt for more information
*********************************************************** */
#ifndef UStatisticH
#define UStatisticH

//#include "../../UNet.h"
#include <errno.h>
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

class RDK_LIB_TYPE UStatistic: public UNet
{
protected: // Параметры
// Путь для сохранения статистики
std::string SavePath;

/// Префикс имен для статистики
std::string PrefixName;

// Флаг необходимости создавать подкаталог дата/время каждый раз после Reset
bool SubFolderAfterResetFlag;

/// Флаг принудительного создания корневого пути для логов ("StatisticLog" по умолчанию)
/// даже если SubFolderAfterResetFlag отключен
bool ForceCreateSavePath;

// Флаг необходимости добавлять дату и время к имени файла
bool TimeToFileNameFlag;

// Флаг необходимости добавлять порядковый номер файла к имени
bool OrderIndexToFileNameFlag;

/// Дополнительный постфикс для имени файла, когда на одну временную метку
/// приходится несколько сохранений лога
int CurrentFileNameNumber;

time_t OldTimeStamp;

// Число шагов расчета которые следуте пропустить перед началом регистрации
int NumSkipSteps;

public:
// Флаг ручного режима сохранения статистики
ULProperty<bool,UStatistic> ManualModeEnabled;

// Интервал отображения
ULProperty<double,UStatistic> TimeInterval;

public: // Данные
// Флаг, взводимый для разового сохранения в ручном режиме
ULProperty<bool,UStatistic> ManualModeSwitch;

protected: // Временные переменные
// Флаг, выставляемый, если был проведен Reset.
bool ResetFlag;

// Текущий путь для записи статистики
std::string CurrentPath;

// Текущее имя файла
std::string CurrentFileName;

/// Индекс текущего номера файла
int CurrentFileIndex;

int CurrentStep;

// Время предыдущей записи
double PrevTime;

public: // Методы
// ---------------------
// Конструкторы и деструкторы
// ---------------------
UStatistic(void);
virtual ~UStatistic(void);
// ---------------------

// ---------------------
// Методы управления параметрами
// ---------------------
bool SetSavePath(const std::string &value);
bool SetPrefixName(const std::string &value);
bool SetSubFolderAfterResetFlag(bool value);
bool SetTimeInterval(const double &value);
// ---------------------

// ---------------------
// Методы счета
// ---------------------
// ---------------------

// ---------------------
// Операторы
// ---------------------
//bool operator () (UBitmap &input, UBitmap &output);
// ---------------------


// --------------------------
// Скрытые методы управления счетом фильтров
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ADefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool ABuild(void);

// Сброс процесса счета без потери настроек
virtual bool AReset(void);

// Выполняет расчет этого объекта
virtual bool ACalculate(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом фильтров сплиттинга
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool AFSDefault(void)=0;

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool AFSBuild(void)=0;

// Сброс процесса счета без потери настроек
virtual bool AFSReset(void)=0;

// Выполняет расчет этого объекта
virtual bool AFSCalculate(void)=0;
// --------------------------
};

template<class T>
class UStatisticMatrix: public RDK::UStatistic
{
public: // Параметры
/// Способ сохранения матрицы на каждом шаге
/// 0 - в строчку
/// 1 - как целую матрицу
ULProperty<int,UStatisticMatrix<T> > SaveMode;

/// Способ усреднения данных
/// 0 - без усреднения
/// 1 - с усреднением по последним N измерениям
/// 2 - с усреднением по изменению состояния определенного входа
ULProperty<int,UStatisticMatrix<T> > AverageMode;

/// Количество измерений для усреднения
ULProperty<int,UStatisticMatrix<T> > AverageNumber;

/// Пара <имя компонента, имя входа> используемая лдя записи усредненных данных
ULProperty<std::pair<std::string,std::string>,UStatisticMatrix<T> > AverageInput;

/// Писать или нет временную метку в каждую строку
ULProperty<bool,UStatisticMatrix<T> > WriteTimeStampFlag;

/// Писать или нет время, прошедшее с момента ресета в каждую строку
ULProperty<bool,UStatisticMatrix<T> > WriteTimeFromResetFlag;

/// Писать или нет временную метку источника данных в каждую строку
ULProperty<bool,UStatisticMatrix<T> > WriteSourceTimeStampFlag;

/// Писать или нет временную метку времени модели
ULProperty<bool,UStatisticMatrix<T> > WriteModelTimeStampFlag;

/// Писать или нет индекс измерения в каждую строку
ULProperty<bool,UStatisticMatrix<T> > WriteIndexFlag;

/// Флаг обрезки имени модели от полного имени формируемого файла
ULProperty<bool,UStatisticMatrix<T> > ExcludeModelFileName;

/// Текущее число измерений для усреднения
ULProperty<int,UStatisticMatrix<T>, ptPubState > CurrentAverageNumber;




protected: // Коммуникационные данные
/// Входной вектор матриц
UPropertyInputCData<MDMatrix<T>,UStatisticMatrix<T> > InputMatrixData;

time_t StartTime;
bool first_calc;

protected: // Данные
/// Массив файлов логов
std::vector<UEPtr<fstream> > LogFiles;

std::vector<std::string> LogFileNames;

std::vector<MDMatrix<T> > Average;

int CurrentIndex;

public: // Методы
// ---------------------
// Конструкторы и деструкторы
// ---------------------
UStatisticMatrix(void);
virtual ~UStatisticMatrix(void);
// ---------------------

// ---------------------
// Методы счета
// ---------------------
// Создание новой копии этого объекта
virtual UStatisticMatrix<T>* New(void);
// ---------------------

// ----------------------
// Коммуникационные методы
// ----------------------
protected:
// ---------------------

// --------------------------
// Скрытые методы управления счетом фильтров сплиттинга
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool AFSDefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool AFSBuild(void);

// Сброс процесса счета без потери настроек
virtual bool AFSReset(void);

// Выполняет расчет этого объекта
virtual bool AFSCalculate(void);
// --------------------------
};


// ---------------------
// Конструкторы и деструкторы
// ---------------------
template<class T>
UStatisticMatrix<T>::UStatisticMatrix(void)
: SaveMode("SaveMode",this),
  AverageMode("AverageMode",this),
  AverageNumber("AverageNumber",this),
  AverageInput("AverageInput",this),
  WriteTimeStampFlag("WriteTimeStampFlag",this),
  WriteTimeFromResetFlag("WriteTimeFromResetFlag",this),
  WriteSourceTimeStampFlag("WriteSourceTimeStampFlag",this),
  WriteModelTimeStampFlag("WriteModelTimeStampFlag",this),
  WriteIndexFlag("WriteIndexFlag",this),
  ExcludeModelFileName("ExcludeModelFileName",this),
  CurrentAverageNumber("CurrentAverageNumber",this),
  InputMatrixData("InputMatrixData",this)
{
 CurrentIndex=0;
}

template<class T>
UStatisticMatrix<T>::~UStatisticMatrix(void)
{
 for(size_t i=0;i<LogFiles.size();i++)
 {
  if(LogFiles[i])
  {
   LogFiles[i]->flush();
   LogFiles[i]->close();
   delete LogFiles[i];
  }
 }
}
// ---------------------


// ---------------------
// Методы счета
// ---------------------
// Создание новой копии этого объекта
template<class T>
UStatisticMatrix<T>* UStatisticMatrix<T>::New(void)
{
 return new UStatisticMatrix<T>;
}
// ---------------------

// ---------------------
// Операторы
// ---------------------
// ---------------------


// ----------------------
// Коммуникационные методы
// ----------------------
// ---------------------

// --------------------------
// Скрытые методы управления счетом фильтров сплиттинга
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
template<class T>
bool UStatisticMatrix<T>::AFSDefault(void)
{
 AverageMode=0;
 AverageNumber=5;
 WriteIndexFlag=true;
 WriteTimeStampFlag=false;
 WriteSourceTimeStampFlag=false;
 ExcludeModelFileName=true;
 WriteModelTimeStampFlag=false;
 WriteTimeFromResetFlag=false;
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
template<class T>
bool UStatisticMatrix<T>::AFSBuild(void)
{
 return true;
}

// Сброс процесса счета без потери настроек
template<class T>
bool UStatisticMatrix<T>::AFSReset(void)
{
  for(size_t i=0;i<LogFiles.size();i++)
  {
   if(LogFiles[i])
   {
	LogFiles[i]->flush();
	LogFiles[i]->close();
	delete LogFiles[i];
   }
  }
  LogFiles.clear();
  LogFileNames.clear();
 Average.clear();
 CurrentAverageNumber=0;
 CurrentIndex=0;
 first_calc = true;
 return true;
}

// Выполняет расчет этого объекта
template<class T>
bool UStatisticMatrix<T>::AFSCalculate(void)
{
 if(first_calc)
 {
	StartTime = time(NULL);
	first_calc = false;
 }
 if(InputMatrixData->size() == 0)
 {
  return true;
 }

/* if(ResetFlag)
 {
  for(size_t i=0;i<LogFiles.size();i++)
  {
   if(LogFiles[i])
   {
	LogFiles[i]->flush();
	LogFiles[i]->close();
	std::string filename;
	GetCItem(i).Item->GetLongName(Owner,filename);
	UIProperty* property=0;
	GetCItem(i).Item->FindOutputProperty(GetCItem(i).Index, property);
	if(property)
	{
	 filename+=std::string(".")+property->GetName()+std::string(".txt");
	 filename=CurrentPath+std::string("/")+filename;
	 LogFiles[i]->open(filename.c_str(),ios::out | ios::trunc);
	}
   }
  }

 }  */

 if(InputMatrixData->size()<LogFiles.size())
 {
  for(size_t i=InputMatrixData->size();i<LogFiles.size();i++)
  {
   LogFiles[i]->close();
   delete LogFiles[i];
  }
  LogFiles.resize(InputMatrixData->size());
  LogFileNames.resize(LogFiles.size());
 }
 else
 if(InputMatrixData->size()>LogFiles.size())
 {
  std::vector<UCItem> c_items;
  UConnector::GetCItem("InputMatrixData", c_items);
  size_t curr_size=LogFiles.size();
  LogFiles.resize(InputMatrixData->size());
  LogFileNames.resize(LogFiles.size());
  for(size_t i=curr_size;i<LogFiles.size();i++)
  {
   LogFiles[i] = new fstream;
   std::string filename;
   if(!c_items[i].Item)
	continue;
   c_items[i].Item->GetFullName(filename);
   if(ExcludeModelFileName)
   {
	std::string::size_type i=filename.find_first_of(".");
	if(i != std::string::npos)
	{
     filename.erase(0, i+1);
    }
   }

   UIProperty* property=0;
   UEPtr<UItem> item=dynamic_cast<UItem*>(c_items[i].Item);
   if(!item)
    continue;
   item->FindOutputProperty(c_items[i].Name, property);
   if(property)
   {
	filename+=std::string(".")+property->GetName()+std::string(".txt");
	filename=CurrentPath+std::string("/")+filename;
	LogFiles[i]->open(filename.c_str(),ios::out | ios::trunc);
	if(LogFiles[i]->fail() || !LogFiles[i]->is_open())
	{
	 LogMessage(RDK_EX_WARNING, std::string("Can't open statistic file: ")+filename+std::string(" reason: ")+strerror(errno));
	}
    LogFileNames[i]=filename;
   }
  }
 }

 switch(AverageMode)
 {
 case 0:
 {
  std::string result;
  for(size_t i=0;i<InputMatrixData->size();i++)
  {
   if(!(*InputMatrixData)[i])
	continue;

   result.resize(0);

   if(WriteIndexFlag)
   {
	result=sntoa(CurrentIndex,8);
   }

   if(!result.empty())
	result+=std::string(" ");

   if(WriteTimeStampFlag)
   {
	time_t time_data;
	time(&time_data);
	result+=get_text_time(time_data,'.',':')+std::string(" AvgN=\t")+sntoa(*CurrentAverageNumber);
   }

   if(WriteSourceTimeStampFlag)
   {
	result+=RDK::sntoa(GetTime().GetSourceCurrentGlobalTime()*86400.0*1000.0);
	result+=std::string(" ");
   }

   if(WriteTimeFromResetFlag)
   {
		time_t curr_time = time(NULL);
		time_t tme = curr_time - StartTime;
		time_t hrs = tme/3600;
		time_t min = (tme%3600)/60;
		time_t sec = tme%60;

		//Получить текущую дату и время в виде строки
		std::stringstream ss;
		if(hrs<10)
			ss<<"0";
		ss<<hrs<<":";
		if(min<10)
			ss<<"0";
		ss<<min<<":";
		if(sec<10)
			ss<<"0";

		ss<<sec;
		std::string tim = ss.str();

		result+= tim+std::string(" ");
   }

   if(WriteModelTimeStampFlag)
   {
	result+=RDK::sntoa(GetTime().GetDoubleTime(),20);
	result+=std::string(" ");
   }

   if(SaveMode == 0)
   {
	result+="\t";
	MDMatrix<T> &matrix=*(*InputMatrixData)[i];
	for(int n=0;n<matrix.GetRows();n++)
	{
	 for(int m=0;m<matrix.GetCols();m++)
	 {
	  result+=sntoa(matrix(n,m));
	  result+="\t\t";
	 }
	}
	result+="\n";
   }
   else
   {
	result+="\n";
	MDMatrix<T> &matrix=*(*InputMatrixData)[i];
	for(int n=0;n<matrix.GetRows();n++)
	{
	 for(int m=0;m<matrix.GetCols();m++)
	 {
	  result+=sntoa(matrix(n,m));
	  result+="\t\t";
	 }
	 result+="\n";
	}
   }

   if(LogFiles[i]->is_open())
   {
	LogFiles[i]->write(result.c_str(),result.size());
	LogFiles[i]->flush();
    LogFiles[i]->close();
    LogFiles[i]->open(LogFileNames[i].c_str(),ios::out | ios::app);
    if(LogFiles[i]->fail() || !LogFiles[i]->is_open())
    {
     LogMessage(RDK_EX_WARNING, std::string("Can't open statistic file: ")+LogFileNames[i]+std::string(" reason: ")+strerror(errno));
    }
   }
//   else
//	LogMessage(RDK_EX_WARNING, std::string("Write to statistic file failed: ")+sntoa(i));

  }
 }
 break;

 case 1:
 {
  if(Average.size()<InputMatrixData->size())
  {
   Average.resize(InputMatrixData->size());
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
	if(!(*InputMatrixData)[i])
	 continue;
	Average[i].Resize((*InputMatrixData)[i]->GetRows(),(*InputMatrixData)[i]->GetCols());
   }
  }
  for(size_t i=0;i<InputMatrixData->size();i++)
  {
   if((*InputMatrixData)[i])
    Average[i]+=*(*InputMatrixData)[i];
  }
  ++(*CurrentAverageNumber);

  if(CurrentAverageNumber == AverageNumber && AverageNumber>0)
  {
   for(size_t i=0;i<Average.size();i++)
	Average[i]/=T(CurrentAverageNumber);

   std::string result;
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
	if(!(*InputMatrixData)[i])
	 continue;

	result.resize(0);

	if(WriteIndexFlag)
	{
	 result=sntoa(CurrentIndex,8);
	}

	if(!result.empty())
  	 result+=std::string(" ");

	if(WriteTimeStampFlag)
	{
	 time_t time_data;
	 time(&time_data);
//	 std::string new_file_name;
	 result+=get_text_time(time_data,'.',':')+std::string(" AvgN=\t")+sntoa(CurrentAverageNumber.v);
	}

   if(WriteSourceTimeStampFlag)
   {
	result+=RDK::sntoa(GetTime().GetSourceCurrentGlobalTime()*86400.0*1000.0);
	result+=std::string(" ");
   }

   if(WriteTimeFromResetFlag)
   {
		time_t curr_time = time(NULL);
		time_t tme = curr_time - StartTime;
		time_t hrs = tme/3600;
		time_t min = (tme%3600)/60;
		time_t sec = tme%60;

		//Получить текущую дату и время в виде строки
		std::stringstream ss;
		if(hrs<10)
			ss<<"0";
		ss<<hrs<<":";
		if(min<10)
			ss<<"0";
		ss<<min<<":";
		if(sec<10)
			ss<<"0";

		ss<<sec;
		std::string tim = ss.str();

		result+= tim+std::string(" ");
   }

   if(WriteModelTimeStampFlag)
   {
	result+=RDK::sntoa(GetTime().GetDoubleTime(),20);
	result+=std::string(" ");
   }

	if(SaveMode == 0)
	{
	 result+="\t";
	 MDMatrix<T> &matrix=Average[i];
	 for(int n=0;n<matrix.GetRows();n++)
	 {
	  for(int m=0;m<matrix.GetCols();m++)
	  {
	   result+=sntoa(matrix(n,m));
	   result+="\t\t";
	  }
	 }
	 result+="\n";
	}
	else
	{
	 result+="\n";
	 MDMatrix<T> &matrix=Average[i];
	 for(int n=0;n<matrix.GetRows();n++)
	 {
	  for(int m=0;m<matrix.GetCols();m++)
	  {
	   result+=sntoa(matrix(n,m));
	   result+="\t\t";
	  }
	  result+="\n";
	 }
	}

	if(LogFiles[i]->is_open())
	{
	 LogFiles[i]->write(result.c_str(),result.size());
	 LogFiles[i]->flush();
     LogFiles[i]->close();
     LogFiles[i]->open(LogFileNames[i].c_str(),ios::out | ios::app);
     if(LogFiles[i]->fail() || !LogFiles[i]->is_open())
     {
      LogMessage(RDK_EX_WARNING, std::string("Can't open statistic file: ")+LogFileNames[i]+std::string(" reason: ")+strerror(errno));
     }
    }
   }
   CurrentAverageNumber=0;
   for(size_t i=0;i<Average.size();i++)
	Average[i].ToZero();
  }
 }
 break;

 case 2:
 {
  if(Average.size()<InputMatrixData->size())
  {
   Average.resize(InputMatrixData->size());
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
	if(!(*InputMatrixData)[i])
	 continue;
	Average[i].Resize((*InputMatrixData)[i]->GetRows(),(*InputMatrixData)[i]->GetCols());
	Average[i]+=*(*InputMatrixData)[i];
   }
  }
  ++(*CurrentAverageNumber);

  if(CurrentAverageNumber == AverageNumber && AverageNumber>0)
  {
   for(size_t i=0;i<Average.size();i++)
	Average[i]/=T(CurrentAverageNumber);

   std::string result;
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
	if(!(*InputMatrixData)[i])
	 continue;

	result.resize(0);
	if(WriteIndexFlag)
	{
	 result=sntoa(CurrentIndex,8);
	}

	if(!result.empty())
  	 result+=std::string(" ");

	if(WriteTimeStampFlag)
	{
	 time_t time_data;
	 time(&time_data);
//	 std::string new_file_name;
	 result+=get_text_time(time_data,'.',':');
  	 result+=std::string(" ");
	}

	if(WriteSourceTimeStampFlag)
	{
	 result+=RDK::sntoa(GetTime().GetSourceCurrentGlobalTime()*86400.0*1000.0);
  	 result+=std::string(" ");
	}

	if(WriteTimeFromResetFlag)
	{
		time_t curr_time = time(NULL);
		time_t tme = curr_time - StartTime;
		time_t hrs = tme/3600;
		time_t min = (tme%3600)/60;
		time_t sec = tme%60;

		//Получить текущую дату и время в виде строки
		std::stringstream ss;
		if(hrs<10)
		ss<<"0";
		ss<<hrs<<":";
		if(min<10)
		ss<<"0";
		ss<<min<<":";
		if(sec<10)
		ss<<"0";

		ss<<sec;
		std::string tim = ss.str();

		result+= tim+std::string(" ");
	}

	if(WriteModelTimeStampFlag)
	{
	 result+=RDK::sntoa(GetTime().GetDoubleTime(),20);
	 result+=std::string(" ");
    }

	if(SaveMode == 0)
	{
	 result+="\t";
	 MDMatrix<T> &matrix=Average[i];
	 for(int n=0;n<matrix.GetRows();n++)
	 {
	  for(int m=0;m<matrix.GetCols();m++)
	  {
	   result+=sntoa(matrix(n,m));
	   result+="\t\t";
	  }
	 }
	 result+="\n";
	}
	else
	{
	 result+="\n";
	 MDMatrix<T> &matrix=Average[i];
	 for(int n=0;n<matrix.GetRows();n++)
	 {
	  for(int m=0;m<matrix.GetCols();m++)
	  {
	   result+=sntoa(matrix(n,m));
	   result+="\t\t";
	  }
	  result+="\n";
	 }
	}

	if(LogFiles[i]->is_open())
	{
	 LogFiles[i]->write(result.c_str(),result.size());
	 LogFiles[i]->flush();
     LogFiles[i]->close();
     LogFiles[i]->open(LogFileNames[i].c_str(),ios::out | ios::app);
     if(LogFiles[i]->fail() || !LogFiles[i]->is_open())
     {
      LogMessage(RDK_EX_WARNING, std::string("Can't open statistic file: ")+LogFileNames[i]+std::string(" reason: ")+strerror(errno));
     }
    }
   }
   CurrentAverageNumber=0;
   for(size_t i=0;i<Average.size();i++)
	Average[i].ToZero();
  }
 }
 break;
 }

 ++CurrentIndex;
 return true;
}
// --------------------------

}
//---------------------------------------------------------------------------
#endif
