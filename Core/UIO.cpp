#ifndef UAIO_CPP
#define UAIO_CPP

#include "UIO.h"
//#include "../../UBinaryEnvSerialize.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UIO::UIO(void)
{
 AddLookupProperty("Direction",ptPubParameter, new UVProperty<int,UIO>(this,&UIO::SetDirection,&UIO::GetDirection));
}

UIO::~UIO(void)
{

}
// --------------------------

// --------------------------
// ������ ���������� �����������
// --------------------------
const int& UIO::GetDirection(void) const
{
 return Direction;
}

bool UIO::SetDirection(const int &value)
{
 Direction=value;
 return true;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UIO::ADefault(void)
{
 SetDirection(1);
// SetNumInputs(1);
// SetNumOutputs(1);
 return AIODefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UIO::ABuild(void)
{
 return AIOBuild();
}

// ����� �������� �����.
bool UIO::AReset(void)
{
 return AIOReset();
}

// ��������� ������ ����� �������
bool UIO::ACalculate(void)
{
 return AIOCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UIO::AIODefault(void)
{
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UIO::AIOBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UIO::AIOReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UIO::AIOCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

