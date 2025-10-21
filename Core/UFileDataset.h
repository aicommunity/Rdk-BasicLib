#ifndef UFileDataset_H
#define UFileDataset_H

#include "UMatrixSourceFileSep.h"
#include "UEPtr.h"
#include "ModernSmartPointers.h"
#include <filesystem>
#include <memory>
#include <mutex>

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

// Modern C++20 methods with std::filesystem
// Thread-safe file operations
bool LoadDatasetSafe(const std::filesystem::path& filepath);
bool SaveDatasetSafe(const std::filesystem::path& filepath) const;

// Modern move semantics
UFileDataset(UFileDataset&& other) noexcept;
UFileDataset& operator=(UFileDataset&& other) noexcept;

// Modern smart pointer factory
static std::shared_ptr<UFileDataset> Create(const std::filesystem::path& filepath);
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

