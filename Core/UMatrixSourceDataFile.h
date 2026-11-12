#ifndef UMatrixSourceDataFile_H
#define UMatrixSourceDataFile_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UMatrixSourceDataFile: public UNet
{
public: // 
///    
UProperty<std::string, UMatrixSourceDataFile, ptPubParameter> FileName;

///        
//UProperty<int, UMatrixSourceDataFile, ptPubParameter> ColCount;

///    -  
UProperty<bool, UMatrixSourceDataFile, ptPubParameter> IsCheckDateTime;

///         
UProperty<bool, UMatrixSourceDataFile, ptPubParameter> SkipCalcIfNoNewData;

///     
UProperty<bool, UMatrixSourceDataFile, ptPubParameter> ReloadFile;

///    
UProperty<bool, UMatrixSourceDataFile, ptPubState> IsNewData;

///        
UProperty<bool, UMatrixSourceDataFile, ptPubParameter> UseRelativePathFromConfig;

///         
UProperty<bool, UMatrixSourceDataFile, ptPubParameter> UseRelativePathFromWorkDir;

///     
UProperty<int, UMatrixSourceDataFile, ptPubState> RowCount;

///     
UProperty<int, UMatrixSourceDataFile, ptPubState> ColCount;

public: //    

///  double -   
UProperty<MDMatrix<double>, UMatrixSourceDataFile, ptPubState | ptOutput> FullMatrix;

protected:

public: // 
// --------------------------
//   
// --------------------------
UMatrixSourceDataFile(void);
virtual ~UMatrixSourceDataFile(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UMatrixSourceDataFile* New(void);
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

//     ColCount
//bool TransformData(MDMatrix<double> &matrix);

//:        
//bool StandartizeData(MDMatrix<double> &matrix);

// /    ,      
void UpdateCurrentLine();

};


}






//---------------------------------------------------------------------------
#endif

