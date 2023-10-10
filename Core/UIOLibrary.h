#ifndef UIOLibrary_H
#define UIOLibrary_H

#include "../../../Rdk/Deploy/Include/rdk.h"
#include "UIO.h"
//#include "UFileIO.h"
#include "UIOConverter.h"
//#include "UIOTextConverter.h"

namespace RDK {

class RDK_LIB_TYPE UIOLibrary: public ULibrary
{
public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIOLibrary(void);
// --------------------------

// --------------------------
// Методы заполенения бибилиотеки
// --------------------------
// Заполняет массив ClassSamples готовыми экземплярами образцов и их именами.
// Не требуется предварительная очистка массива и уборка памяти.
virtual void CreateClassSamples(UStorage *storage);
// --------------------------
};

extern RDK_LIB_TYPE UIOLibrary IOLibrary;

}
#endif

