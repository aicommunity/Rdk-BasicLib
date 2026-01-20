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

Базовый класс для источников матричных данных. Наследуется от `UNet`.

**Свойства:**

Входные свойства:
- `DoubleMatrixInput` (`MDMatrix<double>`) - входная матрица типа double
- `IntMatrixInput` (`MDMatrix<int>`) - входная матрица типа int
- `DoubleVectorInput` (`MDVector<double>`) - входной вектор типа double
- `IntVectorInput` (`MDVector<int>`) - входной вектор типа int

Выходные свойства:
- `DoubleMatrix` (`MDMatrix<double>`) - выходная матрица типа double (параметр/выход)
- `IntMatrix` (`MDMatrix<int>`) - выходная матрица типа int (параметр/выход)
- `DoubleVector` (`MDVector<double>`) - выходной вектор типа double (параметр/выход)
- `IntVector` (`MDVector<int>`) - выходной вектор типа int (параметр/выход)

**Методы жизненного цикла:**

- `New()` - создание нового экземпляра компонента
- `ADefault()` - установка значений по умолчанию
- `ABuild()` - построение компонента (вызывается после `Default()`)
- `AReset()` - сброс состояния компонента
- `ACalculate()` - выполнение расчета компонента

**Методы сериализации:**

- `ASDefault()` - установка значений по умолчанию для сериализации
- `ASBuild()` - построение для сериализации
- `ASReset()` - сброс для сериализации
- `ASCalculate()` - расчет для сериализации

**Использование:**

```cpp
auto source = storage->CreateComponent<UMatrixSource>();
source->DoubleMatrixInput = inputMatrix;
source->Build();
source->Calculate();
auto outputMatrix = source->DoubleMatrix;
```

#### UStatistic

Базовый абстрактный класс для статистических вычислений. Наследуется от `UNet`.

**Свойства:**

Параметры сохранения:
- `SavePath` (`std::string`) - путь для сохранения статистики
- `PrefixName` (`std::string`) - префикс имени файла
- `SubFolderAfterResetFlag` (`bool`) - создавать подпапку после Reset
- `ForceCreateSavePath` (`bool`) - принудительно создавать путь сохранения
- `TimeToFileNameFlag` (`bool`) - добавлять время в имя файла
- `OrderIndexToFileNameFlag` (`bool`) - добавлять порядковый индекс в имя файла
- `NumSkipSteps` (`int`) - количество пропускаемых шагов

Параметры режима:
- `ManualModeEnabled` (`bool`) - включен ли ручной режим
- `TimeInterval` (`double`) - интервал времени для сохранения
- `ManualModeSwitch` (`bool`) - переключатель ручного режима

**Методы:**

- `SetSavePath(const std::string &value)` - установить путь сохранения
- `SetPrefixName(const std::string &value)` - установить префикс имени
- `SetSubFolderAfterResetFlag(bool value)` - установить флаг создания подпапки
- `SetTimeInterval(const double &value)` - установить интервал времени

**Методы жизненного цикла:**

- `ADefault()` - установка значений по умолчанию
- `ABuild()` - построение компонента
- `AReset()` - сброс состояния
- `ACalculate()` - выполнение расчета

**Абстрактные методы (должны быть реализованы в наследниках):**

- `AFSDefault()` - установка значений по умолчанию для сериализации
- `AFSBuild()` - построение для сериализации
- `AFSReset()` - сброс для сериализации
- `AFSCalculate()` - расчет для сериализации

#### UStatisticMatrix<T>

Шаблонный класс для статистических вычислений над матрицами. Наследуется от `UStatistic`.

**Свойства:**

Параметры сохранения:
- `SaveMode` (`int`) - режим сохранения (0 - не сохранять, 1 - сохранять)
- `AverageMode` (`int`) - режим усреднения (0 - сохранять в файл, 1 - сохранять для каждой итерации)
- `AverageNumber` (`int`) - количество итераций для усреднения
- `AverageInput` (`std::pair<std::string,std::string>`) - входная пара для усреднения статистики

Флаги записи:
- `WriteTimeStampFlag` (`bool`) - записывать временную метку
- `WriteTimeFromResetFlag` (`bool`) - записывать время с момента Reset
- `WriteSourceTimeStampFlag` (`bool`) - записывать временную метку источника
- `WriteModelTimeStampFlag` (`bool`) - записывать временную метку модели
- `WriteIndexFlag` (`bool`) - записывать индекс
- `ExcludeModelFileName` (`bool`) - исключать имя файла модели

Входные данные:
- `InputMatrixData` (`std::vector<MDMatrix<T>>`) - входные матричные данные

Состояние:
- `CurrentAverageNumber` (`int`) - текущее число усреднений

**Методы:**

- `New()` - создание нового экземпляра

**Использование:**

