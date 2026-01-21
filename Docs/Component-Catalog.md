# Rdk-BasicLib — Component Catalog

Список компонентов из `CreateClassSamples` (`UBCLLibrary.cpp`, `UIOLibrary.cpp`) с кратким назначением и ключевыми входами/выходами.

## Models
- **UModel** — см. компонент [`UModel`](Components/UModel.md).

## Statistics
- **UStatisticIntMatrix** — см. [`UStatisticIntMatrix`](Components/UStatisticIntMatrix.md).
- **UStatisticDoubleMatrix** — см. [`UStatisticDoubleMatrix`](Components/UStatisticDoubleMatrix.md).

## IO
- **UFileIO** — см. [`UFileIO`](Components/UFileIO.md).
- **UIOTextConverter** — см. [`UIOTextConverter`](Components/UIOTextConverter.md).

## Generators
- **UNoiseGen** / **UNoiseGenDouble** / **UNoiseGenInt** — см. [`UNoiseGen*`](Components/UNoiseGen.md).

## Sources
- **UMatrixSource** — см. [`UMatrixSource`](Components/UMatrixSource.md).
- **UScalarSource** — см. [`UScalarSource`](Components/UScalarSource.md).
- **UMatrixSourceTimeSeries** — см. [`UMatrixSourceTimeSeries`](Components/UMatrixSourceTimeSeries.md).
- **UMatrixSourceDataFile**, **UUMatrixSourceFile**, **UMatrixSourceFileSep**, **UFileDataset** — см. [`File-based matrix sources`](Components/UMatrixSourceFileFamily.md).

## Usage priority
Часто встречаются в `Bin/ClDesc`/`Configs`: `UMatrixSource*`, `UStatistic*`, `UNoiseGen*`, `UModel`. Для подробностей см. `Architecture.md`, `API-Overview.md`, `Usage-Examples.md`.
