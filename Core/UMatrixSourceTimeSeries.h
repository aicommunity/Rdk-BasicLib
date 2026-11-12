#ifndef UMatrixSourceTimeSeries_H
#define UMatrixSourceTimeSeries_H

#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {
                                                        
/// -  
class RDK_LIB_TYPE UMatrixSourceTimeSeries: public UNet
{
public: // 
///    
UProperty<std::string, UMatrixSourceTimeSeries, ptPubParameter> FileName;

///        
UProperty<int, UMatrixSourceTimeSeries, ptPubParameter> ColCount;

///     
UProperty<bool, UMatrixSourceTimeSeries, ptPubParameter> IsStandartizeData;

///    -  
UProperty<bool, UMatrixSourceTimeSeries, ptPubParameter> IsCheckDateTime;

///         
UProperty<bool, UMatrixSourceTimeSeries, ptPubParameter> SkipCalcIfNoNewData;

///    
UProperty<bool, UMatrixSourceTimeSeries, ptPubState> IsNewData;

///        
UProperty<bool, UMatrixSourceTimeSeries, ptPubParameter> UseRelativePathFromConfig;

///         
UProperty<bool, UMatrixSourceTimeSeries, ptPubParameter> UseRelativePathFromWorkDir;

public: //    
///  double -   
UProperty<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> FullMatrix;

///  double -    
UProperty<MDMatrix<double>, UMatrixSourceTimeSeries, ptPubState | ptOutput> CurrentLine;
///   
UProperty<int, UMatrixSourceTimeSeries, ptPubState> CurrentLineIndex;


protected:

int current_line_index;
std::vector<double> source_timeseries;

public: // 
// --------------------------
//   
// --------------------------
UMatrixSourceTimeSeries(void);
virtual ~UMatrixSourceTimeSeries(void);
// --------------------------    

// --------------------------
//    
// --------------------------
public:
//         
virtual UMatrixSourceTimeSeries* New(void);
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
bool TransformData(MDMatrix<double> &matrix);

//:        
bool StandartizeData(MDMatrix<double> &matrix);

// /    ,      
void UpdateCurrentLine();

};


}






//---------------------------------------------------------------------------
#endif