```cpp
auto statistic = storage->CreateComponent<UStatisticMatrix<double>>();
statistic->InputMatrixData = {matrix1, matrix2, matrix3};
statistic->SaveMode = 1;
statistic->AverageNumber = 10;
statistic->Build();
statistic->Calculate();
```

#### UNoiseGen<T>

Шаблонный класс генератора шума. Наследуется от `UNoise<T>`.

**Свойства:**

Параметры:
- `NoiseLevel` (`double`) - уровень шума

**Методы:**

- `New()` - создание нового экземпляра компонента
- `GenerateNoise(double lvlNoise)` - генерация шума с заданным уровнем
  - Возвращает: значение шума типа `T`
  - Параметры: `lvlNoise` - уровень шума

**Методы жизненного цикла:**

- `ANoiseDefault()` - установка значений по умолчанию
- `ANoiseBuild()` - построение компонента
- `ANoiseReset()` - сброс состояния
- `ANoiseCalculate()` - выполнение расчета и генерация шума

**Использование:**

```cpp
auto noiseGen = storage->CreateComponent<UNoiseGen<double>>();
noiseGen->NoiseLevel = 0.1;
noiseGen->Build();
noiseGen->Calculate();
auto noise = noiseGen->GenerateNoise(0.05);
```

#### UMatrixSourceFile

Класс для загрузки матричных данных из файла. Наследуется от `UNet`.

**Свойства:**

Параметры:
- `FileName` (`std::string`) - имя файла для загрузки
- `IsCheckDateTime` (`bool`) - проверять дату/время изменения файла
- `SkipCalcIfNoNewData` (`bool`) - пропускать расчет, если нет новых данных
- `UseRelativePathFromConfig` (`bool`) - использовать относительный путь от конфигурации
- `UseRelativePathFromWorkDir` (`bool`) - использовать относительный путь от рабочей директории

Выходные данные:
- `Matrix` (`MDMatrix<double>`) - загруженная матрица

Состояние:
- `IsNewData` (`bool`) - флаг наличия новых данных

**Методы:**

- `New()` - создание нового экземпляра
- `SetUseRelativePathFromConfig(const bool &value)` - установить использование относительного пути от конфигурации
- `SetUseRelativePathFromWorkDir(const bool &value)` - установить использование относительного пути от рабочей директории
- `ReadAndDecode(const std::string &file_name)` - чтение и декодирование файла
- `CalcActualSourceFilePath(const std::string &file_name)` - вычисление фактического пути к файлу источника

**Методы жизненного цикла:**

- `ADefault()` - установка значений по умолчанию
- `ABuild()` - построение компонента
- `AReset()` - сброс состояния
- `ACalculate()` - выполнение расчета и загрузка данных

**Использование:**

```cpp
auto source = storage->CreateComponent<UMatrixSourceFile>();
source->FileName = "data.csv";
source->IsCheckDateTime = true;
source->Build();
source->Calculate();
if (source->IsNewData) {
    auto matrix = source->Matrix;
}
```

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

Base class for matrix data sources. Inherits from `UNet`.

**Properties:**

Input properties:
- `DoubleMatrixInput` (`MDMatrix<double>`) - input matrix of type double
- `IntMatrixInput` (`MDMatrix<int>`) - input matrix of type int
- `DoubleVectorInput` (`MDVector<double>`) - input vector of type double
- `IntVectorInput` (`MDVector<int>`) - input vector of type int

Output properties:
- `DoubleMatrix` (`MDMatrix<double>`) - output matrix of type double (parameter/output)
- `IntMatrix` (`MDMatrix<int>`) - output matrix of type int (parameter/output)
- `DoubleVector` (`MDVector<double>`) - output vector of type double (parameter/output)
- `IntVector` (`MDVector<int>`) - output vector of type int (parameter/output)

**Lifecycle Methods:**

- `New()` - create new component instance
- `ADefault()` - set default values
- `ABuild()` - build component (called after `Default()`)
- `AReset()` - reset component state
- `ACalculate()` - execute component calculation

**Serialization Methods:**

- `ASDefault()` - set default values for serialization
- `ASBuild()` - build for serialization
- `ASReset()` - reset for serialization
- `ASCalculate()` - calculate for serialization

**Usage:**

```cpp
auto source = storage->CreateComponent<UMatrixSource>();
source->DoubleMatrixInput = inputMatrix;
source->Build();
source->Calculate();
auto outputMatrix = source->DoubleMatrix;
```

#### UStatistic

Base abstract class for statistical computations. Inherits from `UNet`.

**Properties:**

Save parameters:
- `SavePath` (`std::string`) - path for saving statistics
- `PrefixName` (`std::string`) - file name prefix
- `SubFolderAfterResetFlag` (`bool`) - create subfolder after Reset
- `ForceCreateSavePath` (`bool`) - force create save path
- `TimeToFileNameFlag` (`bool`) - add time to file name
- `OrderIndexToFileNameFlag` (`bool`) - add order index to file name
- `NumSkipSteps` (`int`) - number of steps to skip

