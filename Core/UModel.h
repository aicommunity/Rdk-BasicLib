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
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"
#include "../../../Rdk/Core/Engine/ModernContainers.h"

namespace RDK {

class RDK_LIB_TYPE UModel: public UNet
{
protected: // �������� ��������

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UModel(void);
UModel(const UModel&) = default;
UModel(UModel&&) noexcept = default;
virtual ~UModel(void);

UModel& operator=(const UModel&) = default;
UModel& operator=(UModel&&) noexcept = default;
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



