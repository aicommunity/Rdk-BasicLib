# Rdk-BasicLib — Component Catalog

## RU

Список всех **15** зарегистрированных компонентов (`UploadClass` в `UBCLLibrary.cpp`, `UIOLibrary.cpp`) с кратким назначением и ссылками на per-class страницы.

| # | ClassName | Doc | Группа |
|---|-----------|-----|--------|
| 1 | `UModel` | [`UModel.md`](Components/UModel.md) | Models |
| 2 | `UStatisticIntMatrix` | [`UStatisticIntMatrix.md`](Components/UStatisticIntMatrix.md) | Statistics |
| 3 | `UStatisticDoubleMatrix` | [`UStatisticDoubleMatrix.md`](Components/UStatisticDoubleMatrix.md) | Statistics |
| 4 | `UFileIO` | [`UFileIO.md`](Components/UFileIO.md) | IO |
| 5 | `UIOTextConverter` | [`UIOTextConverter.md`](Components/UIOTextConverter.md) | IO |
| 6 | `UNoiseGen` | [`UNoiseGen.md`](Components/UNoiseGen.md) | Generators |
| 7 | `UNoiseGenDouble` | [`UNoiseGenDouble.md`](Components/UNoiseGenDouble.md) | Generators |
| 8 | `UNoiseGenInt` | [`UNoiseGenInt.md`](Components/UNoiseGenInt.md) | Generators |
| 9 | `UMatrixSource` | [`UMatrixSource.md`](Components/UMatrixSource.md) | Sources |
| 10 | `UScalarSource` | [`UScalarSource.md`](Components/UScalarSource.md) | Sources |
| 11 | `UMatrixSourceTimeSeries` | [`UMatrixSourceTimeSeries.md`](Components/UMatrixSourceTimeSeries.md) | Sources |
| 12 | `UMatrixSourceDataFile` | [`UMatrixSourceDataFile.md`](Components/UMatrixSourceDataFile.md) | File sources |
| 13 | `UUMatrixSourceFile` | [`UUMatrixSourceFile.md`](Components/UUMatrixSourceFile.md) | File sources |
| 14 | `UMatrixSourceFileSep` | [`UMatrixSourceFileSep.md`](Components/UMatrixSourceFileSep.md) | File sources |
| 15 | `UFileDataset` | [`UFileDataset.md`](Components/UFileDataset.md) | File sources |

### Групповые обзоры

- Генераторы шума: [`UNoiseGen.md`](Components/UNoiseGen.md) (семейство `UNoiseGen*` / `UNoise`).
- Файловые источники: [`UMatrixSourceFileFamily.md`](Components/UMatrixSourceFileFamily.md).

### Usage priority

Часто встречаются в `Bin/ClDesc`/`Configs`: `UMatrixSource*`, `UStatistic*`, `UNoiseGen*`, `UModel`. Для подробностей см. `Architecture.md`, `API-Overview.md`, `Usage-Examples.md`.

---

## EN

List of all **15** registered components (`UploadClass` in `UBCLLibrary.cpp`, `UIOLibrary.cpp`) with brief purpose and per-class doc links.

| # | ClassName | Doc | Group |
|---|-----------|-----|-------|
| 1 | `UModel` | [`UModel.md`](Components/UModel.md) | Models |
| 2 | `UStatisticIntMatrix` | [`UStatisticIntMatrix.md`](Components/UStatisticIntMatrix.md) | Statistics |
| 3 | `UStatisticDoubleMatrix` | [`UStatisticDoubleMatrix.md`](Components/UStatisticDoubleMatrix.md) | Statistics |
| 4 | `UFileIO` | [`UFileIO.md`](Components/UFileIO.md) | IO |
| 5 | `UIOTextConverter` | [`UIOTextConverter.md`](Components/UIOTextConverter.md) | IO |
| 6 | `UNoiseGen` | [`UNoiseGen.md`](Components/UNoiseGen.md) | Generators |
| 7 | `UNoiseGenDouble` | [`UNoiseGenDouble.md`](Components/UNoiseGenDouble.md) | Generators |
| 8 | `UNoiseGenInt` | [`UNoiseGenInt.md`](Components/UNoiseGenInt.md) | Generators |
| 9 | `UMatrixSource` | [`UMatrixSource.md`](Components/UMatrixSource.md) | Sources |
| 10 | `UScalarSource` | [`UScalarSource.md`](Components/UScalarSource.md) | Sources |
| 11 | `UMatrixSourceTimeSeries` | [`UMatrixSourceTimeSeries.md`](Components/UMatrixSourceTimeSeries.md) | Sources |
| 12 | `UMatrixSourceDataFile` | [`UMatrixSourceDataFile.md`](Components/UMatrixSourceDataFile.md) | File sources |
| 13 | `UUMatrixSourceFile` | [`UUMatrixSourceFile.md`](Components/UUMatrixSourceFile.md) | File sources |
| 14 | `UMatrixSourceFileSep` | [`UMatrixSourceFileSep.md`](Components/UMatrixSourceFileSep.md) | File sources |
| 15 | `UFileDataset` | [`UFileDataset.md`](Components/UFileDataset.md) | File sources |

### Group overviews

- Noise generators: [`UNoiseGen.md`](Components/UNoiseGen.md) (`UNoiseGen*` / `UNoise` family).
- File-based sources: [`UMatrixSourceFileFamily.md`](Components/UMatrixSourceFileFamily.md).

### Usage priority

Commonly found in `Bin/ClDesc`/`Configs`: `UMatrixSource*`, `UStatistic*`, `UNoiseGen*`, `UModel`. For details see `Architecture.md`, `API-Overview.md`, `Usage-Examples.md`.
