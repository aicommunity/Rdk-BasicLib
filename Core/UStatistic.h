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
#include <memory>
#include "ModernSmartPointers.h"
#include <filesystem>
#include <memory>
#include <mutex>
#include <chrono>

namespace RDK {

class RDK_LIB_TYPE UStatistic: public UNet
{
protected: // ���������
// ���� ��� ���������� ����������
UProperty<std::string,UStatistic, ptPubParameter> SavePath;

/// ������� ���� ��� ����������
UProperty<std::string,UStatistic, ptPubParameter> PrefixName;

// ���� ������������� ��������� ���������� ����/����� ������ ��� ����� Reset
UProperty<bool,UStatistic, ptPubParameter> SubFolderAfterResetFlag;

/// ���� ��������������� �������� ��������� ���� ��� ����� ("StatisticLog" �� ���������)
/// ���� ���� SubFolderAfterResetFlag ��������
UProperty<bool,UStatistic, ptPubParameter> ForceCreateSavePath;

// ���� ������������� ��������� ���� � ����� � ����� �����
UProperty<bool,UStatistic, ptPubParameter> TimeToFileNameFlag;

// ���� ������������� ��������� ���������� ����� ����� � �����
UProperty<bool,UStatistic, ptPubParameter> OrderIndexToFileNameFlag;

// ����� ����� ������� ������� ������� ���������� ����� ������� �����������
UProperty<int,UStatistic, ptPubParameter> NumSkipSteps;

public:
// ���� ������� ������ ���������� ����������
ULProperty<bool,UStatistic> ManualModeEnabled;

// �������� �����������
ULProperty<double,UStatistic> TimeInterval;

public: // ������
// ����, ��������� ��� �������� ���������� � ������ ������
ULProperty<bool,UStatistic> ManualModeSwitch;


protected: // ��������� ����������
int OldTimeStamp;

/// �������������� �������� ��� ����� �����, ����� �� ���� ��������� �����
/// ���������� ��������� ���������� ����
int CurrentFileNameNumber;

// ����, ������������, ���� ��� �������� Reset.
bool ResetFlag;

// ������� ���� ��� ������ ����������
std::string CurrentPath;

// ������� ��� �����
std::string CurrentFileName;

// Modern C++20 methods with std::filesystem
// Thread-safe file operations
bool SaveStatisticSafe(const std::filesystem::path& filepath) const;
bool LoadStatisticSafe(const std::filesystem::path& filepath);

// Modern file management
std::filesystem::path GetSavePath(void) const;
void SetSavePath(const std::filesystem::path& path);

// Modern move semantics
UStatistic(UStatistic&& other) noexcept;
UStatistic& operator=(UStatistic&& other) noexcept;

// Modern smart pointer factory
static std::shared_ptr<UStatistic> Create(const std::filesystem::path& savePath);

/// ������ �������� ������ �����
int CurrentFileIndex;

int CurrentStep;

// ����� ���������� ������
double PrevTime;

public: // ������
// ---------------------
// ������������ � �����������
// ---------------------
UStatistic(void);
virtual ~UStatistic(void);
// ---------------------

// ---------------------
// ������ ���������� �����������
// ---------------------
bool SetSavePath(const std::string &value);
bool SetPrefixName(const std::string &value);
bool SetSubFolderAfterResetFlag(bool value);
bool SetTimeInterval(const double &value);
// ---------------------

// ---------------------
// ������ �����
// ---------------------
// ---------------------

// ---------------------
// ���������
// ---------------------
//bool operator () (UBitmap &input, UBitmap &output);
// ---------------------


// --------------------------
// ������� ������ ���������� ������ ��������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ABuild(void);

// ����� �������� ����� ��� ������ ��������
virtual bool AReset(void);

// ��������� ������ ����� �������
virtual bool ACalculate(void);
// --------------------------

// --------------------------
// ������� ������ ���������� ������ �������� ����������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool AFSDefault(void)=0;

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool AFSBuild(void)=0;

// ����� �������� ����� ��� ������ ��������
virtual bool AFSReset(void)=0;

// ��������� ������ ����� �������
virtual bool AFSCalculate(void)=0;
// --------------------------
};

template<class T>
class UStatisticMatrix: public RDK::UStatistic
{
public: // ���������
/// ������ ���������� ������� �� ������ ����
/// 0 - � �������
/// 1 - ��� ����� �������
ULProperty<int,UStatisticMatrix<T> > SaveMode;

/// ������ ���������� ������
/// 0 - ��� ����������
/// 1 - � ����������� �� ��������� N ����������
/// 2 - � ����������� �� ��������� ��������� ������������� �����
ULProperty<int,UStatisticMatrix<T> > AverageMode;

/// ���������� ��������� ��� ����������
ULProperty<int,UStatisticMatrix<T> > AverageNumber;

/// ���� <��� ����������, ��� �����> ������������ ��� ������ ����������� ������
ULProperty<std::pair<std::string,std::string>,UStatisticMatrix<T> > AverageInput;

/// ������ ��� ��� ��������� ����� � ������ ������
ULProperty<bool,UStatisticMatrix<T> > WriteTimeStampFlag;

/// ������ ��� ��� �����, ��������� � ������� ������ � ������ ������
ULProperty<bool,UStatisticMatrix<T> > WriteTimeFromResetFlag;

/// ������ ��� ��� ��������� ����� ��������� ������ � ������ ������
ULProperty<bool,UStatisticMatrix<T> > WriteSourceTimeStampFlag;

/// ������ ��� ��� ��������� ����� ������� ������
ULProperty<bool,UStatisticMatrix<T> > WriteModelTimeStampFlag;

/// ������ ��� ��� ������ ��������� � ������ ������
ULProperty<bool,UStatisticMatrix<T> > WriteIndexFlag;

/// ���� ������� ����� ������ �� ������� ����� ������������ �����
ULProperty<bool,UStatisticMatrix<T> > ExcludeModelFileName;

/// ������� ����� ��������� ��� ����������
ULProperty<int,UStatisticMatrix<T>, ptPubState > CurrentAverageNumber;




protected: // ���������������� ������
/// ������� ������ ������
UPropertyInputCData<MDMatrix<T>,UStatisticMatrix<T> > InputMatrixData;

time_t StartTime;
bool first_calc;

protected: // ������
/// ������ ������ �����
std::vector<std::shared_ptr<fstream> > LogFiles;

std::vector<std::string> LogFileNames;

std::vector<MDMatrix<T> > Average;

int CurrentIndex;

public: // ������
// ---------------------
// ������������ � �����������
// ---------------------
UStatisticMatrix(void);
virtual ~UStatisticMatrix(void);
// ---------------------

// ---------------------
// ������ �����
// ---------------------
// �������� ����� ����� ����� �������
virtual UStatisticMatrix<T>* New(void);
// ---------------------

// ----------------------
// ���������������� ������
// ----------------------
protected:
// ---------------------

// --------------------------
// ������� ������ ���������� ������ �������� ����������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool AFSDefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool AFSBuild(void);

// ����� �������� ����� ��� ������ ��������
virtual bool AFSReset(void);

// ��������� ������ ����� �������
virtual bool AFSCalculate(void);
// --------------------------
};


// ---------------------
// ������������ � �����������
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
   LogFiles[i].reset();
  }
 }
}
// ---------------------


