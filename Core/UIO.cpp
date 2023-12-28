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
 : Direction("Direction", this)
{
}

UIO::~UIO(void)
{

}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UIO::ADefault(void)
{
 Direction=1;
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

