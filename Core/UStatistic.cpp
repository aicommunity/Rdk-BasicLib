/* ***********************************************************
@Copyright Aleksandr Bakhshiev, 2012.
E-mail:        alexab@ailab.ru
Url:           http://ailab.ru

This file is part of the project: RDK

File License:       New BSD License
Project License:    New BSD License
See file license.txt for more information
*********************************************************** */
#ifndef UStatistic_CPP
#define UStatistic_CPP
#include "UStatistic.h"
#include <math.h>
//#include "../../../System/rdk_system.h"
//#include "../../UGraphicsXMLSerialize.h"
//#include "../../UEnvironment.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

//UStatisticRect UBGuiSelectionRect;

// ---------------------
// Конструкторы и деструкторы
// ---------------------
UStatistic::UStatistic(void)
 : ManualModeEnabled("ManualModeEnabled",this),
   TimeInterval("TimeInterval", this, &UStatistic::SetTimeInterval),
   ManualModeSwitch("ManualModeSwitch",this)
{
 AddLookupProperty("SavePath",ptPubParameter, new UVProperty<std::string,UStatistic>(this,&SavePath));
 AddLookupProperty("SubFolderAfterResetFlag",ptPubParameter, new UVProperty<bool,UStatistic>(this,&SubFolderAfterResetFlag));
 AddLookupProperty("ForceCreateSavePath",ptPubParameter, new UVProperty<bool,UStatistic>(this,&ForceCreateSavePath));

 AddLookupProperty("PrefixName",ptPubParameter, new UVProperty<std::string,UStatistic>(this,&PrefixName));

 AddLookupProperty("TimeToFileNameFlag",ptPubParameter, new UVProperty<bool,UStatistic>(this,&TimeToFileNameFlag));
 AddLookupProperty("OrderIndexToFileNameFlag",ptPubParameter, new UVProperty<bool,UStatistic>(this,&OrderIndexToFileNameFlag));
 AddLookupProperty("NumSkipSteps",ptPubParameter, new UVProperty<int,UStatistic>(this,&NumSkipSteps));
}

UStatistic::~UStatistic(void)
{

}
// ---------------------

// ---------------------
// Методы управления параметрами
// ---------------------
bool UStatistic::SetSavePath(const std::string &value)
{
 SavePath=value;
 return true;
}

bool UStatistic::SetPrefixName(const std::string &value)
{
 PrefixName=value;
 return true;
}

bool UStatistic::SetSubFolderAfterResetFlag(bool value)
{
 SubFolderAfterResetFlag=value;
 return true;
}

bool UStatistic::SetTimeInterval(const double &value)
{
 if(value<0)
  return false;

 Ready = false;
 return true;
}
// ---------------------

// --------------------------
// Скрытые методы управления счетом фильтров
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
bool UStatistic::ADefault(void)
{
 Activity=false;
 SubFolderAfterResetFlag=true;
 ForceCreateSavePath=false;
 SavePath="StatisticLog";

 TimeToFileNameFlag=false;
 OrderIndexToFileNameFlag=true;
 NumSkipSteps=0;
 ManualModeEnabled=false;
 ManualModeSwitch=false;

 return AFSDefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool UStatistic::ABuild(void)
{
 return AFSBuild();
}

// Сброс процесса счета без потери настроек
bool UStatistic::AReset(void)
{
 ResetFlag=true;
 OldTimeStamp=0;
 CurrentFileNameNumber=0;
 CurrentFileIndex=0;
 CurrentStep=0;
 PrevTime=0;

 return AFSReset();
}

// Выполняет расчет этого объекта
bool UStatistic::ACalculate(void)
{
 if(CurrentStep<NumSkipSteps)
 {
  ++CurrentStep;
  return true;
 }

  double CurrentTime = GetTime().GetSourceCurrentLocalTime();
  if((CurrentTime!= 0)&&((CurrentTime-PrevTime)<TimeInterval))
   return true;

 PrevTime = CurrentTime;
 ++CurrentStep;

 if(ManualModeEnabled)
 {
  if(ManualModeSwitch)
   ManualModeSwitch=false;
  else
   return true;
 }

 if(SubFolderAfterResetFlag && ResetFlag)
 {
  CurrentPath=Environment->GetCurrentDataDir()+SavePath;
  if(RDK::CreateNewDirectory(CurrentPath.c_str()))
   return false; // TODO: Заглушка!! здесь исключение

  time_t time_data;
  time(&time_data);
  if(!PrefixName.empty())
   CurrentPath=Environment->GetCurrentDataDir()+SavePath+std::string("/")+PrefixName+std::string(" ")+get_text_time(time_data,'.','-');
  else
   CurrentPath=Environment->GetCurrentDataDir()+SavePath+std::string("/")+get_text_time(time_data,'.','-');
  if(RDK::CreateNewDirectory(CurrentPath.c_str()))
   return false; // TODO: Заглушка!! здесь исключение
 }
 else
 if(!SubFolderAfterResetFlag && ResetFlag)
 {
  CurrentPath=Environment->GetCurrentDataDir()+SavePath;
  if(ForceCreateSavePath)
   if(RDK::CreateNewDirectory(CurrentPath.c_str()))
    return false; // TODO: Заглушка!! здесь исключение
 }

 ResetFlag=false;

 time_t time_data;
 time(&time_data);
 std::string new_file_name;
 if(!PrefixName.empty())
  new_file_name=PrefixName;

 if(!new_file_name.empty())
  new_file_name+=std::string(" ");

 if(OrderIndexToFileNameFlag)
 {
  new_file_name+=sntoa(CurrentFileIndex,8)+std::string(" ");
 }



 if(TimeToFileNameFlag)
 {
  new_file_name+=get_text_time(time_data,'.','-')+std::string(" ");
 }

 if(OldTimeStamp && OldTimeStamp != time_data)
 {
  CurrentFileNameNumber=1;
  CurrentFileName=new_file_name+sntoa(CurrentFileNameNumber,2);
 }
 else
 {
  ++CurrentFileNameNumber;
  CurrentFileName=new_file_name+sntoa(CurrentFileNameNumber,2);
 }
 OldTimeStamp=time_data;

 bool res=AFSCalculate();
 ++CurrentFileIndex;
 return res;
}
// --------------------------



}
#endif

