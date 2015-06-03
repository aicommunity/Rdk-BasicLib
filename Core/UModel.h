// ===========================================================
// Version:        3.0.3
// ===========================================================
/* ***********************************************************
@Copyright Alexander V. Bakhshiev, 2002.
E-mail:		alexab@ailab.ru
url:            http://ailab.ru

This file - part of the project: RDK

File License:        BSD License
See file license.txt for more information
*********************************************************** */
#ifndef UMODEL_H
#define UMODEL_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

class RDK_LIB_TYPE UModel: public UNet
{
protected: // �������� ��������

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UModel(void);
virtual ~UModel(void);
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UModel* New(void);
// --------------------------
};

}

#endif



