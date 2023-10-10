#ifndef UFileDataset_H
#define UFileDataset_H

#include "UMatrixSourceFileSep.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UFileDataset: public UMatrixSourceFileSep
{
public:
/// ����� �������� � ��������
ULProperty<int, UFileDataset, ptPubState> NumSamples;

/// ������ �������� �������
ULProperty<int, UFileDataset> CurrentSample;

/// ������� ������
ULProperty<MDMatrix<double>, UFileDataset, ptPubOutput | ptState> SampleData;

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UFileDataset(void);
virtual ~UFileDataset(void);
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UFileDataset* New(void);
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
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

