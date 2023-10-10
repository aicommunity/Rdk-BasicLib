#ifndef UAIOConverter_CPP
#define UAIOConverter_CPP

#include "UIOConverter.h"
//#include "../../UBinaryEnvSerialize.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UIOConverter::UIOConverter(void)
{
}

UIOConverter::~UIOConverter(void)
{

}
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
//virtual NNeuronLife* New(void);
// --------------------------


// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UIOConverter::ADefault(void)
{
// SetNumOutputs(1);
 return AIODefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UIOConverter::ABuild(void)
{
 return AIOBuild();
}

// ����� �������� �����.
bool UIOConverter::AReset(void)
{
 return AIOReset();
}

// ��������� ������ ����� �������
bool UIOConverter::ACalculate(void)
{
 return AIOCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UIOConverter::AIODefault(void)
{
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UIOConverter::AIOBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UIOConverter::AIOReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UIOConverter::AIOCalculate(void)
{
 return true;
}
// --------------------------

}
#endif

