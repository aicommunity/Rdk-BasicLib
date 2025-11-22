#ifndef UMatrixSourceFile_H
#define UMatrixSourceFile_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UMatrixSourceFile: public UNet
{
public: // 
///    
UProperty<std::string, UMatrixSourceFile, ptPubParameter> FileName;

///    -  
UProperty<bool, UMatrixSourceFile, ptPubParameter> IsCheckDateTime;

///         
UProperty<bool, UMatrixSourceFile, ptPubParameter> SkipCalcIfNoNewData;

///    
UProperty<bool, UMatrixSourceFile, ptPubState> IsNewData;

///        
UProperty<bool, UMatrixSourceFile, ptPubParameter> UseRelativePathFromConfig;

///         
UProperty<bool, UMatrixSourceFile, ptPubParameter> UseRelativePathFromWorkDir;

public: //    
///  double
UProperty<MDMatrix<double>, UMatrixSourceFile, ptPubParameter | ptOutput> Matrix;


protected:

FILETIME LastWriteTime;

public: // 
// --------------------------
//   
// --------------------------
UMatrixSourceFile(void);
virtual ~UMatrixSourceFile(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UMatrixSourceFile* New(void);
// --------------------------


// --------------------------
//   
// --------------------------
///        
bool SetUseRelativePathFromConfig(const bool &value);

///         
bool SetUseRelativePathFromWorkDir(const bool &value);
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

///  ,    
virtual bool ReadAndDecode(const std::string &file_name);

///          
std::string CalcActualSourceFilePath(const std::string &file_name);
// --------------------------


};


}






//---------------------------------------------------------------------------
#endif

