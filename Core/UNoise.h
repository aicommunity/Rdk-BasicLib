#ifndef UNOISE_H
#define UNOISE_H

#include "../../../Rdk/Deploy/Include/rdk.h"
#include "UEPtr.h"
#include "ModernSmartPointers.h"
#include <memory>
#include <mutex>
#include <random>
#include <chrono>

namespace RDK {

template<class T>
class RDK_LIB_TYPE UNoise: public UNet
{
protected: // ���������
/// ������ �������������� ����������
/// ������ ������ ��������� ���� ����� ����������
UPropertyInputData<MDMatrix<T>,UNoise<T> > InputParams;

protected: // ������
/// ������ �������� ����������������� ����������
/// ������ ������ ��������� ���� ����� ����������
UPropertyOutputData<MDMatrix<T>,UNoise<T> > OutputParams;
// ���� ���������� ����������� ���� �� ���� ��������� �������
ULProperty<bool,UNoise<T> > OneErrorForAll;

public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UNoise(void);
virtual ~UNoise(void);

// Modern C++20 thread-safe noise generation
// Thread-safe noise generation
MDMatrix<T> GenerateNoiseSafe(size_t rows, size_t cols) const;
MDMatrix<T> GenerateNoiseSafe(size_t rows, size_t cols, T mean, T stddev) const;

// Modern random number generation
std::shared_ptr<std::mt19937> GetRandomEngine(void) const;
void SetRandomSeed(std::chrono::system_clock::time_point seed = std::chrono::system_clock::now());

// Modern move semantics
UNoise(UNoise&& other) noexcept;
UNoise& operator=(UNoise&& other) noexcept;

// Modern smart pointer factory
static std::shared_ptr<UNoise<T>> Create(void);
// --------------------------
// ������ ���������� �����������
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
//virtual NNeuronLife* New(void);
// --------------------------


// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ABuild(void);

// ����� �������� �����.
virtual bool AReset(void);

// ��������� ������ ����� �������
virtual bool ACalculate(void);
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ANoiseDefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ANoiseBuild(void);

// ����� �������� �����.
virtual bool ANoiseReset(void);

// ��������� ������ ����� �������
virtual bool ANoiseCalculate(void);
// --------------------------


};

// --------------------------
// ������������ � �����������
// --------------------------
template<class T>
UNoise<T>::UNoise(void)
   :InputParams("InputParams",this),
    OutputParams("OutputParams",this),
    OneErrorForAll("OneErrorForAll",this)
{

}

template<class T>
UNoise<T>::~UNoise(void)
{

}

// --------------------------
// ������ ���������� �����������
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
// --------------------------


// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
template<class T>
bool UNoise<T>::ADefault(void)
{
 return ANoiseDefault();
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
template<class T>
bool UNoise<T>::ABuild(void)
{
 return ANoiseBuild();
}

// ����� �������� �����.
template<class T>
bool UNoise<T>::AReset(void)
{
 return ANoiseReset();
}

// ��������� ������ ����� �������
template<class T>
bool UNoise<T>::ACalculate(void)
{
 if(!InputParams.IsConnected())
  return true;

 return ANoiseCalculate();
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
template<class T>
bool UNoise<T>::ANoiseDefault(void)
{
 OneErrorForAll=false;
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
template<class T>
bool UNoise<T>::ANoiseBuild(void)
{
 return true;
}

// ����� �������� �����.
template<class T>
bool UNoise<T>::ANoiseReset(void)
{
 return true;
}

// ��������� ������ ����� �������
template<class T>
bool UNoise<T>::ANoiseCalculate(void)
{
 return true;
}
// --------------------------


}






//---------------------------------------------------------------------------
#endif
