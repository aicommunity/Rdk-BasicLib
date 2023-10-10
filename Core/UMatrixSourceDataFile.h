#ifndef UMatrixSourceDataFile_H
#define UMatrixSourceDataFile_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UMatrixSourceDataFile: public UNet
{
public: // ���������
/// ��� ����� � �������
ULProperty<std::string, UMatrixSourceDataFile> FileName;

/// ����� ������� � ��������������� �� ���������� ���� �������
//ULProperty<int, UMatrixSourceDataFile> ColCount;

/// ���� ������������� �������� ����-������� ���������� �����
ULProperty<bool, UMatrixSourceDataFile> IsCheckDateTime;

/// ���� ������������� �������� ������� ���� �� ���� ������ ������
ULProperty<bool, UMatrixSourceDataFile> SkipCalcIfNoNewData;

/// ���������� ������������� ������ �� �����
ULProperty<bool, UMatrixSourceDataFile> ReloadFile;

/// ���� ������� ����� ������
ULProperty<bool, UMatrixSourceDataFile, ptPubState> IsNewData;

/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
ULProperty<bool, UMatrixSourceDataFile> UseRelativePathFromConfig;

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
ULProperty<bool, UMatrixSourceDataFile> UseRelativePathFromWorkDir;

/// ����� ����� � ����������� �������
ULProperty<int, UMatrixSourceDataFile, ptPubState> RowCount;

/// ����� �������� � ����������� �������
ULProperty<int, UMatrixSourceDataFile, ptPubState> ColCount;

public: // ������� � �������� ������

/// ������� double - ������ �������� �������
UPropertyOutputData<MDMatrix<double>, UMatrixSourceDataFile, ptPubState | ptOutput> FullMatrix;

protected:

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSourceDataFile(void);
virtual ~UMatrixSourceDataFile(void);
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UMatrixSourceDataFile* New(void);
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

//������������� ������ � ������� ������� ColCount
//bool TransformData(MDMatrix<double> &matrix);

//���������������: ������� ����������� ���� ���� � �������� �� ���
//bool StandartizeData(MDMatrix<double> &matrix);

//�������� / ����������� ������� ������ �������, ������� ������������ ����������� � �������� ������
void UpdateCurrentLine();

};


}






//---------------------------------------------------------------------------
#endif

