## UStatisticIntMatrix — статистика по int-матрицам (Rdk-BasicLib)

## RU

### Назначение

**Класс**: `UStatisticIntMatrix` — компонент сбора статистики по целочисленным матрицам на основе `UStatisticMatrix<int>`.  
Используется для анализа результатов экспериментов, построения логов и отчётов.

### Регистрация в UStorage

- Файл: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`.
- Метод: `CreateClassSamples(...)` → `UploadClass("UStatisticIntMatrix", ...)`.
- В `Bin/ClDesc`/`Configs`: `ClassName = "UStatisticIntMatrix"`.

### UML-диаграмма классов

```mermaid
classDiagram
    UStatistic <|-- UStatisticMatrix_int_
    UStatisticMatrix_int_ <|-- UStatisticIntMatrix

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
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }

    class UStatisticMatrix_int_ {
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
        +InputMatrixData : UProperty_vector_MDMatrix_int___
        +New() UStatisticMatrix*
        +AFSDefault() bool
        +AFSBuild() bool
        +AFSReset() bool
        +AFSCalculate() bool
    }

    class UStatisticIntMatrix {
        // specialization of UStatisticMatrix<int>
    }
```

### UML-диаграмма последовательности

```mermaid
sequenceDiagram
    participant S as UStorage
    participant Src as IntMatrixSource
    participant St as UStatisticIntMatrix

    S->>St: ADefault()
    S->>St: ABuild()

    loop each frame
        Src-->>St: InputMatrixData (int matrices)
        S->>St: ACalculate()
        St-->>S: update statistic logs / files
    end
```

### UML-диаграмма состояний

```mermaid
stateDiagram-v2
    [*] --> Uninitialized: New()
    Uninitialized --> Defaulted: ADefault()
    Defaulted --> Built: ABuild()
    Built --> Ready: Ready = true
    Ready --> Collecting: ACalculate()
    Collecting --> Ready
    Ready --> Resetting: AReset()
    Resetting --> Ready
```

### UML-диаграмма активности

```mermaid
flowchart TD
    start[Start ACalculate] --> checkSkip{Skip step? (NumSkipSteps / TimeInterval)}
    checkSkip -->|yes| endSkip[Return without logging]
    checkSkip -->|no| accumulate[Update averages / counters]
    accumulate --> writeMode{SaveMode / AverageMode}
    writeMode --> writeFiles[Append statistics to log files]
    writeFiles --> endNode[Конец]
```

### UML-диаграмма компонентов

```mermaid
graph TB
    src[IntMatrixSource] --> stats[UStatisticIntMatrix]
    stats --> logs[Statistic logs / files]
```

### Свойства

Через базовые классы `UStatistic` и `UStatisticMatrix<int>`:

- Путь и схема именования файлов (`SavePath`, `PrefixName`, `SubFolderAfterResetFlag`, `TimeToFileNameFlag`, `OrderIndexToFileNameFlag` и др.).
- Режимы сохранения (`SaveMode`, `AverageMode`, `AverageNumber`, `AverageInput`).
- Флаги записи временных меток, индексов и других атрибутов.
- Входные матрицы (`InputMatrixData`) и внутренние накопители средних значений и пр.

### Методы и жизненный цикл

- `ADefault`, `ABuild`, `AReset`, `ACalculate` — верхнеуровневые методы `UStatistic`.
- `AFSDefault`, `AFSBuild`, `AFSReset`, `AFSCalculate` — специализированные методы для работы с матрицами типа `int`.

### Примеры использования

Компонент активно используется в конфигурациях управления движением (`MotionControl_Test`, `MultiPositionControl_*`) для логирования выходных матриц:

```xml
<StatisticDoubleMatrix Class="UStatisticIntMatrix">
    <Parameters>
        <SavePath Type="s" PType="257" IoType="17">logs/</SavePath>
        <PrefixName Type="s" PType="257" IoType="17">int_stat</PrefixName>
        <SaveMode Type="i" PType="257" IoType="17">0</SaveMode>
    </Parameters>
</StatisticDoubleMatrix>
```

---

## UStatisticIntMatrix — integer matrix statistics (Rdk-BasicLib)

## EN

### Purpose

**Class**: `UStatisticIntMatrix` (based on `UStatisticMatrix<int>`) collects statistics over integer matrices and writes them to log files.  
It is registered in `CreateClassSamples` and used in analysis/reporting pipelines.

The diagrams in the RU section describe inheritance, lifecycle, activity flow and data paths.

```mermaid
classDiagram
    UStatistic <|-- UStatisticMatrix_int_
    UStatisticMatrix_int_ <|-- UStatisticIntMatrix

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
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }

    class UStatisticMatrix_int_ {
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
        +InputMatrixData : UProperty_vector_MDMatrix_int___
        +New() UStatisticMatrix*
        +AFSDefault() bool
        +AFSBuild() bool
        +AFSReset() bool
        +AFSCalculate() bool
    }

    class UStatisticIntMatrix {
        // specialization of UStatisticMatrix<int>
    }
```

```mermaid
sequenceDiagram
    participant S as UStorage
    participant Src as IntMatrixSource
    participant St as UStatisticIntMatrix

    S->>St: ADefault()
    S->>St: ABuild()

    loop each frame
        Src-->>St: InputMatrixData (int matrices)
        S->>St: ACalculate()
        St-->>S: update statistic logs / files
    end
```

```mermaid
stateDiagram-v2
    [*] --> Uninitialized: New()
    Uninitialized --> Defaulted: ADefault()
    Defaulted --> Built: ABuild()
    Built --> Ready: Ready = true
    Ready --> Collecting: ACalculate()
    Collecting --> Ready
    Ready --> Resetting: AReset()
    Resetting --> Ready
```

```mermaid
flowchart TD
    start[Start ACalculate] --> checkSkip{Skip step? (NumSkipSteps / TimeInterval)}
    checkSkip -->|yes| endSkip[Return without logging]
    checkSkip -->|no| accumulate[Update averages / counters]
    accumulate --> writeMode{SaveMode / AverageMode}
    writeMode --> writeFiles[Append statistics to log files]
    writeFiles --> endNode[End]
```

```mermaid
graph TB
    src[IntMatrixSource] --> stats[UStatisticIntMatrix]
    stats --> logs[Statistic logs / files]
```

## UStatisticIntMatrix — integer matrix statistics (Rdk-BasicLib)
