#ifndef UIOLibrary_H
#define UIOLibrary_H

#include "../../../Rdk/Deploy/Include/rdk.h"
#include "UIO.h"
//#include "UFileIO.h"
#include "UIOConverter.h"
//#include "UIOTextConverter.h"

namespace RDK {

class RDK_LIB_TYPE UIOLibrary: public ULibrary
{
public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UIOLibrary(void);
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
virtual void CreateClassSamples(UStorage *storage);
// --------------------------
};

extern RDK_LIB_TYPE UIOLibrary IOLibrary;

}
#endif

