#ifndef UMatrixSource_H
#define UMatrixSource_H

#include "../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"
#include "../../../Rdk/Core/Engine/ModernContainers.h"

namespace RDK {
                                                        
/// �����-�������� ������ ������
class RDK_LIB_TYPE UMatrixSource: public UNet
{
protected: // ���������

public: // ������� � �������� ������
/// ������� double
UPropertyInputData<MDMatrix<double>, UMatrixSource> DoubleMatrixInput;

/// ������� int
UPropertyInputData<MDMatrix<int>, UMatrixSource> IntMatrixInput;

/// ������ double
UPropertyInputData<MDVector<double>, UMatrixSource> DoubleVectorInput;

/// ������ int
UPropertyInputData<MDVector<int>, UMatrixSource> IntVectorInput;

/// ������� double
UPropertyOutputData<MDMatrix<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleMatrix;

/// ������� int
UPropertyOutputData<MDMatrix<int>, UMatrixSource, ptPubParameter | ptOutput> IntMatrix;

/// ������ double
UPropertyOutputData<MDVector<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleVector;

/// ������ int
UPropertyOutputData<MDVector<int>, UMatrixSource, ptPubParameter | ptOutput> IntVector;

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSource(void);
UMatrixSource(const UMatrixSource&) = default;
UMatrixSource(UMatrixSource&&) noexcept = default;
virtual ~UMatrixSource(void);

UMatrixSource& operator=(const UMatrixSource&) = default;
UMatrixSource& operator=(UMatrixSource&&) noexcept = default;
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
public:
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual UMatrixSource* New(void);
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

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
/// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ASDefault(void);

/// ������������ ������ ���������� ��������� �������
/// ����� ��������� ����������
/// ������������� �������� ����� Reset() � ���������� Ready � true
/// � ������ �������� ������
virtual bool ASBuild(void);

/// ����� �������� �����.
virtual bool ASReset(void);

/// ��������� ������ ����� �������
virtual bool ASCalculate(void);
// --------------------------


// --------------------------
// Modern C++20 methods
// --------------------------
// Efficient matrix operations using modern containers
template<typename T>
void ReserveMatrix(MDMatrix<T>& matrix, size_t rows, size_t cols);

// Move semantics for large matrices
template<typename T>
void MoveMatrix(MDMatrix<T>& target, MDMatrix<T>&& source);

// Modern matrix validation
bool IsValidMatrix() const;

// Performance optimized operations
void OptimizeMatrixOperations();
// --------------------------

};


}






//---------------------------------------------------------------------------
#endif

