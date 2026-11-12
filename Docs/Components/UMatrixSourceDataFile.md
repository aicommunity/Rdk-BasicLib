# UMatrixSourceDataFile

**Каталог:** [Component-Catalog.md](../Component-Catalog.md).

## RU

### Назначение

**Класс**: `UMatrixSourceDataFile` — источник матрицы из файла данных (`FullMatrix`, опциональная проверка даты/времени файла).

**Регистрация**: `UBCLLibrary.cpp` → `UploadClass("UMatrixSourceDataFile", ...)`.

См. также: [UMatrixSourceFileFamily](UMatrixSourceFileFamily.md#umatrixsourcedatafile), [UMatrixSource](UMatrixSource.md).

### Свойства и методы

Ключевые свойства: `FileName`, `IsCheckDateTime`, `SkipCalcIfNoNewData`, `ReloadFile`, `IsNewData`, `FullMatrix`, `RowCount`, `ColCount`. Полные таблицы — в `Core/UMatrixSourceDataFile.h` и [API-Overview.md](../API-Overview.md).

---

### Ключевые свойства / Favorites

| Свойство | Роль |
|----------|------|
| `FileName` / `ReloadFile` | Источник данных |
| `UseRelativePathFromConfig` / `SkipCalcIfNoNewData` | Путь и обновление |
| `FullMatrix` / `RowCount` / `ColCount` | Результат и размеры |

ClDesc: `Bin/ClDesc/BasicLib/ru-RU/UMatrixSourceDataFile.xml`.

## EN

### Purpose

**Class**: `UMatrixSourceDataFile` — matrix source from a data file (`FullMatrix`, optional file datetime check).

**Registration**: `UploadClass("UMatrixSourceDataFile", ...)` in Rdk-BasicLib.

See also: [UMatrixSourceFileFamily](UMatrixSourceFileFamily.md#umatrixsourcedatafile), [UMatrixSource](UMatrixSource.md).

### Properties and methods

Key properties: `FileName`, `IsCheckDateTime`, `SkipCalcIfNoNewData`, `ReloadFile`, `IsNewData`, `FullMatrix`, `RowCount`, `ColCount`. Full tables in `Core/UMatrixSourceDataFile.h` and [API-Overview.md](../API-Overview.md).
