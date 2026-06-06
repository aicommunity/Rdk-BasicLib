# Статус документации Rdk-BasicLib

## RU

Краткий статус документации библиотеки Rdk-BasicLib и чеклист синхронизации с кодом.

**Аудит:** 2026-06-06 — [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md), [Code-Inventory.json](../../../Docs/Audit/Code-Inventory.json)

---

## Статистика (сверка с кодом)

| Метрика | Значение |
|---------|----------|
| Зарегистрированных классов (`UploadClass`) | **15** |
| Файлов `Docs/Components/*.md` | **13** |
| Классов без отдельного doc-файла | **6** |
| Orphan docs (групповые/legacy) | **4** |
| Отсутствуют в Component-Catalog | **7** |
| Регистрация | `UBCLLibrary.cpp`, `UIOLibrary.cpp` |

**Прогресс по классам:** 9/15 (60%) — есть прямое или групповое покрытие; 6 классов требуют отдельных страниц или явных якорей в каталоге.

---

## Выполнено

### Общая документация
- ✅ **README.md** — обзор библиотеки, быстрый старт (RU/EN)
- ✅ **Architecture.md** — архитектура подсистем IO, источников, статистики (RU/EN)
- ✅ **API-Overview.md** — обзор публичного API (RU/EN)
- ✅ **Usage-Examples.md** — примеры C++ и XML (RU/EN)
- ✅ **FAQ.md** — часто задаваемые вопросы (RU/EN)
- ✅ **Component-Catalog.md** — каталог с группировкой по назначению
- ✅ **Diagrams/** — Data-Flow, Component-Interactions (RU/EN)

### Компоненты с документацией (прямое покрытие)
- ✅ **UFileIO** — [`Components/UFileIO.md`](Components/UFileIO.md)
- ✅ **UIOTextConverter** — [`Components/UIOTextConverter.md`](Components/UIOTextConverter.md)
- ✅ **UMatrixSource** — [`Components/UMatrixSource.md`](Components/UMatrixSource.md)
- ✅ **UMatrixSourceTimeSeries** — [`Components/UMatrixSourceTimeSeries.md`](Components/UMatrixSourceTimeSeries.md)
- ✅ **UModel** — [`Components/UModel.md`](Components/UModel.md)
- ✅ **UScalarSource** — [`Components/UScalarSource.md`](Components/UScalarSource.md)
- ✅ **UStatisticDoubleMatrix** — [`Components/UStatisticDoubleMatrix.md`](Components/UStatisticDoubleMatrix.md)
- ✅ **UStatisticIntMatrix** — [`Components/UStatisticIntMatrix.md`](Components/UStatisticIntMatrix.md)
- ⚠ **UNoiseGen** — [`Components/UNoiseGen.md`](Components/UNoiseGen.md) (семейство; варианты `UNoiseGenDouble` / `UNoiseGenInt` не выделены отдельно)

### Групповые документы (частичное покрытие)
- ⚠ **UMatrixSourceFileFamily** — [`Components/UMatrixSourceFileFamily.md`](Components/UMatrixSourceFileFamily.md) — описывает `UMatrixSourceDataFile`, `UUMatrixSourceFile`, `UMatrixSourceFileSep`, `UFileDataset`, но без отдельных страниц на класс

### Orphan docs (ожидаемые legacy/групповые)
- `UIO`, `UIOConverter` — устаревшие имена IO
- `UNoise` — legacy-редирект к `UNoiseGen`
- `UMatrixSourceFileFamily` — групповой doc (см. выше)

---

## Планируется / рекомендации

### Приоритет P0 — закрыть gap по классам
- [ ] **UFileDataset** — создать `Components/UFileDataset.md` или расширить `UMatrixSourceFileFamily.md` с якорями и таблицами свойств
- [ ] **UMatrixSourceDataFile** — отдельная секция/страница
- [ ] **UMatrixSourceFileSep** — отдельная секция/страница
- [ ] **UUMatrixSourceFile** — отдельная секция/страница
- [ ] **UNoiseGenDouble** — выделить из `UNoiseGen.md` или создать `Components/UNoiseGenDouble.md`
- [ ] **UNoiseGenInt** — выделить из `UNoiseGen.md` или создать `Components/UNoiseGenInt.md`
- [ ] Обновить **Component-Catalog.md** — явные ссылки на все 15 `UploadClass` (сейчас 7 отсутствуют в каталоге)

### Приоритет P1 — качество и шаблон
- [ ] Создать **Component-Documentation-Template.md** (по образцу Nmsdk-MotionControlLib / Nmsdk-PulseLib)
- [ ] Добавить секцию **## EN** в **Component-Catalog.md** (currently RU-only — see [Bilingual-Parity-Report.md](../../../Docs/Audit/Bilingual-Parity-Report.md))
- [ ] Synchronize tables properties/methods с headers `Core/*.h`
- [ ] Add paths к examples в `Bin/ClDesc/` и `Bin/Configs/` в blockи «Usage in configurations»

### Priority P2 — navigation
- [ ] В beginning each component — link: «Directory: [Component-Catalog.md](Component-Catalog.md)»
- [ ] Check cross links из `Docs/Libraries/Rdk-BasicLib.md`

---

## Checklist по classes (`UploadClass`)

Registration: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`, `UIOLibrary.cpp`.

| ClassName | Doc-file | Status |
|-----------|----------|--------|
| `UFileDataset` | — | ❌ missing |
| `UFileIO` | `Components/UFileIO.md` | ✅ |
| `UIOTextConverter` | `Components/UIOTextConverter.md` | ✅ |
| `UMatrixSource` | `Components/UMatrixSource.md` | ✅ |
| `UMatrixSourceDataFile` | (group `UMatrixSourceFileFamily`) | ⚠ partially |
| `UMatrixSourceFileSep` | (group `UMatrixSourceFileFamily`) | ⚠ partially |
| `UMatrixSourceTimeSeries` | `Components/UMatrixSourceTimeSeries.md` | ✅ |
| `UModel` | `Components/UModel.md` | ✅ |
| `UNoiseGen` | `Components/UNoiseGen.md` | ✅ |
| `UNoiseGenDouble` | (group `UNoiseGen`) | ⚠ partially |
| `UNoiseGenInt` | (group `UNoiseGen`) | ⚠ partially |
| `UScalarSource` | `Components/UScalarSource.md` | ✅ |
| `UStatisticDoubleMatrix` | `Components/UStatisticDoubleMatrix.md` | ✅ |
| `UStatisticIntMatrix` | `Components/UStatisticIntMatrix.md` | ✅ |
| `UUMatrixSourceFile` | (group `UMatrixSourceFileFamily`) | ⚠ partially |

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

Rdk-BasicLib has **15** registered `UploadClass` entries and **13** component markdown files. **9** classes have direct or group documentation; **6** lack dedicated per-class pages (`UFileDataset`, `UMatrixSourceDataFile`, `UMatrixSourceFileSep`, `UUMatrixSourceFile`, `UNoiseGenDouble`, `UNoiseGenInt`). **4** orphan docs are expected legacy/group stubs.

**Progress:** 9/15 classes covered (60%).

### Sync checklist (code changes)

When adding or changing a class in `Core/`:

1. Update **Component-Catalog.md**
2. Update or create **Docs/Components/[ComponentName].md**
3. Update **API-Overview.md** and **Usage-Examples.md** if public API or typical usage changes
4. Re-run `Scripts/doc-audit/run-all.sh` and verify [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md)

---

*References: [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md), [Code-Inventory.json](../../../Docs/Audit/Code-Inventory.json); template — [Nmsdk-PulseLib/Docs/Documentation-Status.md](../../Nmsdk-PulseLib/Docs/Documentation-Status.md).*