// ---------------------
// ������ �����
// ---------------------
// �������� ����� ����� ����� �������
template<class T>
UStatisticMatrix<T>* UStatisticMatrix<T>::New(void)
{
 return new UStatisticMatrix<T>;
}
// ---------------------

// ---------------------
// ���������
// ---------------------
// ---------------------


// ----------------------
// ���������������� ������
// ----------------------
// ---------------------

// --------------------------
// ������� ������ ���������� ������ �������� ����������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
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

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
template<class T>
bool UStatisticMatrix<T>::AFSBuild(void)
{
 return true;
}

// ����� �������� ����� ��� ������ ��������
template<class T>
bool UStatisticMatrix<T>::AFSReset(void)
{
  for(size_t i=0;i<LogFiles.size();i++)
  {
   if(LogFiles[i])
   {
	LogFiles[i]->flush();
	LogFiles[i]->close();
	LogFiles[i].reset();
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

// ��������� ������ ����� �������
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
   LogFiles[i].reset();
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
   LogFiles[i] = std::make_shared<fstream>();
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

   UIPropertyOutput* property=0;
   std::shared_ptr<UItem> item=safe_shared_cast<UItem>(dynamic_cast<UItem*>(c_items[i].Item));
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

    //�������� ������� ���� � ����� � ���� ������
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
    const MDMatrix<T> &matrix=InputMatrixData[i];
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
    const MDMatrix<T> &matrix=InputMatrixData[i];
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
    Average[i].Resize(InputMatrixData[i].GetRows(),InputMatrixData[i].GetCols());
   }
  }
  for(size_t i=0;i<InputMatrixData->size();i++)
  {
   Average[i]+=InputMatrixData[i];
  }
  ++(*CurrentAverageNumber);

  if(CurrentAverageNumber == AverageNumber.v && AverageNumber>0)
  {
   for(size_t i=0;i<Average.size();i++)
    Average[i]/=T(CurrentAverageNumber);

   std::string result;
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
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

       //�������� ������� ���� � ����� � ���� ������
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
    Average[i].Resize(InputMatrixData[i].GetRows(),InputMatrixData[i].GetCols());
    Average[i]+=InputMatrixData[i];
   }
  }
  ++(*CurrentAverageNumber);

  if(CurrentAverageNumber == AverageNumber.v && AverageNumber>0)
  {
   for(size_t i=0;i<Average.size();i++)
    Average[i]/=T(CurrentAverageNumber);

   std::string result;
   for(size_t i=0;i<InputMatrixData->size();i++)
   {
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

     //�������� ������� ���� � ����� � ���� ������
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
