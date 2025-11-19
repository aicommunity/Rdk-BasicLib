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
// ������������ � �����������
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
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UMatrixSourceDataFile* UMatrixSourceDataFile::New(void)
{
 return new UMatrixSourceDataFile;
}
// --------------------------


// --------------------------
// ������ ���������� �����������
// --------------------------
/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
bool UMatrixSourceDataFile::SetUseRelativePathFromConfig(const bool &value)
{
 UseRelativePathFromWorkDir=false;
 Ready=false;
 return true;
}

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
bool UMatrixSourceDataFile::SetUseRelativePathFromWorkDir(const bool &value)
{
 UseRelativePathFromConfig=false;
 Ready=false;
 return true;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSourceDataFile::ADefault(void)
{
 FileName="";
 IsCheckDateTime=true;
 SkipCalcIfNoNewData=true;
 UseRelativePathFromWorkDir=false;
 UseRelativePathFromConfig=true;
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSourceDataFile::ABuild(void)
{
 ReloadFile=true; //?
 return true;
}

// ����� �������� �����.
bool UMatrixSourceDataFile::AReset(void)
{
 IsNewData=false;
 ReloadFile = true;
 return true;
}

// ��������� ������ ����� �������
bool UMatrixSourceDataFile::ACalculate(void)
{
 bool res = true;
 if(ReloadFile.v==true)
 {
  std::string file_name=CalcActualSourceFilePath(FileName);
  res = ReadAndDecode(file_name);
  if(res)
  {
      ReloadFile.v = false; //� ����� ���������, ����� �� ������ ��� ������ ���
  }
 }


 if(!res)
 {
  // CRITICAL: GetOwner() now returns weak_ptr, need to lock before use
  std::weak_ptr<UContainer> owner_weak=GetOwner();
  if(!owner_weak.expired())
  {
   std::shared_ptr<UContainer> owner=owner_weak.lock();
   if(owner)
    owner->ForceSkipComponentCalculation();
  }

  return true;
 }

 return true;
}

/// ��������� ������, ������������� � ������ ������
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


/// ����������� �������� ���� �� ����� ������ �� �������� ������������� �����
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

