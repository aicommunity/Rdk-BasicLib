# Обзор API Rdk-BasicLib

## RU

### Основные классы

#### UBasicLib

Главный класс библиотеки, наследник `ULibrary`.

**Методы:**
- `CreateClassSamples(UStorage *storage)` - регистрация компонентов библиотеки

#### UIO

Базовый компонент для операций ввода-вывода.

**Основные свойства:**
- Входные/выходные данные
- Параметры формата

#### UMatrixSource

Базовый класс для источников матричных данных.

**Основные методы:**
- `GetMatrix()` - получение матрицы данных
- `HasData()` - проверка наличия данных

#### UStatistic

Компонент для статистических вычислений.

**Основные свойства:**
- `InputData` - входные данные
- `Mean` - среднее значение
- `Variance` - дисперсия
- `StdDev` - стандартное отклонение

#### UNoiseGen

Генератор шума.

**Основные свойства:**
- `NoiseType` - тип шума (Gaussian, Uniform, etc.)
- `Mean` - среднее значение
- `StdDev` - стандартное отклонение

### См. также

- [Reports/03-Rdk-BasicLib.md](../../../Reports/03-Rdk-BasicLib.md) - детальное описание
- Исходный код: `Libraries/Rdk-BasicLib/Core/`

---

## EN

### Main Classes

#### UBasicLib

Main library class, inherits from `ULibrary`.

**Methods:**
- `CreateClassSamples(UStorage *storage)` - register library components

#### UIO

Base component for I/O operations.

#### UMatrixSource

Base class for matrix data sources.

**Main Methods:**
- `GetMatrix()` - get data matrix
- `HasData()` - check data availability

#### UStatistic

Component for statistical computations.

**Main Properties:**
- `InputData` - input data
- `Mean` - mean value
- `Variance` - variance
- `StdDev` - standard deviation

#### UNoiseGen

Noise generator.

**Main Properties:**
- `NoiseType` - noise type (Gaussian, Uniform, etc.)
- `Mean` - mean value
- `StdDev` - standard deviation

### See Also

- [Reports/03-Rdk-BasicLib.md](../../../Reports/03-Rdk-BasicLib.md) - detailed description
- Source code: `Libraries/Rdk-BasicLib/Core/`
