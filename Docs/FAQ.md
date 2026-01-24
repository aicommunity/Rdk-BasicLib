# FAQ - Rdk-BasicLib

## RU

### Общие вопросы

#### Что такое Rdk-BasicLib?

Rdk-BasicLib - это фундаментальная библиотека, предоставляющая базовые компоненты для работы с данными, вводом-выводом, матрицами, статистикой и генерацией данных. На неё опираются другие библиотеки проекта.

#### Какие основные категории компонентов входят в библиотеку?

- **Ввод-вывод (IO)** - UIO, UFileIO, UIOConverter
- **Матрицы и источники данных** - UMatrixSource, UMatrixSourceFileFamily
- **Статистика** - UStatisticDoubleMatrix, UStatisticIntMatrix
- **Генераторы данных** - UNoise, UNoiseGen
- **Модели** - UModel

### Компоненты ввода-вывода

#### Как прочитать данные из файла?

Используйте `UFileIO`:
```cpp
auto fileIO = storage->CreateComponent<UFileIO>("FileIO");
fileIO->FileName = "data.txt";
fileIO->Build();
fileIO->Calculate();
```

#### Как конвертировать данные между форматами?

Используйте `UIOConverter` или `UIOTextConverter`:
```cpp
auto converter = storage->CreateComponent<UIOConverter>("Converter");
converter->Input.AttachTo(&source->Output);
converter->OutputFormat = "CSV";
converter->Build();
```

### Матрицы и источники данных

#### Как создать источник данных из файла?

Используйте `UMatrixSource`:
```cpp
auto source = storage->CreateComponent<UMatrixSource>("Source");
source->FileName = "data.csv";
source->Build();
```

#### Как работать с временными рядами?

Используйте `UMatrixSourceTimeSeries`:
```cpp
auto timeSeries = storage->CreateComponent<UMatrixSourceTimeSeries>("TimeSeries");
timeSeries->FileName = "timeseries.csv";
timeSeries->TimeColumn = 0;
timeSeries->Build();
```

### Статистика

#### Как вычислить статистику по матрице?

Используйте `UStatisticDoubleMatrix`:
```cpp
auto statistic = storage->CreateComponent<UStatisticDoubleMatrix>("Statistic");
statistic->InputData.AttachTo(&source->OutputMatrix);
statistic->CalculateMean = true;
statistic->CalculateStdDev = true;
statistic->Build();
statistic->Calculate();
```

### Генераторы данных

#### Как сгенерировать шум?

Используйте `UNoise` или `UNoiseGen`:
```cpp
auto noise = storage->CreateComponent<UNoise>("Noise");
noise->NoiseType = "Gaussian";
noise->Mean = 0.0;
noise->StdDev = 1.0;
noise->Build();
```

### Интеграция

#### Как использовать компоненты Rdk-BasicLib с другими библиотеками?

Компоненты Rdk-BasicLib часто используются как источники данных для других библиотек:
- Подключите выход `UMatrixSource` к входу компонента из другой библиотеки
- Используйте `UIO` для сохранения результатов
- Используйте `UStatistic` для анализа данных

### Устранение неполадок

#### Файл не читается

- Проверьте путь к файлу
- Убедитесь, что файл существует
- Проверьте формат файла
- См. логи приложения

#### Матрица пустая

- Проверьте, что источник данных правильно настроен
- Убедитесь, что файл содержит данные
- Проверьте параметры чтения

### Дополнительные ресурсы

- [Architecture.md](Architecture.md) - архитектура библиотеки
- [Component-Catalog.md](Component-Catalog.md) - каталог компонентов
- [Usage-Examples.md](Usage-Examples.md) - примеры использования
- [Docs/Troubleshooting/Troubleshooting-Guide.md](../../../Docs/Troubleshooting/Troubleshooting-Guide.md) - общее руководство по устранению неполадок

---

## EN

### General Questions

#### What is Rdk-BasicLib?

Rdk-BasicLib is a fundamental library providing basic components for data operations, input-output, matrices, statistics, and data generation. Other project libraries depend on it.

#### What are the main component categories in the library?

- **Input-Output (IO)** - UIO, UFileIO, UIOConverter
- **Matrices and Data Sources** - UMatrixSource, UMatrixSourceFileFamily
- **Statistics** - UStatisticDoubleMatrix, UStatisticIntMatrix
- **Data Generators** - UNoise, UNoiseGen
- **Models** - UModel

### I/O Components

#### How do I read data from a file?

Use `UFileIO`:
```cpp
auto fileIO = storage->CreateComponent<UFileIO>("FileIO");
fileIO->FileName = "data.txt";
fileIO->Build();
fileIO->Calculate();
```

#### How do I convert data between formats?

Use `UIOConverter` or `UIOTextConverter`:
```cpp
auto converter = storage->CreateComponent<UIOConverter>("Converter");
converter->Input.AttachTo(&source->Output);
converter->OutputFormat = "CSV";
converter->Build();
```

### Matrices and Data Sources

#### How do I create a data source from a file?

Use `UMatrixSource`:
```cpp
auto source = storage->CreateComponent<UMatrixSource>("Source");
source->FileName = "data.csv";
source->Build();
```

#### How do I work with time series?

Use `UMatrixSourceTimeSeries`:
```cpp
auto timeSeries = storage->CreateComponent<UMatrixSourceTimeSeries>("TimeSeries");
timeSeries->FileName = "timeseries.csv";
timeSeries->TimeColumn = 0;
timeSeries->Build();
```

### Statistics

#### How do I calculate statistics for a matrix?

Use `UStatisticDoubleMatrix`:
```cpp
auto statistic = storage->CreateComponent<UStatisticDoubleMatrix>("Statistic");
statistic->InputData.AttachTo(&source->OutputMatrix);
statistic->CalculateMean = true;
statistic->CalculateStdDev = true;
statistic->Build();
statistic->Calculate();
```

### Data Generators

#### How do I generate noise?

Use `UNoise` or `UNoiseGen`:
```cpp
auto noise = storage->CreateComponent<UNoise>("Noise");
noise->NoiseType = "Gaussian";
noise->Mean = 0.0;
noise->StdDev = 1.0;
noise->Build();
```

### Integration

#### How do I use Rdk-BasicLib components with other libraries?

Rdk-BasicLib components are often used as data sources for other libraries:
- Connect `UMatrixSource` output to input of component from another library
- Use `UIO` to save results
- Use `UStatistic` for data analysis

### Troubleshooting

#### File doesn't read

- Check file path
- Ensure file exists
- Check file format
- See application logs

#### Matrix is empty

- Check that data source is properly configured
- Ensure file contains data
- Check reading parameters

### Additional Resources

- [Architecture.md](Architecture.md) - library architecture
- [Component-Catalog.md](Component-Catalog.md) - component catalog
- [Usage-Examples.md](Usage-Examples.md) - usage examples
- [Docs/Troubleshooting/Troubleshooting-Guide.md](../../../Docs/Troubleshooting/Troubleshooting-Guide.md) - general troubleshooting guide
