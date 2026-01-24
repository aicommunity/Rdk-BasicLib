# Rdk-BasicLib - Документация

## RU

### Назначение

**Rdk-BasicLib** предоставляет базовые компоненты для работы с данными, вводом-выводом, матрицами, статистикой и генерацией данных. Это фундаментальная библиотека, на которую опираются другие библиотеки проекта.

### Краткий обзор

Библиотека включает компоненты для:
- Ввода-вывода данных (IO операции)
- Работы с матрицами и источниками данных
- Статистических вычислений
- Генерации данных и шума
- Базовых математических моделей

### Быстрый старт

#### Чтение данных из файла

```cpp
// Создание источника данных
auto source = storage->CreateComponent<UMatrixSource>("Source");
source->FileName = "data.csv";
source->Default();
source->Build();

// Чтение данных
source->Calculate();
auto data = source->OutputMatrix();
```

#### Вычисление статистики

```cpp
// Создание статистического компонента
auto statistic = storage->CreateComponent<UStatisticDoubleMatrix>("Statistic");
statistic->InputData.AttachTo(&source->OutputMatrix);
statistic->CalculateMean = true;
statistic->Build();

// Вычисление
statistic->Calculate();
double mean = statistic->Mean();
```

### Связь с корневой документацией

Для обзорной информации см. корневую документацию проекта:
- `Docs/Libraries/Rdk-BasicLib.md` - обзор библиотеки (в корневом репозитории)

### Детальная документация

- [Architecture.md](Architecture.md) - архитектура библиотеки
- [Usage-Examples.md](Usage-Examples.md) - примеры использования
- [API-Overview.md](API-Overview.md) - обзор API
- [Component-Catalog.md](Component-Catalog.md) - каталог компонентов
- [FAQ.md](FAQ.md) - часто задаваемые вопросы
- `Docs/Components/*.md` - подробная документация по отдельным компонентам

### Шаблон документа компонента (mermaid UML)

Для всех компонентов `Rdk-BasicLib` используется единый шаблон `.md` (аналогично `Nmsdk-PulseLib`):

- `## <ComponentName> — краткое описание (RU)`
- `### Назначение`
- `### UML-диаграмма классов`
- `### UML-диаграмма последовательности`
- `### UML-диаграмма состояний` (если применимо)
- `### UML-диаграмма активности`
- `### UML-диаграмма компонентов`
- `### Свойства`
- `### Методы`
- `### Примеры использования в C++`
- `### Примеры использования в конфигурациях`

Каждая UML-секция оформляется как `mermaid`-диаграмма:

- Классы: ` ```mermaid` + `classDiagram` (иерархия, свойства, методы).
- Последовательность: ` ```mermaid` + `sequenceDiagram` (жизненный цикл, вызовы `ADefault/ABuild/AReset/ACalculate`).
- Состояния: ` ```mermaid` + `stateDiagram-v2` (инициализация, конфигурация, работа, сброс).
- Активность: ` ```mermaid` + `flowchart TD` (алгоритм работы ключевого метода, ветвления и циклы).
- Компоненты: ` ```mermaid` + `graph TB` (место компонента в архитектуре `Rdk-BasicLib`, связи с другими объектами).

EN-секция компонента следует той же структуре с английскими заголовками (`Purpose`, `UML Class Diagram`, `UML Sequence Diagram`, `Properties`, `Methods`, `Usage in C++`, `Usage in Configs`).

---

## EN

### Purpose

**Rdk-BasicLib** provides basic components for data operations, input-output, matrices, statistics, and data generation. This is a fundamental library that other project libraries depend on.

### Brief Overview

The library includes components for:
- Data I/O operations
- Matrix and data source operations
- Statistical computations
- Data and noise generation
- Basic mathematical models

### Link to Root Documentation

For overview information see root project documentation:
- `Docs/Libraries/Rdk-BasicLib.md` - library overview (in root repository)

### Detailed Documentation

- [Architecture.md](Architecture.md) - library architecture
- [Usage-Examples.md](Usage-Examples.md) - usage examples
- [API-Overview.md](API-Overview.md) - API overview
- [Component-Catalog.md](Component-Catalog.md) - component catalog
- [FAQ.md](FAQ.md) - frequently asked questions
- `Docs/Components/*.md` - per-component detailed documentation

### Component documentation template (mermaid UML)

All `Rdk-BasicLib` components share a unified `.md` template (similar to `Nmsdk-PulseLib`):

- `## <ComponentName> — short description (EN)`
- `### Purpose`
- `### UML Class Diagram`
- `### UML Sequence Diagram`
- `### UML State Diagram` (if applicable)
- `### UML Activity Diagram`
- `### UML Component Diagram`
- `### Properties`
- `### Methods`
- `### Usage in C++`
- `### Usage in Configs`

Each UML section is a `mermaid` diagram:

- Classes: ` ```mermaid` + `classDiagram` (inheritance, properties, methods).
- Sequence: ` ```mermaid` + `sequenceDiagram` (lifecycle, `ADefault/ABuild/AReset/ACalculate` calls).
- States: ` ```mermaid` + `stateDiagram-v2` (initialisation, configuration, running, reset).
- Activity: ` ```mermaid` + `flowchart TD` (core algorithm, branches and loops).
- Components: ` ```mermaid` + `graph TB` (component position in `Rdk-BasicLib` architecture, relations to other objects).
