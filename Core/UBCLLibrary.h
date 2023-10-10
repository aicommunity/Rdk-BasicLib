/* ***********************************************************
@Copyright Alexander V. Bakhshiev, 2012.
E-mail:         alexab@ailab.ru
url:            http://ailab.ru
Version:        1.0.0

This file - part of the project: RDK

File License:        BSD License
See file license.txt for more information
*********************************************************** */

#ifndef UBCLLibraryH
#define UBCLLibraryH

#include "../../../Rdk/Deploy/Include/rdk.h"

#include "UModel.h"
#include "UStatistic.h"

#include "UIO.h"
//#include "UFileIO.h"
#include "UIOConverter.h"
//#include "UIOTextConverter.h"

#include "UNoise.h"
#include "UNoiseGen.h"

#include "UMatrixSource.h"
#include "UScalarSource.h"
#include "UMatrixSourceTimeSeries.h"
#include "UMatrixSourceDataFile.h"
#ifdef WIN32
#include "UMatrixSourceFile.h"
#include "UMatrixSourceFileSep.h"
#include "UFileDataset.h"
#endif

namespace RDK {

class RDK_LIB_TYPE UBCLLibrary: public ULibrary
{
public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UBCLLibrary(void);
// --------------------------

// --------------------------
// Методы заполенения бибилиотеки
// --------------------------
// Заполняет массив ClassSamples готовыми экземплярами образцов и их именами.
// Не требуется предварительная очистка массива и уборка памяти.
virtual void CreateClassSamples(UStorage *storage);
// --------------------------
};          

extern RDK_LIB_TYPE UBCLLibrary BCLLibrary;

}


#endif
