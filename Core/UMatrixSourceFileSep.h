#ifndef UMatrixSourceFileSep_H
#define UMatrixSourceFileSep_H

#include "UMatrixSourceFile.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UMatrixSourceFileSep: public UMatrixSourceFile
{
public:
/// ������-�����������
ULProperty<std::string,UMatrixSourceFileSep> Separator;

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSourceFileSep(void);
virtual ~UMatrixSourceFileSep(void);
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UMatrixSourceFileSep* New(void);
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
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

