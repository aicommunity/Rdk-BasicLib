# Примеры использования Rdk-BasicLib

## RU

### Пример 1: Работа с матричными данными

```cpp
// Создание источника матричных данных из файла
auto matrixSource = storage->CreateComponent<UMatrixSourceFile>();
matrixSource->FileName = "data.csv";
matrixSource->Build();

// Получение данных
auto data = matrixSource->GetMatrix();
```

### Пример 2: Генерация шума

```cpp
// Создание генератора шума
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Gaussian;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 1.0;
noiseGen->Build();

// Генерация шума
auto noise = noiseGen->Generate();
```

### Пример 3: Статистические вычисления

```cpp
// Создание компонента статистики
auto statistic = storage->CreateComponent<UStatistic>();
statistic->InputData = dataMatrix;
statistic->Build();

// Вычисление статистики
statistic->Calculate();
auto mean = statistic->Mean;
auto variance = statistic->Variance;
```

### Интеграция с Rdk

Библиотека автоматически регистрируется при загрузке:

```cpp
bool RdkLoadPredefinedLibraries(std::list<ULibrary*> &libs_list)
{
    libs_list.push_back(&RDK::BasicLibrary);
    // ...
}
```

---

## EN

### Example 1: Working with Matrix Data

```cpp
// Creating matrix data source from file
auto matrixSource = storage->CreateComponent<UMatrixSourceFile>();
matrixSource->FileName = "data.csv";
matrixSource->Build();

// Getting data
auto data = matrixSource->GetMatrix();
```

### Example 2: Noise Generation

```cpp
// Creating noise generator
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Gaussian;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 1.0;
noiseGen->Build();

// Generating noise
auto noise = noiseGen->Generate();
```

### Example 3: Statistical Computations

```cpp
// Creating statistics component
auto statistic = storage->CreateComponent<UStatistic>();
statistic->InputData = dataMatrix;
statistic->Build();

// Computing statistics
statistic->Calculate();
auto mean = statistic->Mean;
auto variance = statistic->Variance;
```

### Integration with Rdk

The library is automatically registered on load.
