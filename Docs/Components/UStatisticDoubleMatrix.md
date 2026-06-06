## UStatisticDoubleMatrix — статистика по double-матрицам (Rdk-BasicLib)

## RU

### Назначение

**Класс**: `UStatisticDoubleMatrix` — специализированный вариант `UStatisticMatrix<double>` для матриц с плавающей точкой.  
Собирает и сохраняет статистику по double‑матрицам (среднее, дисперсия, min/max и т.п.).

### Регистрация в UStorage

- Файл: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`.
- Метод: `CreateClassSamples(...)` → `UploadClass("UStatisticDoubleMatrix", ...)`.
- В `Bin/ClDesc`/`Configs`: `ClassName = "UStatisticDoubleMatrix"`.

### UML-диаграмма классов

```mermaid
classDiagram
    UStatistic <|-- UStatisticMatrix_double_
    UStatisticMatrix_double_ <|-- UStatisticDoubleMatrix

    class UStatistic {
        +SavePath : UProperty_string_
        +PrefixName : UProperty_string_
        +SubFolderAfterResetFlag : UProperty_bool_
        +ForceCreateSavePath : UProperty_bool_
        +TimeToFileNameFlag : UProperty_bool_
        +OrderIndexToFileNameFlag : UProperty_bool_
        +NumSkipSteps : UProperty_int_
        +ManualModeEnabled : UProperty_bool_
        +TimeInterval : UProperty_double_
    }

    class UStatisticMatrix_double_ {
        +SaveMode : UProperty_int_
        +AverageMode : UProperty_int_
        +AverageNumber : UProperty_int_
        +AverageInput : UProperty_pair_string_string__
        +WriteTimeStampFlag : UProperty_bool_
        +WriteTimeFromResetFlag : UProperty_bool_
        +WriteSourceTimeStampFlag : UProperty_bool_
        +WriteModelTimeStampFlag : UProperty_bool_
        +WriteIndexFlag : UProperty_bool_
        +ExcludeModelFileName : UProperty_bool_
        +CurrentAverageNumber : UProperty_int_
        +InputMatrixData : UProperty_vector_MDMatrix_double___
    }
```

### UML-диаграмма последовательности

```mermaid
sequenceDiagram
    participant S as UStorage
    participant Src as DoubleMatrixSource
    participant St as UStatisticDoubleMatrix

    S->>St: ADefault()
    S->>St: ABuild()

    loop each step
        Src-->>St: InputMatrixData (double matrices)
        S->>St: ACalculate()
        St-->>S: update statistics / log files
    end
```

### UML-диаграмма компонентов

```mermaid
graph TB
    src[DoubleMatrixSource] --> stats[UStatisticDoubleMatrix]
    stats --> logs[Double statistic logs / files]
```

### Входы/выходы

- Вход: double‑матрицы в `InputMatrixData`.
- Выход: статистика, сохраняемая во внутренние структуры и, при необходимости, в файлы.

### Методы и жизненный цикл

Как и в `UStatisticIntMatrix`, логика реализована через базовые методы `UStatistic` и `UStatisticMatrix<double>`:

- `ADefault`, `ABuild`, `AReset`, `ACalculate` — верхний уровень.
- `AFSDefault`, `AFSBuild`, `AFSReset`, `AFSCalculate` — реализация статистики над double‑матрицами.

### Примеры использования в конфигурациях

Компонент используется во множестве конфигов из `Bin/Configs/a.demcheva/*`, например:

```xml
<StatisticDoubleMatrix Class="UStatisticDoubleMatrix">
    <Parameters>
        <SavePath Type="s" PType="257" IoType="17">logs/</SavePath>
        <PrefixName Type="s" PType="257" IoType="17">double_stat</PrefixName>
        <SaveMode Type="i" PType="257" IoType="17">0</SaveMode>
        <AverageMode Type="i" PType="257" IoType="17">0</AverageMode>
    </Parameters>
</StatisticDoubleMatrix>
```

---

## UStatisticDoubleMatrix — double matrix statistics (Rdk-BasicLib)

## EN

### Purpose

**Class**: `UStatisticDoubleMatrix` is a `UStatisticMatrix<double>` specialization for double matrices, computing and logging statistics.  
It is heavily used in motion control and position control configs for numeric diagnostics.

Mermaid diagrams in the RU section show its inheritance, data flow and interaction within `Rdk-BasicLib`.

```mermaid
classDiagram
    UStatistic <|-- UStatisticMatrix_double_
    UStatisticMatrix_double_ <|-- UStatisticDoubleMatrix

    class UStatistic {
        +SavePath : UProperty_string_
        +PrefixName : UProperty_string_
        +SubFolderAfterResetFlag : UProperty_bool_
        +ForceCreateSavePath : UProperty_bool_
        +TimeToFileNameFlag : UProperty_bool_
        +OrderIndexToFileNameFlag : UProperty_bool_
        +NumSkipSteps : UProperty_int_
        +ManualModeEnabled : UProperty_bool_
        +TimeInterval : UProperty_double_
    }

    class UStatisticMatrix_double_ {
        +SaveMode : UProperty_int_
        +AverageMode : UProperty_int_
        +AverageNumber : UProperty_int_
        +AverageInput : UProperty_pair_string_string__
        +WriteTimeStampFlag : UProperty_bool_
        +WriteTimeFromResetFlag : UProperty_bool_
        +WriteSourceTimeStampFlag : UProperty_bool_
        +WriteModelTimeStampFlag : UProperty_bool_
        +WriteIndexFlag : UProperty_bool_
        +ExcludeModelFileName : UProperty_bool_
        +CurrentAverageNumber : UProperty_int_
        +InputMatrixData : UProperty_vector_MDMatrix_double___
    }
```

```mermaid
sequenceDiagram
    participant S as UStorage
    participant Src as DoubleMatrixSource
    participant St as UStatisticDoubleMatrix

    S->>St: ADefault()
    S->>St: ABuild()

    loop each step
        Src-->>St: InputMatrixData (double matrices)
        S->>St: ACalculate()
        St-->>S: update statistics / log files
    end
```

```mermaid
graph TB
    src[DoubleMatrixSource] --> stats[UStatisticDoubleMatrix]
    stats --> logs[Double statistic logs / files]
```

## UStatisticDoubleMatrix — double matrix statistics (Rdk-BasicLib)
