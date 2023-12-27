#ifndef UFileDataset_CPP
#define UFileDataset_CPP

#include "UFileDataset.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UFileDataset::UFileDataset(void)
: NumSamples("NumSamples",this),
  CurrentSample("CurrentSample",this),
  SampleData("SampleData",this)
{
}

UFileDataset::~UFileDataset(void)
{

}
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UFileDataset* UFileDataset::New(void)
{                             
 return new UFileDataset;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UFileDataset::ADefault(void)
{
 if(!UMatrixSourceFileSep::ADefault())
  return false;

 CurrentSample=0;
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UFileDataset::ABuild(void)
{
 if(!UMatrixSourceFileSep::ABuild())
  return false;

 return true;
}

// ����� �������� �����.
bool UFileDataset::AReset(void)
{
 if(!UMatrixSourceFileSep::AReset())
  return false;

 NumSamples=Matrix->GetRows();

 if(CurrentSample>=0 && CurrentSample.v<NumSamples.v)
  SampleData=Matrix->GetRow(CurrentSample);
 else
  SampleData->Resize(0,0);

 return true;
}

// ��������� ������ ����� �������
bool UFileDataset::ACalculate(void)
{
 if(!UMatrixSourceFileSep::ACalculate())
  return false;

 NumSamples=Matrix->GetRows();
 if(CurrentSample.v>=0 && CurrentSample.v<NumSamples.v)
  SampleData=Matrix->GetRow(CurrentSample);
 else
  SampleData->Resize(0,0);


 return true;
}

// --------------------------

}
#endif

