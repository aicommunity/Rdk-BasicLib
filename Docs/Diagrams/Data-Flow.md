# Поток данных Rdk-BasicLib

## RU

### Общий поток данных

```mermaid
flowchart LR
    Source["Источник_данных (UMatrixSource)"]
    Process["Обработка (UStatistic)"]
    Output[Выходные данные]
    
    Source --> Process
    Process --> Output
```

### Пример: Статистическая обработка данных

```mermaid
sequenceDiagram
    participant Source as UMatrixSourceFile
    participant Statistic as UStatistic
    participant Output as Выход
    
    Source->>Source: LoadData()
    Source->>Statistic: InputData
    Statistic->>Statistic: Calculate()
    Statistic->>Statistic: ComputeMean()
    Statistic->>Statistic: ComputeVariance()
    Statistic->>Output: Mean, Variance
```

---

## EN

### General Data Flow

```mermaid
flowchart LR
    Source_EN["Data_source (UMatrixSource)"]
    Process_EN["Processing (UStatistic)"]
    Output_EN[Output_data]
    
    Source_EN --> Process_EN
    Process_EN --> Output_EN
```

The flowchart shows a simple pipeline: data source produces a matrix, processing component computes statistics, results are sent to output consumers via properties.

### Example: Statistical Data Processing

The sequence diagram in the RU section shows a typical flow: load data → push input → calculate statistics → publish mean/variance.
