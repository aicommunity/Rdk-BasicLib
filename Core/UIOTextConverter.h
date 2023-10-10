//---------------------------------------------------------------------------

#ifndef UIOTextConverterH
#define UIOTextConverterH

#include "UIOConverter.h"
#include <string>

namespace RDK{

class RDK_LIB_TYPE UIOTextConverter: public UIOConverter
{
public: // ���������
/// ����� ����� ������
/// 0 - ��������
/// 1 - ���������, ��������� ������� - ������ ������->�������� ������
/// 2 - ���������, ��������� ������ - ������ ������->�������� ������
ULProperty<int, UIOTextConverter> InputMode;

/// ����� ������ ������
/// 0 - ��������
/// 1 - ���������, ���������� ������� - ������ �������� ������->������
/// 2 - ���������, ���������� ������ - ������ �������� ������->������
ULProperty<int, UIOTextConverter> OutputMode;

/// ������������ ����� �������������� �����/��������
ULProperty<int, UIOTextConverter> MaxColumns;

public: // ����� � ������
/// ������������ ������
UPropertyInputData<MDMatrix<double>, UIOTextConverter> Input;

/// ����������� ������
UPropertyOutputData<MDMatrix<double>, UIOTextConverter> Output;

protected: // ��������� ����������
std::string OutData;
std::vector<string> Separate1;
std::vector<string> Separate2;

std::vector<UItemData> DataAfterRead;


public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UIOTextConverter(void);
virtual ~UIOTextConverter(void);
// --------------------------

// --------------------------
// ������ ���������� �����������
// --------------------------
bool SetInputMode(const int &value);

bool SetOutputMode(const int &value);

bool SetMaxColumns(const int &value);
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UIOTextConverter* New(void);
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool AIODefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool AIOBuild(void);

// ����� �������� �����.
virtual bool AIOReset(void);

// ��������� ������ ����� �������
virtual bool AIOCalculate(void);
// --------------------------

// --------------------------
// ��������������� ������ �������
// --------------------------
protected:
// ��������������� ������ ������ � �������� ����������� ������� ������
void ConvertFromTextColumns(const string &text, std::vector<UItemData> &data);
void ConvertFromTextRows(const string &text, std::vector<UItemData> &data);

// ��������������� ����������� ������� ������ � ������ ������
void ConvertToTextColumns(const std::vector<UItemData> &data, string &text);
void ConvertToTextRows(const std::vector<UItemData> &data, string &text);
// --------------------------

};




//---------------------------------------------------------------------------
}
#endif

