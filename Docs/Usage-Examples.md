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

### Пример 4: Композитная обработка данных с несколькими компонентами

```cpp
// Создание конвейера обработки данных
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "sensor_data.csv";
dataSource->Build();

// Добавление шума к данным для тестирования устойчивости
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Gaussian;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 0.1;
noiseGen->Build();

// Статистический анализ исходных данных
auto cleanStatistic = storage->CreateComponent<UStatistic>();
cleanStatistic->InputData = dataSource->GetMatrix();
cleanStatistic->Build();

// Статистический анализ зашумленных данных
auto noisyStatistic = storage->CreateComponent<UStatistic>();

// Связывание компонентов через свойства
noiseGen->InputMatrix = dataSource->GetMatrix();
noisyStatistic->InputData = noiseGen->OutputMatrix;

// Вычисление статистики
cleanStatistic->Calculate();
noiseGen->Calculate();
noisyStatistic->Calculate();

// Сравнение результатов
double cleanMean = cleanStatistic->Mean;
double noisyMean = noisyStatistic->Mean;
double noiseImpact = std::abs(cleanMean - noisyMean);
std::cout << "Влияние шума: " << noiseImpact << std::endl;
```

### Пример 5: Обработка временных рядов с валидацией данных

```cpp
// Создание источника временных рядов
auto timeSeriesSource = storage->CreateComponent<UMatrixSourceTimeSeries>();
timeSeriesSource->FileName = "timeseries.csv";
timeSeriesSource->TimeColumnIndex = 0;
timeSeriesSource->Build();

// Загрузка данных с проверкой
try {
    if (!timeSeriesSource->HasData()) {
        throw std::runtime_error("Нет данных в файле");
    }
    
    auto timeSeries = timeSeriesSource->GetMatrix();
    
    // Статистический анализ временного ряда
    auto statistic = storage->CreateComponent<UStatistic>();
    statistic->InputData = timeSeries;
    statistic->Build();
    statistic->Calculate();
    
    // Проверка на аномалии (данные за пределами 3 сигм)
    double threshold = 3.0 * statistic->StdDev;
    int anomalyCount = 0;
    
    for (int i = 0; i < timeSeries.Rows(); i++) {
        for (int j = 0; j < timeSeries.Cols(); j++) {
            double value = timeSeries(i, j);
            if (std::abs(value - statistic->Mean) > threshold) {
                anomalyCount++;
            }
        }
    }
    
    std::cout << "Обнаружено аномалий: " << anomalyCount << std::endl;
    
} catch (const RDK::UException& e) {
    std::cerr << "Ошибка обработки данных: " << e.what() << std::endl;
}
```

### Пример 6: Оптимизированная пакетная обработка данных

```cpp
// Создание источника данных
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "large_dataset.csv";
dataSource->Build();

// Предварительное выделение памяти для статистики
auto statistic = storage->CreateComponent<UStatistic>();
statistic->InputData = dataSource->GetMatrix();
statistic->Build();

// Пакетная обработка с кэшированием
const int batchSize = 1000;
auto data = dataSource->GetMatrix();
int totalRows = data.Rows();
int processedRows = 0;

while (processedRows < totalRows) {
    int endRow = std::min(processedRows + batchSize, totalRows);
    
    // Извлечение батча данных
    auto batch = data.GetSubMatrix(processedRows, 0, endRow - processedRows, data.Cols());
    
    // Обработка батча
    statistic->InputData = batch;
    statistic->Calculate();
    
    // Сохранение промежуточных результатов
    std::cout << "Обработано строк: " << endRow << "/" << totalRows 
              << ", Среднее: " << statistic->Mean << std::endl;
    
    processedRows = endRow;
}
```

### Пример 7: Интеграция с другими библиотеками

```cpp
// Использование данных из BasicLib в компонентах других библиотек
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "image_features.csv";
dataSource->Build();

// Генерация шума для аугментации данных
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Uniform;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 0.05;
noiseGen->InputMatrix = dataSource->GetMatrix();
noiseGen->Build();

// Статистическая нормализация данных перед передачей в ML модель
auto normalizer = storage->CreateComponent<UStatistic>();
normalizer->InputData = noiseGen->OutputMatrix;
normalizer->Build();
normalizer->Calculate();

// Нормализация данных (z-score)
auto normalizedData = noiseGen->OutputMatrix;
for (int i = 0; i < normalizedData.Rows(); i++) {
    for (int j = 0; j < normalizedData.Cols(); j++) {
        normalizedData(i, j) = (normalizedData(i, j) - normalizer->Mean) / normalizer->StdDev;
    }
}

// Historical note: optional ML libs (Rdk-TensorflowLib, Rdk-PyMachineLearningLib)
// are deprecated and not in .gitmodules — see Docs/Libraries/Optional-ML-Libraries.md
// For new work, use PulseLib / CvBasicLib pipelines instead.
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

### Example 4: Composite Data Processing with Multiple Components

```cpp
// Creating data processing pipeline
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "sensor_data.csv";
dataSource->Build();

