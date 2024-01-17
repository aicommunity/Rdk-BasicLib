#ifndef UNOISE_GEN_H
#define UNOISE_GEN_H

#include <string>
#include "UNoise.h"
#if __cplusplus >= 201103L
#include <random>
#endif

namespace RDK{

template<class T>
class RDK_LIB_TYPE UNoiseGen: public UNoise<T>
{
protected: // Параметры

protected: // Данные
// Уровень шума
UProperty<double, UNoiseGen<T>, ptPubParameter> NoiseLevel;

protected: // Временные переменные
#if __cplusplus >= 201103L
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
#endif

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UNoiseGen(void);
virtual ~UNoiseGen(void);
// --------------------------

// --------------------------
// Методы управления данными
// --------------------------
T GenerateNoise(double lvlNoise);
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
public:
// Выделяет память для новой чистой копии объекта этого класса
virtual UNoiseGen* New(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ANoiseDefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool ANoiseBuild(void);

// Сброс процесса счета.
virtual bool ANoiseReset(void);

// Выполняет расчет этого объекта
virtual bool ANoiseCalculate(void);
// --------------------------

// --------------------------
// Вспомогательные методы расчета
// --------------------------
protected:

// --------------------------

};


// --------------------------
// Конструкторы и деструкторы
// --------------------------
template<class T>
UNoiseGen<T>::UNoiseGen(void)
 : NoiseLevel("NoiseLevel", this)
#if __cplusplus >= 201103L
 , gen(rd())
#endif
{
}

template<class T>
UNoiseGen<T>::~UNoiseGen(void)
{

}
// --------------------------

// --------------------------
// Методы управления данными
// --------------------------
template<class T>
T UNoiseGen<T>::GenerateNoise(double lvlNoise)
{
#if __cplusplus >= 201103L
 if(typeid(int) == typeid(T))
 {
  std::uniform_int_distribution<> distrib_int(-int(lvlNoise),int(lvlNoise));
  return distrib_int(gen);
 }

 std::uniform_real_distribution<> distrib_real(-lvlNoise,lvlNoise);
 return T(distrib_real(gen));
#else
 if(typeid(int) == typeid(T))
  return ceil(2.0*lvlNoise*((rand()/((double)RAND_MAX))-0.5));
 return 2.0*lvlNoise*((rand()/((double)RAND_MAX))-0.5);
#endif
}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса

template<class T>
UNoiseGen<T>* UNoiseGen<T>::New(void)
{
 return new UNoiseGen;
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
template<class T>
bool UNoiseGen<T>::ANoiseDefault(void)
{
 NoiseLevel=0;

 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
template<class T>
bool UNoiseGen<T>::ANoiseBuild(void)
{
 return true;
}

// Сброс процесса счета.
template<class T>
bool UNoiseGen<T>::ANoiseReset(void)
{
 time_t time_val;
 time(&time_val);

 srand(unsigned(time_val));
 return true;
}

// Выполняет расчет этого объекта
template<class T>
bool UNoiseGen<T>::ANoiseCalculate(void)
{
 MDMatrix<T> &aInput=(*this->InputParams);
 MDMatrix<T> &aOutput=(*this->OutputParams);

 this->OutputParams->Resize(this->InputParams->GetRows(),this->InputParams->GetCols());
 if(this->OneErrorForAll){
    T Noise = GenerateNoise(NoiseLevel);
    for(int i=0; i<this->InputParams->GetRows(); i++)
    {
     for(int j=0; j<this->InputParams->GetCols(); j++)
     {
      aOutput(i,j)=aInput(i,j)+Noise;
     }
    }
}else{
    for(int i=0; i<this->InputParams->GetRows(); i++)
    {
     for(int j=0; j<this->InputParams->GetCols(); j++)
     {
      aOutput(i,j)=aInput(i,j)+GenerateNoise(NoiseLevel);
     }
    }
}
 return true;
}
// --------------------------

}
#endif
