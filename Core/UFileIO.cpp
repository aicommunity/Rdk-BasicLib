#ifndef UAFileIO_CPP
#define UAFileIO_CPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include "UFileIO.h"
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"
#include "../../../Rdk/Core/Engine/ModernContainers.h"

namespace RDK {

// --------------------------
// ������������ � �����������
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
// ������ ���������� �����������
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
// ������ ���������� �������
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
 // ������� �� ������� ����� �������� ��������� ���� ������
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
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UFileIO* UFileIO::New(void)
{
 return new UFileIO;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UFileIO::AIODefault(void)
{
 SetReadPartSize(2048);
 SetBinFlag(0);
 SetClearFlag(0);
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UFileIO::AIOBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UFileIO::AIOReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UFileIO::AIOCalculate(void)
{
 if(Direction == 0)
 {
  ReadData();
  if(NumOutputs == 0)
   return true;
  int result_size=int(DataString.size())/GetOutputData(0).GetElementByteSize();
  if(DataString.size() % GetOutputData(0).GetElementByteSize() != 0)
   result_size++;
  SetOutputDataSize(0,MMatrixSize(1,result_size));
  if(DataString.size())
   memcpy(POutputData[0].UChar,&DataString[0],DataString.size());
  *Output=POutputData[0];
 }
 else
 if(Direction == 1)
 {
  if(NumInputs == 0 || !GetInputData(0) || (GetInputData(0)->GetByteSize() == 0 && !Input.IsConnected()))
  {
   DataString.resize(0);
  }
  else
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
   DataString.resize(input->GetByteSize());
   if(input->GetByteSize())
	memcpy(&DataString[0],input->UChar,DataString.size());
  }
  WriteData();
 }
 return true;
}
// --------------------------

// --------------------------
// Modern C++20 methods implementation
// --------------------------
bool UFileIO::FileExists() const {
    try {
        return std::filesystem::exists(FileName.GetData());
    } catch (const std::filesystem::filesystem_error&) {
        return false;
    }
}

std::uintmax_t UFileIO::GetFileSize() const {
    try {
        if (FileExists()) {
            return std::filesystem::file_size(FileName.GetData());
        }
    } catch (const std::filesystem::filesystem_error&) {
        // Return 0 on error
    }
    return 0;
}

bool UFileIO::EnsureDirectoryExists() const {
    try {
        std::filesystem::path file_path = FileName.GetData();
        std::filesystem::path dir_path = file_path.parent_path();
        
        if (!dir_path.empty() && !std::filesystem::exists(dir_path)) {
            return std::filesystem::create_directories(dir_path);
        }
        return true;
    } catch (const std::filesystem::filesystem_error&) {
        return false;
    }
}

std::filesystem::path UFileIO::GetFilePath() const {
    return std::filesystem::path(FileName.GetData());
}
// --------------------------

}
#endif


