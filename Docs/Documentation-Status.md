# Статус документации Rdk-BasicLib

## RU

Краткий статус документации библиотеки Rdk-BasicLib и чеклист синхронизации с кодом.

**Аудит:** 2026-06-06 — [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md), [Code-Inventory.json](../../../Docs/Audit/Code-Inventory.json)  
**Обновление Track 3:** 2026-07-27

---

## Статистика (сверка с кодом)

| Метрика | Значение |
|---------|----------|
| Зарегистрированных классов (`UploadClass`) | **15** |
| Файлов `Docs/Components/*.md` (per-class + group/legacy) | **19** |
| Классов с per-class doc-файлом | **15** |
| Классов без отдельного doc-файла | **0** |
| Orphan docs (групповые/legacy) | **4** |
| Отсутствуют в Component-Catalog | **0** |
| Регистрация | `UBCLLibrary.cpp`, `UIOLibrary.cpp` |

**Прогресс по классам:** 15/15 (100%) ✅ — у каждого `UploadClass` есть per-class страница; семейные обзоры сохранены.

---

## Выполнено

### Общая документация
- ✅ **README.md** — обзор библиотеки, быстрый старт (RU/EN)
- ✅ **Architecture.md** — архитектура подсистем IO, источников, статистики (RU/EN)
- ✅ **API-Overview.md** — обзор публичного API (RU/EN)
- ✅ **Usage-Examples.md** — примеры C++ и XML (RU/EN)
- ✅ **FAQ.md** — часто задаваемые вопросы (RU/EN)
- ✅ **Component-Catalog.md** — каталог всех 15 `UploadClass` (RU/EN)
- ✅ **Component-Documentation-Template.md** — шаблон per-class страницы
- ✅ **Diagrams/** — Data-Flow, Component-Interactions (RU/EN)

### Компоненты (все зарегистрированные классы)
- ✅ **UModel**, **UStatisticIntMatrix**, **UStatisticDoubleMatrix**
- ✅ **UFileIO**, **UIOTextConverter**
- ✅ **UNoiseGen**, **UNoiseGenDouble**, **UNoiseGenInt**
- ✅ **UMatrixSource**, **UScalarSource**, **UMatrixSourceTimeSeries**
- ✅ **UMatrixSourceDataFile**, **UUMatrixSourceFile**, **UMatrixSourceFileSep**, **UFileDataset**

### Групповые / orphan docs (ожидаемые)
- `UMatrixSourceFileFamily` — обзор файловых источников + якоря
- `UNoise` — legacy-редирект к `UNoiseGen`
- `UIO`, `UIOConverter` — устаревшие имена IO

---

## Планируется / рекомендации

### Приоритет P1 — качество
- [ ] Synchronize tables properties/methods с headers `Core/*.h` на stub-страницах file/noise вариантов
- [ ] Add paths к examples в `Bin/ClDesc/` и `Bin/Configs/` в blockи «Usage in configurations»

### Priority P2 — navigation
- [ ] Check cross links из `Docs/Libraries/Rdk-BasicLib.md`

---

## Checklist по classes (`UploadClass`)

Registration: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`, `UIOLibrary.cpp`.

| ClassName | Doc-file | Status |
|-----------|----------|--------|
| `UFileDataset` | `Components/UFileDataset.md` | ✅ |
| `UFileIO` | `Components/UFileIO.md` | ✅ |
| `UIOTextConverter` | `Components/UIOTextConverter.md` | ✅ |
| `UMatrixSource` | `Components/UMatrixSource.md` | ✅ |
| `UMatrixSourceDataFile` | `Components/UMatrixSourceDataFile.md` | ✅ |
| `UMatrixSourceFileSep` | `Components/UMatrixSourceFileSep.md` | ✅ |
| `UMatrixSourceTimeSeries` | `Components/UMatrixSourceTimeSeries.md` | ✅ |
| `UModel` | `Components/UModel.md` | ✅ |
| `UNoiseGen` | `Components/UNoiseGen.md` | ✅ |
| `UNoiseGenDouble` | `Components/UNoiseGenDouble.md` | ✅ |
| `UNoiseGenInt` | `Components/UNoiseGenInt.md` | ✅ |
| `UScalarSource` | `Components/UScalarSource.md` | ✅ |
| `UStatisticDoubleMatrix` | `Components/UStatisticDoubleMatrix.md` | ✅ |
| `UStatisticIntMatrix` | `Components/UStatisticIntMatrix.md` | ✅ |
| `UUMatrixSourceFile` | `Components/UUMatrixSourceFile.md` | ✅ |

---

## Checklist sync с code

При adding или changing class в `Libraries/Rdk-BasicLib/Core/` recommended update:

1. **Component-Catalog.md** — при registration new `UploadClass` в `UBCLLibrary.cpp` / `UIOLibrary.cpp`
2. **Docs/Components/[ComponentName].md** — property and method tables, diagrams, examples C++/XML
3. **API-Overview.md** — при changing public API key classes (`UMatrixSource`, `UStatistic*`, `UNoiseGen*`, `UModel`)
4. **Usage-Examples.md** — при appearance new typical scenarios или paths к configs
5. **Architecture.md** / **Diagrams/** — при changing flows data between subsystems
6. Rerun audit: `Scripts/doc-audit/run-all.sh` и verify [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md)

---

## EN

### Documentation status summary

Rdk-BasicLib has **15** registered `UploadClass` entries and **15** dedicated per-class component pages (plus group/legacy docs). Component-Catalog lists all 15 with RU/EN. Template: `Component-Documentation-Template.md`.

**Progress:** 15/15 classes covered (100%) ✅

### Sync checklist (code changes)

When adding or changing a class in `Core/`:

1. Update **Component-Catalog.md**
2. Update or create **Docs/Components/[ComponentName].md**
3. Update **API-Overview.md** and **Usage-Examples.md** if public API or typical usage changes
4. Re-run `Scripts/doc-audit/run-all.sh` and verify [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md)

---

*References: [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md), [Code-Inventory.json](../../../Docs/Audit/Code-Inventory.json); template — [Component-Documentation-Template.md](Component-Documentation-Template.md).*
