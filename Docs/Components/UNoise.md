## UNoise — базовый шаблонный класс генераторов шума (Rdk-BasicLib)

## RU

### Назначение

**Класс-шаблон**: `UNoise<T>` — базовый шаблонный класс для генераторов аддитивного шума над матрицами типа `T`.  
**Базовый класс**: `UNet`.  
Не регистрируется напрямую в `UStorage`, используется как родительский класс для специализированных генераторов (например, `UNoiseGen<double>`, `UNoiseGen<int>`).

### UML-диаграмма классов

```mermaid
classDiagram
    UNet <|-- UNoise_T_
    UNoise_T_ <|-- UNoiseGen_T_

    class UNet {
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }

    class UNoise_T_ {
        +InputParams : UProperty_MDMatrix_T__ (input)
        +OutputParams : UProperty_MDMatrix_T__ (output)
        +OneErrorForAll : UProperty_bool_
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
        +ANoiseDefault() bool
        +ANoiseBuild() bool
        +ANoiseReset() bool
        +ANoiseCalculate() bool
    }
```

### UML-диаграмма последовательности

```mermaid
sequenceDiagram
    participant Child as UNoiseGen_T_ (child)
    participant Base as UNoise_T_
    participant Net as UNet

    Child->>Base: ANoiseDefault()
    Base->>Net: ADefault()
    Child->>Base: ANoiseBuild()
    Base->>Net: ABuild()
    
    loop each step
        Child->>Base: ANoiseCalculate()
        Base->>Net: ACalculate()
        Base->>Base: check InputParams.IsConnected()
    end
```

### UML-диаграмма состояний

```mermaid
stateDiagram-v2
    [*] --> Uninitialized: New()
    Uninitialized --> Defaulted: ANoiseDefault()
    Defaulted --> Built: ANoiseBuild()
    Built --> Ready: Ready = true
    Ready --> Generating: ANoiseCalculate()
    Generating --> Ready
    Ready --> Resetting: ANoiseReset()
    Resetting --> Ready
```

### UML-диаграмма активности

```mermaid
flowchart TD
    start[Start ACalculate] --> checkConnected{InputParams.IsConnected()?}
    checkConnected -->|no| endNoOp[Return true without changes]
    checkConnected -->|yes| callNoise[Call ANoiseCalculate()]
    callNoise --> endNode[Конец]
```

### UML-диаграмма компонентов

```mermaid
graph TB
    subgraph basicLib["Rdk-BasicLib"]
        noise[UNoise base template]
        noiseGen[UNoiseGen]
    end

    noise -->|inherits| noiseGen
```

### Свойства

Из `UNoise.h`:

- **`InputParams`** (`UProperty<MDMatrix<T>, ..., ptPubInput>`) — входная матрица сигнала.
- **`OutputParams`** (`UProperty<MDMatrix<T>, ..., ptPubOutput>`) — выходная матрица с добавленным шумом.
- **`OneErrorForAll`** (`bool`, `ptPubParameter`) — флаг использования одного значения шума для всех элементов матрицы (по умолчанию `false`).

### Методы

Жизненный цикл (два уровня):

- Верхний уровень (наследуется от `UNet`):
  - `ADefault`, `ABuild`, `AReset`, `ACalculate`.
- Специализированный уровень Noise:
  - `ANoiseDefault` — устанавливает `OneErrorForAll = false`.
  - `ANoiseBuild`, `ANoiseReset` — подготовка и сброс (базовая реализация возвращает `true`).
  - `ANoiseCalculate` — абстрактный метод, должен быть переопределён в производных классах (базовая реализация возвращает `true`).

Метод `ACalculate` проверяет подключение `InputParams` и вызывает `ANoiseCalculate`, если вход подключён.

### Использование

`UNoise<T>` не используется напрямую в конфигурациях, но служит базой для:
- `UNoiseGen<double>` → `UNoiseGenDouble`.
- `UNoiseGen<int>` → `UNoiseGenInt`.

---

## UNoise — base noise generator template (Rdk-BasicLib)

## EN

### Purpose

**Template class**: `UNoise<T>` is a base template class for additive noise generators over matrices of type `T`, extending `UNet`.  
It is not registered directly in `UStorage` but serves as a parent for specialized generators like `UNoiseGen<double>` and `UNoiseGen<int>`.

### Notes

- Provides input/output matrix properties (`InputParams`, `OutputParams`) and a flag `OneErrorForAll` for noise generation mode.
- Implements lifecycle methods at both `UNet` level and specialized `ANoise*` level.
- Derived classes must implement `ANoiseCalculate` to add noise to input matrices.
- Mermaid diagrams in the RU section show inheritance, lifecycle and component relationships.
