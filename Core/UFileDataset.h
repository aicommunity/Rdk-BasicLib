#ifndef UFileDataset_H
#define UFileDataset_H

#include "UMatrixSourceFileSep.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UFileDataset: public UMatrixSourceFileSep
{
public:
///    
UProperty<int, UFileDataset, ptPubState> NumSamples;

///   
UProperty<int,UFileDataset, ptPubParameter> CurrentSample;

///  
UProperty<MDMatrix<double>, UFileDataset, ptPubOutput | ptState> SampleData;

public: // 
// --------------------------
//   
// --------------------------
UFileDataset(void);
virtual ~UFileDataset(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UFileDataset* New(void);
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


};


}






//---------------------------------------------------------------------------
#endif

