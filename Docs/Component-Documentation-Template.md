# [ComponentName] — [RU название]

**Каталог компонентов:** [Component-Catalog.md](Component-Catalog.md).

## RU

### Назначение

**Класс**: `[ComponentName]` — [краткое описание назначения].
**Регистрация**: `UBCLLibrary.cpp` / `UIOLibrary.cpp` → `UploadClass("[ComponentName]", ...)`.
**Storage-инстансы**: `ClassName = "[ComponentName]"` в `Bin/Configs/*/Model_*.xml` / `Bin/ClDesc/`.

[Подробное описание компонента, назначения и области применения.]

**Использование:** `Bin/Configs/...`, `Bin/ClDesc/...` (при наличии).

### UML-диаграмма классов

```mermaid
classDiagram
    [BaseClass] <|-- [ComponentName]
    class [ComponentName] {
        +Property1 : Type
        +New() [ComponentName]*
        +ADefault() bool
        +ABuild() bool
        +AReset() bool
        +ACalculate() bool
    }
```

**Иерархия наследования:** [описание.]

**Ключевые свойства:** [список свойств.]

### UML-диаграмма последовательности

[По необходимости.]

### Свойства

| Свойство | Тип | Описание |
|----------|-----|----------|
| `Property1` | `Type` | [описание] |

### Методы

- **`ADefault()`** — [описание]
- **`ABuild()`** — [описание]
- **`AReset()`** — [описание]
- **`ACalculate()`** — [описание]

### Примеры

#### C++

```cpp
// пример создания и использования
```

#### XML

```xml
<Component ClassName="[ComponentName]" Name="...">
  <!-- свойства -->
</Component>
```

### См. также

- [Component-Catalog.md](Component-Catalog.md)
- [API-Overview.md](API-Overview.md)
- [Usage-Examples.md](Usage-Examples.md)

---

## EN

### Purpose

**Class**: `[ComponentName]` — [short purpose].
**Registration**: `UBCLLibrary.cpp` / `UIOLibrary.cpp` → `UploadClass("[ComponentName]", ...)`.
**Instances**: `ClassName = "[ComponentName]"` in `Bin/Configs/*/Model_*.xml` / `Bin/ClDesc/`.

[Short description.]

**Usage:** `Bin/Configs/...`, `Bin/ClDesc/...` when available.

### UML class diagram

Mirror the RU section; keep Mermaid diagrams language-neutral.

### Properties

| Property | Type | Description |
|----------|------|-------------|
| `Property1` | `Type` | [description] |

### Methods

- **`ADefault()`** — [description]
- **`ABuild()`** — [description]
- **`AReset()`** — [description]
- **`ACalculate()`** — [description]

### Examples

Mirror RU C++/XML examples with English comments if needed.

### See also

- [Component-Catalog.md](Component-Catalog.md)
- [API-Overview.md](API-Overview.md)
- [Usage-Examples.md](Usage-Examples.md)
