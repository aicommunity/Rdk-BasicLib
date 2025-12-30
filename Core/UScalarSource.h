#ifndef UScalarSource_H
#define UScalarSource_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UScalarSource: public UNet
{
protected: // 

public: //    
/// double
UProperty<double, UScalarSource, ptPubParameter | ptOutput> Double;

/// long double
UProperty<long double, UScalarSource, ptPubParameter | ptOutput> LDouble;

/// float
UProperty<float, UScalarSource, ptPubParameter | ptOutput> Float;

/// int
UProperty<int, UScalarSource, ptPubParameter | ptOutput> Int;

/// long
UProperty<long, UScalarSource, ptPubParameter | ptOutput> Long;

/// unsigned long
UProperty<unsigned long, UScalarSource, ptPubParameter | ptOutput> ULong;

/// long long
UProperty<long, UScalarSource, ptPubParameter | ptOutput> LongLong;

/// unsigned long long
UProperty<unsigned long, UScalarSource, ptPubParameter | ptOutput> ULongLong;


public: // 
// --------------------------
//   
// --------------------------
UScalarSource(void);
virtual ~UScalarSource(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UScalarSource* New(void);
// --------------------------

// --------------------------
//    
// --------------------------
protected:
///        
virtual bool ADefault(void);

///     
///   
///    Reset()   Ready  true
///    
virtual bool ABuild(void);

///   .
virtual bool AReset(void);

///    
virtual bool ACalculate(void);
// --------------------------

// --------------------------
//    
// --------------------------
protected:
///        
virtual bool ASDefault(void);

///     
///   
///    Reset()   Ready  true
///    
virtual bool ASBuild(void);

///   .
virtual bool ASReset(void);

///    
virtual bool ASCalculate(void);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

