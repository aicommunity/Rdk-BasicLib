## UScalarSource — источник скаляров (Rdk-BasicLib)

## RU

### Назначение

**Класс**: `UScalarSource` — источник скалярных значений разных типов (double, float, int и др.).  
Компонент хранит значения в `UProperty` и предоставляет их другим компонентам как параметры/выходы.

### UML-диаграмма классов

```mermaid
classDiagram
    UNet <|-- UScalarSource

    class UScalarSource {
        +Double : UProperty_double_
        +LDouble : UProperty_long_double_
        +Float : UProperty_float_
        +Int : UProperty_int_
        +Long : UProperty_long_
        +ULong : UProperty_unsigned_long_
        +LongLong : UProperty_long_
        +ULongLong : UProperty_unsigned_long_
        +New() UScalarSource*
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }
```

### UML-диаграмма последовательности

```mermaid
sequenceDiagram
    participant Cfg as Config
    participant S as UStorage
    participant Src as UScalarSource

    Cfg->>S: create (Class="UScalarSource")
    S->>Src: New()
    S->>Src: ADefault()
    S->>Src: ABuild()

    loop each step
        S->>Src: ACalculate()
        Src-->>S: publish Double / Int / ... values
    end
```

### UML-диаграмма состояний

```mermaid
stateDiagram-v2
    [*] --> Uninitialized: New()
    Uninitialized --> Defaulted: ADefault()
    Defaulted --> Built: ABuild()
    Built --> Ready: Ready = true
    Ready --> Updating: ACalculate()
    Updating --> Ready
    Ready --> Resetting: AReset()
    Resetting --> Ready
```

### UML-диаграмма активности

```mermaid
flowchart TD
    start[Start ACalculate] --> checkParams{Parameters changed?}
    checkParams -->|no| endNoOp[Return without changes]
    checkParams -->|yes| updateProps[Update scalar properties]
    updateProps --> endNode[Конец]
```

### UML-диаграмма компонентов

```mermaid
graph TB
    src[UScalarSource] -->|"Double / Int / ... scalars"| model[Model / Controller]
```

### Свойства

Из `UScalarSource.h`:

- `Double`, `LDouble`, `Float`, `Int`, `Long`, `ULong`, `LongLong`, `ULongLong` — скалярные значения соответствующих типов, помеченные как `ptPubParameter | ptOutput`.

Каждое свойство может быть настроено в конфигурации и далее считываться другими компонентами через соединения.

### Методы

- Конструктор/деструктор, `New`.
- Жизненный цикл: `ADefault`, `ABuild`, `AReset`, `ACalculate`.
- Дополнительно реализованы `ASDefault`, `ASBuild`, `ASReset`, `ASCalculate` — служебные варианты жизненного цикла.

### Примеры использования в C++

```cpp
#include "UScalarSource.h"

using namespace RDK;

void UseScalarSource()
{
    UScalarSource* src = new UScalarSource();
    src->ADefault();
    src->ABuild();

    src->Double = 1.0;
    src->Int = 42;

    src->ACalculate(); // обновление состояний/выходов

    double value = src->Double;
    int index = src->Int;

    delete src;
}
```

### Примеры использования в конфигурациях

```xml
<ScalarSource Class="UScalarSource">
    <Parameters>
        <Double Type="d" PType="257" IoType="17">1.0</Double>
        <Int Type="i" PType="257" IoType="17">42</Int>
    </Parameters>
</ScalarSource>
```

---

## UScalarSource — scalar source (Rdk-BasicLib)

## EN

### Purpose

**Class**: `UScalarSource` provides scalar values of various numeric types (double, float, int, etc.) as parameters/outputs for other components.  
The mermaid diagrams in the RU section describe class structure, lifecycle and interactions. 

