## UIOConverter — базовый класс конвертеров IO (Rdk-BasicLib)

## RU

### Назначение

**Класс**: `UIOConverter` — базовый абстрактный класс для компонентов преобразования данных в IO-контексте.  
**Префикс**: `IO` — **I**nput/**O**utput (ввод-вывод).  
**Базовый класс**: `UNet`.  
Не регистрируется напрямую в `UStorage`, используется как родительский класс для специализированных конвертеров (например, `UIOTextConverter`).

### UML-диаграмма классов

```mermaid
classDiagram
    UNet <|-- UIOConverter
    UIOConverter <|-- UIOTextConverter

    class UNet {
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }

    class UIOConverter {
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
        +AIODefault() bool
        +AIOBuild() bool
        +AIOReset() bool
        +AIOCalculate() bool
    }
```

### UML-диаграмма последовательности

```mermaid
sequenceDiagram
    participant Child as UIOTextConverter (child)
    participant Base as UIOConverter
    participant Net as UNet

    Child->>Base: AIODefault()
    Base->>Net: ADefault()
    Child->>Base: AIOBuild()
    Base->>Net: ABuild()
    
    loop each step
        Child->>Base: AIOCalculate()
        Base->>Net: ACalculate()
    end
```

### UML-диаграмма состояний

```mermaid
stateDiagram-v2
    [*] --> Uninitialized: New()
    Uninitialized --> Defaulted: AIODefault()
    Defaulted --> Built: AIOBuild()
    Built --> Ready: Ready = true
    Ready --> Converting: AIOCalculate()
    Converting --> Ready
    Ready --> Resetting: AIOReset()
    Resetting --> Ready
```

### UML-диаграмма активности

```mermaid
flowchart TD
    start[Start AIOCalculate] --> convert[Convert data format]
    convert --> endNode[Конец]
```

### UML-диаграмма компонентов

```mermaid
graph TB
    subgraph basicLib["Rdk-BasicLib"]
        conv[UIOConverter base class]
        textConv[UIOTextConverter]
    end

    conv -->|inherits| textConv
```

### Методы

Жизненный цикл (два уровня):

- Верхний уровень (наследуется от `UNet`):
  - `ADefault`, `ABuild`, `AReset`, `ACalculate`.
- Специализированный уровень IO:
  - `AIODefault`, `AIOBuild`, `AIOReset`, `AIOCalculate`.

Производные классы переопределяют методы IO-уровня для реализации конкретных преобразований данных.

### Использование

`UIOConverter` не используется напрямую в конфигурациях, но служит базой для:
- `UIOTextConverter` — преобразование между числовым и текстовым форматами.
- Других специализированных конвертеров данных.

---

## UIOConverter — base IO converter class (Rdk-BasicLib)

## EN

### Purpose

**Class**: `UIOConverter` is an abstract base class for data conversion components in IO context, extending `UNet`.  
It is not registered directly in `UStorage` but serves as a parent for specialized converters like `UIOTextConverter`.

### Notes

- Provides both standard `UNet` lifecycle methods and specialized `AIO*` methods for conversion logic.
- Derived classes implement specific conversion algorithms in their `AIOCalculate` methods.
- Mermaid diagrams in the RU section show inheritance, lifecycle and component relationships.
