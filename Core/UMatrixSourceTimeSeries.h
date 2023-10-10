#ifndef UMatrixSourceTimeSeries_H
#define UMatrixSourceTimeSeries_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UMatrixSourceTimeSeries: public UNet
{
public: // ���������
/// ��� ����� � �������
ULProperty<std::string, UMatrixSourceTimeSeries> FileName;

/// ����� ������� � ��������������� �� ���������� ���� �������
ULProperty<int, UMatrixSourceTimeSeries> ColCount;

/// ���� ������������� �������������� ������� ������
ULProperty<bool, UMatrixSourceTimeSeries> IsStandartizeData;

/// ���� ������������� �������� ����-������� ���������� �����
ULProperty<bool, UMatrixSourceTimeSeries> IsCheckDateTime;

/// ���� ������������� �������� ������� ���� �� ���� ������ ������
ULProperty<bool, UMatrixSourceTimeSeries> SkipCalcIfNoNewData;

/// ���� ������� ����� ������
ULProperty<bool, UMatrixSourceTimeSeries, ptPubState> IsNewData;

/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
ULProperty<bool, UMatrixSourceTimeSeries> UseRelativePathFromConfig;

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
ULProperty<bool, UMatrixSourceTimeSeries> UseRelativePathFromWorkDir;

public: // ������� � �������� ������
/// ������� double - ������ �������� �������
UPropertyOutputData<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> FullMatrix;

/// ������� double - ������� ������ �������� �������
UPropertyOutputData<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> CurrentLine;
/// ������ �������� �������
UPropertyOutputData<int, UMatrixSourceTimeSeries, ptPubState> CurrentLineIndex;


protected:

int current_line_index;
std::vector<double> source_timeseries;

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSourceTimeSeries(void);
virtual ~UMatrixSourceTimeSeries(void);
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UMatrixSourceTimeSeries* New(void);
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
bool TransformData(MDMatrix<double> &matrix);

//���������������: ������� ����������� ���� ���� � �������� �� ���
bool StandartizeData(MDMatrix<double> &matrix);

//�������� / ����������� ������� ������ �������, ������� ������������ ����������� � �������� ������
void UpdateCurrentLine();

};


}






//---------------------------------------------------------------------------
#endif