Mode parameters:
- `ManualModeEnabled` (`bool`) - manual mode enabled
- `TimeInterval` (`double`) - time interval for saving
- `ManualModeSwitch` (`bool`) - manual mode switch

**Methods:**

- `SetSavePath(const std::string &value)` - set save path
- `SetPrefixName(const std::string &value)` - set prefix name
- `SetSubFolderAfterResetFlag(bool value)` - set subfolder flag
- `SetTimeInterval(const double &value)` - set time interval

**Lifecycle Methods:**

- `ADefault()` - set default values
- `ABuild()` - build component
- `AReset()` - reset state
- `ACalculate()` - execute calculation

**Abstract Methods (must be implemented in derived classes):**

- `AFSDefault()` - set default values for serialization
- `AFSBuild()` - build for serialization
- `AFSReset()` - reset for serialization
- `AFSCalculate()` - calculate for serialization

#### UStatisticMatrix<T>

Template class for statistical computations on matrices. Inherits from `UStatistic`.

**Properties:**

Save parameters:
- `SaveMode` (`int`) - save mode (0 - don't save, 1 - save)
- `AverageMode` (`int`) - averaging mode (0 - save to file, 1 - save for each iteration)
- `AverageNumber` (`int`) - number of iterations for averaging
- `AverageInput` (`std::pair<std::string,std::string>`) - input pair for averaging statistics

Write flags:
- `WriteTimeStampFlag` (`bool`) - write timestamp
- `WriteTimeFromResetFlag` (`bool`) - write time from Reset
- `WriteSourceTimeStampFlag` (`bool`) - write source timestamp
- `WriteModelTimeStampFlag` (`bool`) - write model timestamp
- `WriteIndexFlag` (`bool`) - write index
- `ExcludeModelFileName` (`bool`) - exclude model file name

Input data:
- `InputMatrixData` (`std::vector<MDMatrix<T>>`) - input matrix data

State:
- `CurrentAverageNumber` (`int`) - current average number

**Methods:**

- `New()` - create new instance

**Usage:**

```cpp
auto statistic = storage->CreateComponent<UStatisticMatrix<double>>();
statistic->InputMatrixData = {matrix1, matrix2, matrix3};
statistic->SaveMode = 1;
statistic->AverageNumber = 10;
statistic->Build();
statistic->Calculate();
```

#### UNoiseGen<T>

Template class for noise generation. Inherits from `UNoise<T>`.

**Properties:**

Parameters:
- `NoiseLevel` (`double`) - noise level

**Methods:**

- `New()` - create new component instance
- `GenerateNoise(double lvlNoise)` - generate noise with specified level
  - Returns: noise value of type `T`
  - Parameters: `lvlNoise` - noise level

**Lifecycle Methods:**

- `ANoiseDefault()` - set default values
- `ANoiseBuild()` - build component
- `ANoiseReset()` - reset state
- `ANoiseCalculate()` - execute calculation and generate noise

**Usage:**

```cpp
auto noiseGen = storage->CreateComponent<UNoiseGen<double>>();
noiseGen->NoiseLevel = 0.1;
noiseGen->Build();
noiseGen->Calculate();
auto noise = noiseGen->GenerateNoise(0.05);
```

#### UMatrixSourceFile

Class for loading matrix data from file. Inherits from `UNet`.

**Properties:**

Parameters:
- `FileName` (`std::string`) - file name to load
- `IsCheckDateTime` (`bool`) - check file modification date/time
- `SkipCalcIfNoNewData` (`bool`) - skip calculation if no new data
- `UseRelativePathFromConfig` (`bool`) - use relative path from config
- `UseRelativePathFromWorkDir` (`bool`) - use relative path from work directory

Output data:
- `Matrix` (`MDMatrix<double>`) - loaded matrix

State:
- `IsNewData` (`bool`) - flag indicating new data availability

**Methods:**

- `New()` - create new instance
- `SetUseRelativePathFromConfig(const bool &value)` - set use relative path from config
- `SetUseRelativePathFromWorkDir(const bool &value)` - set use relative path from work directory
- `ReadAndDecode(const std::string &file_name)` - read and decode file
- `CalcActualSourceFilePath(const std::string &file_name)` - calculate actual source file path

**Lifecycle Methods:**

- `ADefault()` - set default values
- `ABuild()` - build component
- `AReset()` - reset state
- `ACalculate()` - execute calculation and load data

**Usage:**

```cpp
auto source = storage->CreateComponent<UMatrixSourceFile>();
source->FileName = "data.csv";
source->IsCheckDateTime = true;
source->Build();
source->Calculate();
if (source->IsNewData) {
    auto matrix = source->Matrix;
}
```

### See Also

- [Reports/03-Rdk-BasicLib.md](../../../Reports/03-Rdk-BasicLib.md) - detailed description
- Source code: `Libraries/Rdk-BasicLib/Core/`
