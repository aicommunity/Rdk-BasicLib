#ifndef UIOLibrary_CPP
#define UIOLibrary_CPP

#include "UIOLibrary.h"

//#include "UIO.cpp"
//#include "UFileIO.cpp"
//#include "UIOConverter.cpp"
//#include "UIOTextConverter.cpp"


namespace RDK {

UIOLibrary IOLibrary;



// --------------------------
// Конструкторы и деструкторы
// --------------------------
UIOLibrary::UIOLibrary(void)
 : ULibrary("IOLibrary","1.0", GetGlobalVersion())
{
}
// --------------------------

// --------------------------
// Методы заполенения бибилиотеки
// --------------------------
// Заполняет массив ClassSamples готовыми экземплярами образцов и их именами.
// Не требуется предварительная очистка массива и уборка памяти.
void UIOLibrary::CreateClassSamples(UStorage *storage)
{
    /*
 UContainer *cont;
 cont=new UFileIO;
 cont->SetName("FileIO");
 cont->Default();
 UploadClass("UFileIO",cont);

 cont=new UIOTextConverter;
 cont->SetName("IOTextConverter");
 cont->Default();
 UploadClass("UIOTextConverter",cont);*/
}
// --------------------------

}

#endif
