#ifndef UMatrixSource_CPP
#define UMatrixSource_CPP

#include "UMatrixSource.h"
#include "../../../Rdk/Core/Engine/ModernSmartPointers.h"
#include "../../../Rdk/Core/Engine/ModernContainers.h"

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSource::UMatrixSource(void)
: DoubleMatrixInput("DoubleMatrixInput",this),
  IntMatrixInput("IntMatrixInput",this),
  DoubleVectorInput("DoubleVectorInput",this),
  IntVectorInput("IntVectorInput",this),

  DoubleMatrix("DoubleMatrix",this),
  IntMatrix("IntMatrix",this),
  DoubleVector("DoubleVector",this),
  IntVector("IntVector",this)
{
}

UMatrixSource::~UMatrixSource(void)
{

}
// --------------------------    

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UMatrixSource* UMatrixSource::New(void)
{                             
 return new UMatrixSource;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSource::ADefault(void)
{
 return ASDefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSource::ABuild(void)
{
 return ASBuild();
}

// ����� �������� �����.
bool UMatrixSource::AReset(void)
{
 return ASReset();
}

// ��������� ������ ����� �������
bool UMatrixSource::ACalculate(void)
{
 return ASCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSource::ASDefault(void)
{
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSource::ASBuild(void)
{
 return true;
}

// ����� �������� �����.
bool UMatrixSource::ASReset(void)
{
 return true;
}

// ��������� ������ ����� �������
bool UMatrixSource::ASCalculate(void)
{
 return true;
}
// --------------------------

// --------------------------
// Modern C++20 methods implementation
// --------------------------
template<typename T>
void UMatrixSource::ReserveMatrix(MDMatrix<T>& matrix, size_t rows, size_t cols) {
    // Reserve memory for efficient matrix operations
    matrix.reserve(rows);
    for (auto& row : matrix) {
        row.reserve(cols);
    }
}

template<typename T>
void UMatrixSource::MoveMatrix(MDMatrix<T>& target, MDMatrix<T>&& source) {
    // Efficient move operation for large matrices
    target = std::move(source);
}

bool UMatrixSource::IsValidMatrix() const {
    // Validate matrix data integrity
    return DoubleMatrix.GetData().GetSize() > 0 || 
           IntMatrix.GetData().GetSize() > 0 ||
           DoubleVector.GetData().GetSize() > 0 || 
           IntVector.GetData().GetSize() > 0;
}

void UMatrixSource::OptimizeMatrixOperations() {
    // Optimize matrix operations for better performance
    // This could include memory alignment, cache optimization, etc.
    if (DoubleMatrix.GetData().GetSize() > 0) {
        // Matrix optimization logic can be added here
        // For now, just validate that matrix has data
    }
}
// --------------------------

}
#endif

