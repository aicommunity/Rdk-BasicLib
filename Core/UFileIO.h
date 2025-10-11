//---------------------------------------------------------------------------

#ifndef UAFileIOH
#define UAFileIOH

#include "UIO.h"
#include <string>
#include <filesystem>
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"
#include "../../../Rdk/Core/Engine/ModernContainers.h"

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
UFileIO(const UFileIO&) = default;
UFileIO(UFileIO&&) noexcept = default;
virtual ~UFileIO(void);

UFileIO& operator=(const UFileIO&) = default;
UFileIO& operator=(UFileIO&&) noexcept = default;
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

// --------------------------
// Modern C++20 methods
// --------------------------
// Check if file exists using std::filesystem
bool FileExists() const;

// Get file size using std::filesystem
std::uintmax_t GetFileSize() const;

// Create directory if not exists
bool EnsureDirectoryExists() const;

// Modern file operations with std::filesystem
std::filesystem::path GetFilePath() const;
// --------------------------

};




//---------------------------------------------------------------------------
}
#endif

