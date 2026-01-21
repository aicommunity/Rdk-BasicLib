## UStatisticIntMatrix — статистика по int-матрицам (Rdk-BasicLib)

**Класс**: `UStatisticIntMatrix` — собирает статистику по целочисленным матрицам.  
**Storage-компоненты**: регистрируется через `UploadClass("UStatisticIntMatrix", ...)` и используется в пайплайнах анализа.

### Регистрация в UStorage
- Файл: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`.
- Метод: `CreateClassSamples(...)` → `UploadClass("UStatisticIntMatrix", ...)`.
- В `Bin/ClDesc`/`Configs`: `ClassName = "UStatisticIntMatrix"`.

### Иерархия (Class)

```mermaid
classDiagram
    UComponent <|-- UStatisticBase
    UStatisticBase <|-- UStatisticIntMatrix
    class UStatisticIntMatrix {
        +input : UProperty(intMatrix)
        +stats : UProperty
    }
```

### Жизненный цикл
- **ADefault** — сброс счётчиков и начальных значений.
- **ABuild** — проверка размерности входной матрицы, выделение памяти для накопителей.
- **ACalculate** — при каждом вызове обновляет статистику (среднее, минимум, максимум и т.п.).

### Входы/выходы
- Вход: `UProperty` с int-матрицей.
- Выход: `UProperty` с объектом статистики (значения, гистограммы и др.).

```mermaid
flowchart LR
    src[IntMatrixSource] --> stats[UStatisticIntMatrix]
    stats --> report[StatisticConsumer]
```

Пояснение: блок-схема показывает поток данных/сигналов (входы → компонент → выходы).

### Типовой сценарий (Sequence)

```mermaid
sequenceDiagram
    participant S as UStorage
    participant Src as IntSource
    participant St as UStatisticIntMatrix
    S->>St: ADefault + ABuild
    loop each frame
        Src-->>St: matrix input
        S->>St: ACalculate()
        St-->>S: update statistics
    end
```

Пояснение: диаграмма последовательности показывает типовой сценарий взаимодействия и порядок вызовов.

---

## UStatisticIntMatrix — integer matrix statistics (Rdk-BasicLib)

**Class**: `UStatisticIntMatrix` — collects statistics over integer matrices.  
**Usage**: registered in `CreateClassSamples`, used in analysis/reporting pipelines.

