#ifndef UMatrixSourceFileSep_CPP
#define UMatrixSourceFileSep_CPP

#include "UMatrixSourceFileSep.h"

namespace RDK {

// --------------------------
// ������������ � �����������
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
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UMatrixSourceFileSep* UMatrixSourceFileSep::New(void)
{                             
 return new UMatrixSourceFileSep;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
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

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSourceFileSep::ABuild(void)
{
 if(!UMatrixSourceFile::ABuild())
  return false;

 return true;
}

// ����� �������� �����.
bool UMatrixSourceFileSep::AReset(void)
{
 if(!UMatrixSourceFile::AReset())
  return false;

 return true;
}

// ��������� ������ ����� �������
bool UMatrixSourceFileSep::ACalculate(void)
{
 if(!UMatrixSourceFile::ACalculate())
  return false;

 return true;
}

/// ��������� ������, ������������� � ������ ������
bool UMatrixSourceFileSep::ReadAndDecode(const std::string &file_name)
{
 std::string buffer;
 Matrix->Resize(0,0);
 if(SkipCalcIfNoNewData.v == true)
 {
  if(!LoadFile(file_name, buffer) || Separator->empty())
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

