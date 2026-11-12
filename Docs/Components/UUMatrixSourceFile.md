# UUMatrixSourceFile

**Каталог:** [Component-Catalog.md](../Component-Catalog.md).

## RU

### Назначение

**Класс**: `UUMatrixSourceFile` — файловый источник матрицы (зарегистрированное имя; Windows-специфичная реализация использует `FILETIME`).

**Регистрация**: `UBCLLibrary.cpp` → `UploadClass("UUMatrixSourceFile", ...)` (часто под `#ifdef WIN32`).

См. также: [UMatrixSourceFileFamily](UMatrixSourceFileFamily.md#uumatrixsourcefile), [UMatrixSourceDataFile](UMatrixSourceDataFile.md).

### Свойства и методы

Ключевые свойства: `FileName`, `IsCheckDateTime`, `SkipCalcIfNoNewData`, `IsNewData`, `Matrix`. Полные таблицы — в заголовке семейства / `Core/` и [API-Overview.md](../API-Overview.md).

---

## EN

### Purpose

**Class**: `UUMatrixSourceFile` — file-based matrix source (registered name; Windows-specific implementation uses `FILETIME`).

**Registration**: `UploadClass("UUMatrixSourceFile", ...)` in Rdk-BasicLib (often under `#ifdef WIN32`).

See also: [UMatrixSourceFileFamily](UMatrixSourceFileFamily.md#uumatrixsourcefile), [UMatrixSourceDataFile](UMatrixSourceDataFile.md).

### Properties and methods

Key properties: `FileName`, `IsCheckDateTime`, `SkipCalcIfNoNewData`, `IsNewData`, `Matrix`. Full tables in family overview / `Core/` and [API-Overview.md](../API-Overview.md).
