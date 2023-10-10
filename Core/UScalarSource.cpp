#ifndef UScalarSource_CPP
#define UScalarSource_CPP

#include "UScalarSource.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UScalarSource::UScalarSource(void)
: Double("Double",this),
  LDouble("LDouble",this),
  Float("Float",this),
  Int("Int",this),
  Long("Long",this),
  ULong("ULong",this),
  LongLong("LongLong",this),
  ULongLong("ULongLong",this)
{
}

UScalarSource::~UScalarSource(void)
{

}
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UScalarSource* UScalarSource::New(void)
{                             
 return new UScalarSource;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UScalarSource::ADefault(void)
{
 return ASDefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UScalarSource::ABuild(void)
{
 return ASBuild();
}

// ����� �������� �����.
bool UScalarSource::AReset(void)
{
 return ASReset();
}

// ��������� ������ ����� �������
bool UScalarSource::ACalculate(void)
{
 return ASCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UScalarSource::ASDefault(void)
{
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UScalarSource::ASBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UScalarSource::ASReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UScalarSource::ASCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

