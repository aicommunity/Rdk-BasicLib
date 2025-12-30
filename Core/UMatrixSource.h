#ifndef UMatrixSource_H
#define UMatrixSource_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UMatrixSource: public UNet
{
protected: // 

public: //    
///  double
UProperty<MDMatrix<double>, UMatrixSource, ptPubInput> DoubleMatrixInput;

///  int
UProperty<MDMatrix<int>, UMatrixSource, ptPubInput> IntMatrixInput;

///  double
UProperty<MDVector<double>, UMatrixSource, ptPubInput> DoubleVectorInput;

///  int
UProperty<MDVector<int>, UMatrixSource, ptPubInput> IntVectorInput;

///  double
UProperty<MDMatrix<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleMatrix;

///  int
UProperty<MDMatrix<int>, UMatrixSource, ptPubParameter | ptOutput> IntMatrix;

///  double
UProperty<MDVector<double>, UMatrixSource, ptPubParameter | ptOutput> DoubleVector;

///  int
UProperty<MDVector<int>, UMatrixSource, ptPubParameter | ptOutput> IntVector;

public: // 
// --------------------------
//   
// --------------------------
UMatrixSource(void);
virtual ~UMatrixSource(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UMatrixSource* New(void);
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

