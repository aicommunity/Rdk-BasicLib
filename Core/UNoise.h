#ifndef UNOISE_H
#define UNOISE_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

template<class T>
class RDK_LIB_TYPE UNoise: public UNet
{
protected: // 
///   
///      
UProperty<MDMatrix<T>,UNoise<T>, ptPubInput> InputParams;

protected: // Output
/// Output parameters
UProperty<MDMatrix<T>,UNoise<T>, ptPubOutput> OutputParams;
/// Flag to use one error for all
UProperty<bool,UNoise<T>, ptPubParameter> OneErrorForAll;

public: // 
// --------------------------
//   
// --------------------------
UNoise(void);
virtual ~UNoise(void);
// --------------------------
//   
// --------------------------

// --------------------------
//    
// --------------------------
//         
//virtual NNeuronLife* New(void);
// --------------------------


// --------------------------
//    
// --------------------------
protected:
//        
virtual bool ADefault(void);

//     
//   
//    Reset()   Ready  true
//    
virtual bool ABuild(void);

//   .
virtual bool AReset(void);

//    
virtual bool ACalculate(void);
// --------------------------

// --------------------------
//    
// --------------------------
protected:
//        
virtual bool ANoiseDefault(void);

//     
//   
//    Reset()   Ready  true
//    
virtual bool ANoiseBuild(void);

//   .
virtual bool ANoiseReset(void);

//    
virtual bool ANoiseCalculate(void);
// --------------------------


};

// --------------------------
//   
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
//   
// --------------------------

// --------------------------
//    
// --------------------------
//         
// --------------------------


// --------------------------
//    
// --------------------------
//        
template<class T>
bool UNoise<T>::ADefault(void)
{
 return ANoiseDefault();
}

//     
//   
//    Reset()   Ready  true
//    
template<class T>
bool UNoise<T>::ABuild(void)
{
 return ANoiseBuild();
}

//   .
template<class T>
bool UNoise<T>::AReset(void)
{
 return ANoiseReset();
}

//    
template<class T>
bool UNoise<T>::ACalculate(void)
{
 if(!InputParams.IsConnected())
  return true;

 return ANoiseCalculate();
}
// --------------------------

// --------------------------
//    
// --------------------------
//        
template<class T>
bool UNoise<T>::ANoiseDefault(void)
{
 OneErrorForAll=false;
 return true;
}

//     
//   
//    Reset()   Ready  true
//    
template<class T>
bool UNoise<T>::ANoiseBuild(void)
{
 return true;
}

//   .
template<class T>
bool UNoise<T>::ANoiseReset(void)
{
 return true;
}

//    
template<class T>
bool UNoise<T>::ANoiseCalculate(void)
{
 return true;
}
// --------------------------


}






//---------------------------------------------------------------------------
#endif
