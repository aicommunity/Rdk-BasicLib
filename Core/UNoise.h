#ifndef UNOISE_H
#define UNOISE_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

template<class T>
class RDK_LIB_TYPE UNoise: public UNet
{
protected: // Параметры
/// Вектор прогнозируемых параметров
/// Каждая строка описывает один набор параметров
UPropertyInputData<MDMatrix<T>,UNoise<T> > InputParams;

protected: // Данные
/// Вектор выходных спрогнозированных параметров
/// Каждая строка описывает один набор параметров
UPropertyOutputData<MDMatrix<T>,UNoise<T> > OutputParams;
// Флаг применения одинакового шума ко всем элементам массива
ULProperty<bool,UNoise<T> > OneErrorForAll;

public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UNoise(void);
virtual ~UNoise(void);
// --------------------------
// Методы управления параметрами
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
//virtual NNeuronLife* New(void);
// --------------------------


// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ADefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool ABuild(void);

// Сброс процесса счета.
virtual bool AReset(void);

// Выполняет расчет этого объекта
virtual bool ACalculate(void);
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


};

// --------------------------
// Конструкторы и деструкторы
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
// Методы управления параметрами
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
// --------------------------


// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
template<class T>
bool UNoise<T>::ADefault(void)
{
 return ANoiseDefault();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
template<class T>
bool UNoise<T>::ABuild(void)
{
 return ANoiseBuild();
}

// Сброс процесса счета.
template<class T>
bool UNoise<T>::AReset(void)
{
 return ANoiseReset();
}

// Выполняет расчет этого объекта
template<class T>
bool UNoise<T>::ACalculate(void)
{
 if(!InputParams.IsConnected())
  return true;

 return ANoiseCalculate();
}
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
// Восстановление настроек по умолчанию и сброс процесса счета
template<class T>
bool UNoise<T>::ANoiseDefault(void)
{
 OneErrorForAll=false;
 return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
template<class T>
bool UNoise<T>::ANoiseBuild(void)
{
 return true;
}

// Сброс процесса счета.
template<class T>
bool UNoise<T>::ANoiseReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
template<class T>
bool UNoise<T>::ANoiseCalculate(void)
{
 return true;
}
// --------------------------


}






//---------------------------------------------------------------------------
#endif