// Adding noise to data for robustness testing
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Gaussian;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 0.1;
noiseGen->Build();

// Statistical analysis of clean data
auto cleanStatistic = storage->CreateComponent<UStatistic>();
cleanStatistic->InputData = dataSource->GetMatrix();
cleanStatistic->Build();

// Statistical analysis of noisy data
auto noisyStatistic = storage->CreateComponent<UStatistic>();

// Linking components via properties
noiseGen->InputMatrix = dataSource->GetMatrix();
noisyStatistic->InputData = noiseGen->OutputMatrix;

// Computing statistics
cleanStatistic->Calculate();
noiseGen->Calculate();
noisyStatistic->Calculate();

// Comparing results
double cleanMean = cleanStatistic->Mean;
double noisyMean = noisyStatistic->Mean;
double noiseImpact = std::abs(cleanMean - noisyMean);
std::cout << "Noise impact: " << noiseImpact << std::endl;
```

### Example 5: Time Series Processing with Data Validation

```cpp
// Creating time series source
auto timeSeriesSource = storage->CreateComponent<UMatrixSourceTimeSeries>();
timeSeriesSource->FileName = "timeseries.csv";
timeSeriesSource->TimeColumnIndex = 0;
timeSeriesSource->Build();

// Loading data with validation
try {
    if (!timeSeriesSource->HasData()) {
        throw std::runtime_error("No data in file");
    }
    
    auto timeSeries = timeSeriesSource->GetMatrix();
    
    // Statistical analysis of time series
    auto statistic = storage->CreateComponent<UStatistic>();
    statistic->InputData = timeSeries;
    statistic->Build();
    statistic->Calculate();
    
    // Anomaly detection (data beyond 3 sigma)
    double threshold = 3.0 * statistic->StdDev;
    int anomalyCount = 0;
    
    for (int i = 0; i < timeSeries.Rows(); i++) {
        for (int j = 0; j < timeSeries.Cols(); j++) {
            double value = timeSeries(i, j);
            if (std::abs(value - statistic->Mean) > threshold) {
                anomalyCount++;
            }
        }
    }
    
    std::cout << "Anomalies detected: " << anomalyCount << std::endl;
    
} catch (const RDK::UException& e) {
    std::cerr << "Data processing error: " << e.what() << std::endl;
}
```

### Example 6: Optimized Batch Data Processing

```cpp
// Creating data source
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "large_dataset.csv";
dataSource->Build();

// Pre-allocating memory for statistics
auto statistic = storage->CreateComponent<UStatistic>();
statistic->InputData = dataSource->GetMatrix();
statistic->Build();

// Batch processing with caching
const int batchSize = 1000;
auto data = dataSource->GetMatrix();
int totalRows = data.Rows();
int processedRows = 0;

while (processedRows < totalRows) {
    int endRow = std::min(processedRows + batchSize, totalRows);
    
    // Extracting data batch
    auto batch = data.GetSubMatrix(processedRows, 0, endRow - processedRows, data.Cols());
    
    // Processing batch
    statistic->InputData = batch;
    statistic->Calculate();
    
    // Saving intermediate results
    std::cout << "Processed rows: " << endRow << "/" << totalRows 
              << ", Mean: " << statistic->Mean << std::endl;
    
    processedRows = endRow;
}
```

### Example 7: Integration with Other Libraries

```cpp
// Using data from BasicLib in components from other libraries
auto dataSource = storage->CreateComponent<UMatrixSourceFile>();
dataSource->FileName = "image_features.csv";
dataSource->Build();

// Generating noise for data augmentation
auto noiseGen = storage->CreateComponent<UNoiseGen>();
noiseGen->NoiseType = NT_Uniform;
noiseGen->Mean = 0.0;
noiseGen->StdDev = 0.05;
noiseGen->InputMatrix = dataSource->GetMatrix();
noiseGen->Build();

// Statistical normalization before passing to ML model
auto normalizer = storage->CreateComponent<UStatistic>();
normalizer->InputData = noiseGen->OutputMatrix;
normalizer->Build();
normalizer->Calculate();

// Normalizing data (z-score)
auto normalizedData = noiseGen->OutputMatrix;
for (int i = 0; i < normalizedData.Rows(); i++) {
    for (int j = 0; j < normalizedData.Cols(); j++) {
        normalizedData(i, j) = (normalizedData(i, j) - normalizer->Mean) / normalizer->StdDev;
    }
}

// Now normalizedData can be used in ML components
// Historical: optional ML libs are deprecated — see Docs/Libraries/Optional-ML-Libraries.md
```

### Integration with Rdk

The library is automatically registered on load.
