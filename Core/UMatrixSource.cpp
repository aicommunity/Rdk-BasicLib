#ifndef UMatrixSource_CPP
#define UMatrixSource_CPP

#include "UMatrixSource.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSource::UMatrixSource(void)
: DoubleMatrixInput("DoubleMatrixInput",this),
  IntMatrixInput("IntMatrixInput",this),
  DoubleVectorInput("DoubleVectorInput",this),
  IntVectorInput("IntVectorInput",this),

  DoubleMatrix("DoubleMatrix",this),
  IntMatrix("IntMatrix",this),
  DoubleVector("DoubleVector",this),
  IntVector("IntVector",this)
{
}

UMatrixSource::~UMatrixSource(void)
{

}
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UMatrixSource* UMatrixSource::New(void)
{                             
 return new UMatrixSource;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSource::ADefault(void)
{
 return ASDefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSource::ABuild(void)
{
 return ASBuild();
}

// ����� �������� �����.
bool UMatrixSource::AReset(void)
{
 return ASReset();
}

// ��������� ������ ����� �������
bool UMatrixSource::ACalculate(void)
{
 return ASCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSource::ASDefault(void)
{
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSource::ASBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UMatrixSource::ASReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UMatrixSource::ASCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

