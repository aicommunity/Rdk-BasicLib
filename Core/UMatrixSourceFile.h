#ifndef UMatrixSourceFile_H
#define UMatrixSourceFile_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UMatrixSourceFile: public UNet
{
public: // ���������
/// ��� ����� � �������
ULProperty<std::string, UMatrixSourceFile> FileName;

/// ���� ������������� �������� ����-������� ���������� �����
ULProperty<bool, UMatrixSourceFile> IsCheckDateTime;

/// ���� ������������� �������� ������� ���� �� ���� ������ ������
ULProperty<bool, UMatrixSourceFile> SkipCalcIfNoNewData;

/// ���� ������� ����� ������
ULProperty<bool, UMatrixSourceFile, ptPubState> IsNewData;

/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
ULProperty<bool, UMatrixSourceFile> UseRelativePathFromConfig;

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
ULProperty<bool, UMatrixSourceFile> UseRelativePathFromWorkDir;

public: // ������� � �������� ������
/// ������� double
UPropertyOutputData<MDMatrix<double>, UMatrixSourceFile, ptPubParameter | ptOutput> Matrix;


protected:

#ifdef _WIN32
FILETIME LastWriteTime;
#else
// On Linux, use std::filesystem::file_time_type or similar
std::filesystem::file_time_type LastWriteTime;
#endif

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSourceFile(void);
virtual ~UMatrixSourceFile(void);
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UMatrixSourceFile* New(void);
// --------------------------


// --------------------------
// ������ ���������� �����������
// --------------------------
/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
bool SetUseRelativePathFromConfig(const bool &value);

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
bool SetUseRelativePathFromWorkDir(const bool &value);
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
/// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADefault(void);

/// ������������ ������ ���������� ��������� �������
/// ����� ��������� ����������
/// ������������� �������� ����� Reset() � ���������� Ready � true
/// � ������ �������� ������
virtual bool ABuild(void);

/// ����� �������� �����.
virtual bool AReset(void);

/// ��������� ������ ����� �������
virtual bool ACalculate(void);

/// ��������� ������, ������������� � ������ ������
virtual bool ReadAndDecode(const std::string &file_name);

/// ����������� �������� ���� �� ����� ������ �� �������� ������������� �����
std::string CalcActualSourceFilePath(const std::string &file_name);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

