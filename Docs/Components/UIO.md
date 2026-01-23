## UIO — базовый класс ввода/вывода (Rdk-BasicLib)

## RU

### Назначение

**Класс**: `UIO` — базовый абстрактный класс для компонентов ввода/вывода данных.  
**Базовый класс**: `UNet`.  
Не регистрируется напрямую в `UStorage`, используется как родительский класс для специализированных IO-компонентов (например, `UFileIO`).

### UML-диаграмма классов

```mermaid
classDiagram
    UNet <|-- UIO
    UIO <|-- UFileIO

    class UNet {
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }

    class UIO {
        +Direction : UProperty_int_ (parameter)
        -BinaryStorage : USerStorageBinary
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
    participant Child as UFileIO (child)
    participant Base as UIO
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
    Ready --> Calculating: AIOCalculate()
    Calculating --> Ready
    Ready --> Resetting: AIOReset()
    Resetting --> Ready
```

### UML-диаграмма активности

```mermaid
flowchart TD
    start[Start AIOCalculate] --> checkDirection{Direction?}
    checkDirection -->|0 input| readOp[Read operation]
    checkDirection -->|1 output| writeOp[Write operation]
    readOp --> endNode[End]
    writeOp --> endNode
```

### UML-диаграмма компонентов

```mermaid
graph TB
    subgraph basicLib["Rdk-BasicLib"]
        io[UIO base class]
        fileIO[UFileIO]
    end

    io -->|inherits| fileIO
```

### Свойства

Из `UIO.h`:

- **`Direction`** (`int`, `ptPubParameter`) — направление работы:
  - 0 — ввод информации.
  - 1 — вывод информации.

Внутренние:

- **`BinaryStorage`** (`USerStorageBinary`) — хранилище двоичных данных для ввода/вывода.

### Методы

Жизненный цикл (два уровня):

- Верхний уровень (наследуется от `UNet`):
  - `ADefault`, `ABuild`, `AReset`, `ACalculate`.
- Специализированный уровень IO:
  - `AIODefault`, `AIOBuild`, `AIOReset`, `AIOCalculate`.

Методы IO-уровня обычно вызываются из производных классов и делегируют работу верхнему уровню или реализуют специфичную для IO логику.

### Использование

`UIO` не используется напрямую в конфигурациях, но служит базой для:
- `UFileIO` — файловый ввод/вывод.
- Других специализированных IO-компонентов.

---

## UIO — base IO class (Rdk-BasicLib)

## EN

### Purpose

**Class**: `UIO` is an abstract base class for input/output components, extending `UNet`.  
It is not registered directly in `UStorage` but serves as a parent for specialized IO classes like `UFileIO`.

### Notes

- `Direction` property controls whether the component performs input (0) or output (1) operations.
- The class provides both standard `UNet` lifecycle methods and specialized `AIO*` methods for IO-specific logic.
- Mermaid diagrams in the RU section show inheritance, lifecycle and component relationships.
