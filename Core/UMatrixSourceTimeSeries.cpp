#ifndef UMatrixSourceTimeSeries_CPP
#define UMatrixSourceTimeSeries_CPP


#ifdef _WIN32
#include <windows.h>
#endif

#include "UMatrixSourceTimeSeries.h"

#include <vector>
#include <fstream>

namespace RDK {

// --------------------------
// ������������ � �����������
// --------------------------
UMatrixSourceTimeSeries::UMatrixSourceTimeSeries(void)
:
  FileName("FileName",this),
  ColCount("ColCount",this),
  IsStandartizeData("IsStandartizeData",this),
  IsCheckDateTime("IsCheckDateTime",this),
  SkipCalcIfNoNewData("SkipCalcIfNoNewData",this),
  IsNewData("IsNewData",this),
  UseRelativePathFromConfig("UseRelativePathFromConfig",this,&UMatrixSourceTimeSeries::SetUseRelativePathFromConfig),
  UseRelativePathFromWorkDir("UseRelativePathFromWorkDir",this,&UMatrixSourceTimeSeries::SetUseRelativePathFromWorkDir),
  FullMatrix("FullMatrix",this),
  CurrentLine("CurrentLine",this),
  CurrentLineIndex("CurrentLineIndex", this),
  current_line_index(0)
{
}

UMatrixSourceTimeSeries::~UMatrixSourceTimeSeries(void)
{

}
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
UMatrixSourceTimeSeries* UMatrixSourceTimeSeries::New(void)
{
 return new UMatrixSourceTimeSeries;
}
// --------------------------


// --------------------------
// ������ ���������� �����������
// --------------------------
/// ������������ ���� �� ��������� ����������� ������������ ����� ������������
bool UMatrixSourceTimeSeries::SetUseRelativePathFromConfig(const bool &value)
{
 UseRelativePathFromWorkDir=false;
 Ready=false;
 return true;
}

/// ������������ ���� �� ��������� ����������� ������������ ������� ����� ����������
bool UMatrixSourceTimeSeries::SetUseRelativePathFromWorkDir(const bool &value)
{
 UseRelativePathFromConfig=false;
 Ready=false;
 return true;
}
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
// �������������� �������� �� ��������� � ����� �������� �����
bool UMatrixSourceTimeSeries::ADefault(void)
{
 FileName="";
 IsCheckDateTime=true;
 SkipCalcIfNoNewData=true;
 UseRelativePathFromWorkDir=false;
 UseRelativePathFromConfig=true;
 ColCount = 1; //������, ��� ��� ��������� ����� ������, ���������-���������
 IsStandartizeData = true; //��� ��� ���������� ���� ������ ��� PCA, ������������� �� ���������
 current_line_index = 0;
 return true;
}

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool UMatrixSourceTimeSeries::ABuild(void)
{
 return true;
}

// ����� �������� �����.
bool UMatrixSourceTimeSeries::AReset(void)
{
 IsNewData=false;
 current_line_index = 0;
 source_timeseries.clear();
 return true;
}

// ��������� ������ ����� �������
bool UMatrixSourceTimeSeries::ACalculate(void)
{
 bool res = true;
 if(source_timeseries.size()==0)
 {
  std::string file_name=CalcActualSourceFilePath(FileName);
  res = ReadAndDecode(file_name);
 }


 if(!res)
 {
  //��� ������ ���� ���-�� ������, ���� �������� false?
  if(GetOwner())
   GetOwner()->ForceSkipComponentCalculation();

  return true;
 }

 if(current_line_index >= (*FullMatrix).GetRows())
 {
  current_line_index = 0;
 }

 UpdateCurrentLine();

 return true;
}

//�������� / ����������� ������� ������ �������, ������� ������������ ����������� � �������� ������
void UMatrixSourceTimeSeries::UpdateCurrentLine()
{
 MDMatrix<double> outline;

 if(current_line_index>=0)
 {
     if(current_line_index>=FullMatrix.v.GetRows())
     {
         current_line_index=0;
     }
     outline = FullMatrix.v.GetRow(current_line_index);
     current_line_index++;
 }
 *CurrentLineIndex = current_line_index;
 *CurrentLine=outline;
}


//������������� ������ � ������� ������� ColCount
bool UMatrixSourceTimeSeries::TransformData(MDMatrix<double> &matrix)
{
 int cols = ColCount.v;
 int rows = int(source_timeseries.size()) - cols - 1;
 matrix.Resize(rows, cols);

 for(int i=0; i<rows; i++)
 {
  for(int j=0; j<cols; j++)
  {
   matrix(i, j) = source_timeseries[i+j];
  }
 }

 return true;
}

//���������������: ������� ����������� ���� ���� � �������� �� ���
bool UMatrixSourceTimeSeries::StandartizeData(MDMatrix<double> &matrix)
{
 //Normalize data [] -> [0.0; 1.0]
 int N = matrix.GetRows();
 int M = matrix.GetCols();

 double max = -100000000000;
 double min = 10000000000;

 for(int i=0; i<N; i++)
 {
     for(int j=0; j<M; j++)
     {
         if(matrix(i, j)>max)
             max = matrix(i, j);

         if(matrix(i, j)<min)
             min = matrix(i, j);
     }
 }

 double delta = max-min;

 for(int i=0; i<N; i++)
 {
     for(int j=0; j<M; j++)
     {
         matrix(i, j) = (matrix(i, j)-min)/delta;
     }
 }

 //Standartize data (x-u)/s
 std::vector<double> mean;
 mean.resize(M, 0.0);
 std::vector<double> mean_sum;
 mean_sum.resize(M, 0.0);

 for(int j=0; j<M; j++)
 {
     mean_sum[j] = 0;
     for(int i=0; i<N; i++)
     {
         mean_sum[j] = mean_sum[j]+matrix(i, j);
     }
 }

 for(int j=0; j<M; j++)
 {
     mean[j] = mean_sum[j]/N;
 }

 /*std::cout<<"mean: ";
 for(int j=0; j<M; j++)
 {
     std::cout<<mean[j]<<" ";
 }
 std::cout<<"\n\n";*/

 std::vector<double> sko, sko_sum;
 sko.resize(M, 0.0);
 sko_sum.resize(M, 0.0);

 for(int j=0; j<M; j++)
 {
     sko_sum[j] = 0;
     for(int i=0; i<N; i++)
     {
         double diff = matrix(i, j) - mean[j];
         sko_sum[j] = sko_sum[j]+diff*diff;
     }
 }

 for(int j=0; j<M; j++)
 {
     sko[j] = sqrt(sko_sum[j]/N);
 }

 /*
 std::cout<<"SKO: ";
 for(int j=0; j<M; j++)
 {
     std::cout<<sko[j]<<" ";
 }
 std::cout<<"\n\n";*/

 for(int i=0; i<N; i++)
 {
     for(int j=0; j<M; j++)
     {
         matrix(i, j) = (matrix(i, j)-mean[j])/sko[j];
     }
 }

 return true;
}

/// ��������� ������, ������������� � ������ ������
bool UMatrixSourceTimeSeries::ReadAndDecode(const std::string &file_name)
{
 std::ifstream datafile;
 datafile.open(file_name, std::ifstream::in);

 if(datafile.good())
 {
  int line_cnt = -1;
  datafile>>line_cnt;

  source_timeseries.resize(line_cnt, 0.0);

  for(int i=0; i<line_cnt; i++)
  {
   if(datafile.good())
   {
    datafile>>source_timeseries[i];
   }
   else {
    return false;
   }
  }
  //return true;
 }

 //������ �������� ������
 //���� �� ������ ���������, ������ � �������
 if(ColCount.v>0)
 {
  //���� ������ ������, ��� ����� ����� �����, ���� ��������� ������
  if(int(source_timeseries.size())>ColCount.v)
  {
   MDMatrix<double> out;
   TransformData(out);
   if(IsStandartizeData.v==true)
   {
    StandartizeData(out);
   }
   *FullMatrix=out;
   //DEBUG
   std::ofstream ofs;
   ofs.open("norm_matrix.txt");
   for(int i=0; i<out.GetRows(); i++)
   {
    for(int j=0; j<out.GetCols(); j++)
    {
     ofs<<out(i, j)<<" ";
    }
    ofs<<"\n";
   }
   ofs.close();
  }
  else
   return true;
 }
 else
  return true;




 /*USerStorageXML xml;

 if(SkipCalcIfNoNewData.v == true)
 {
  if(!xml.LoadFromFile(file_name,"Matrix"))
  {
   if(GetOwner())
    GetOwner()->ForceSkipComponentCalculation();
   return true;
  }
 }
 else
 if(!xml.LoadFromFile(file_name,"Matrix"))
  return true;


 MDMatrix<double> out;
 xml>>out;
 *Matrix=out;*/

 return true;
}


/// ����������� �������� ���� �� ����� ������ �� �������� ������������� �����
std::string UMatrixSourceTimeSeries::CalcActualSourceFilePath(const std::string &file_name)
{
 std::string clean_file_name=trim_spaces(file_name);

 if(clean_file_name.empty())
  return clean_file_name;

 if(!UseRelativePathFromConfig && !UseRelativePathFromWorkDir)
  return clean_file_name;

 std::string file_path;

 if(clean_file_name.substr(0,2) == "./" || clean_file_name.substr(0,2) == ".\\")
  clean_file_name=clean_file_name.substr(2);

 if(UseRelativePathFromConfig)
 {
  if(GetEnvironment())
   file_path=GetEnvironment()->GetCurrentDataDir()+clean_file_name;
 }

 if(UseRelativePathFromWorkDir)
 {
  if(GetEnvironment())
   file_path=GetEnvironment()->GetSystemDir()+clean_file_name;
 }
 return file_path;
}

// --------------------------

}
#endif

