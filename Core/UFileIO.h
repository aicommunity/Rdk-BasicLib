//---------------------------------------------------------------------------

#ifndef UAFileIOH
#define UAFileIOH

#include "UIO.h"
#include <string>

namespace RDK{

class RDK_LIB_TYPE UFileIO: public UIO
{
public: // ���������
/// ���� ������ �������� �����, �������� ���� 1 ��� ���������
ULProperty<int,UFileIO> BinFlag;

/// ���� ������� ����� ����� �������, ���� 1 �� ������
ULProperty<int,UFileIO> ClearFlag;

/// ����� ������������ ����� �����
ULProperty<std::streamsize,UFileIO> ReadPartSize;

/// ��� ����� � ������� ����� ��������
ULProperty<std::string,UFileIO> FileName;

public: // ����� � ������
/// ������������ ������
UPropertyInputData<MDMatrix<double>, UFileIO> Input;

/// ����������� ������
UPropertyOutputData<MDMatrix<double>, UFileIO> Output;

protected: // ��������� ����������
/// ��������� ���������� ��� ������������� ������ � ������ ������
std::string DataString;


public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UFileIO(void);
virtual ~UFileIO(void);
// --------------------------

// --------------------------
// ������ ���������� �����������
// --------------------------
bool SetBinFlag(const int &bin_flag);

bool SetClearFlag(const int &clear_flag);

bool SetReadPartSize(const std::streamsize &value);

bool SetFileName(const std::string& file_name);
// --------------------------


// --------------------------
// ������ ���������� �������
// --------------------------
const std::string& GetDataString(void) const;
bool SetDataString(const std::string& data_string);

bool WriteData();
char ReadData();
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UFileIO* New(void);
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

};




//---------------------------------------------------------------------------
}
#endif

