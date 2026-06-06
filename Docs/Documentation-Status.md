# Статус документации Rdk-BasicLib

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
- [ ] Добавить секцию **## EN** в **Component-Catalog.md** (сейчас RU-only — см. [Bilingual-Parity-Report.md](../../../Docs/Audit/Bilingual-Parity-Report.md))
- [ ] Синхронизировать таблицы свойств/методов с заголовками `Core/*.h`
- [ ] Добавить пути к примерам в `Bin/ClDesc/` и `Bin/Configs/` в блоки «Использование в конфигурациях»

### Приоритет P2 — навигация
- [ ] В начале каждого компонента — ссылка: «Каталог: [Component-Catalog.md](Component-Catalog.md)»
- [ ] Проверить перекрёстные ссылки из `Docs/Libraries/Rdk-BasicLib.md`

---

## Чеклист по классам (`UploadClass`)

Регистрация: `Libraries/Rdk-BasicLib/Core/UBCLLibrary.cpp`, `UIOLibrary.cpp`.

| ClassName | Doc-файл | Статус |
|-----------|----------|--------|
| `UFileDataset` | — | ❌ отсутствует |
| `UFileIO` | `Components/UFileIO.md` | ✅ |
| `UIOTextConverter` | `Components/UIOTextConverter.md` | ✅ |
| `UMatrixSource` | `Components/UMatrixSource.md` | ✅ |
| `UMatrixSourceDataFile` | (группа `UMatrixSourceFileFamily`) | ⚠ частично |
| `UMatrixSourceFileSep` | (группа `UMatrixSourceFileFamily`) | ⚠ частично |
| `UMatrixSourceTimeSeries` | `Components/UMatrixSourceTimeSeries.md` | ✅ |
| `UModel` | `Components/UModel.md` | ✅ |
| `UNoiseGen` | `Components/UNoiseGen.md` | ✅ |
| `UNoiseGenDouble` | (группа `UNoiseGen`) | ⚠ частично |
| `UNoiseGenInt` | (группа `UNoiseGen`) | ⚠ частично |
| `UScalarSource` | `Components/UScalarSource.md` | ✅ |
| `UStatisticDoubleMatrix` | `Components/UStatisticDoubleMatrix.md` | ✅ |
| `UStatisticIntMatrix` | `Components/UStatisticIntMatrix.md` | ✅ |
| `UUMatrixSourceFile` | (группа `UMatrixSourceFileFamily`) | ⚠ частично |

---

## Чеклист синхронизации с кодом

При добавлении или изменении класса в `Libraries/Rdk-BasicLib/Core/` рекомендуется обновить:

1. **Component-Catalog.md** — при регистрации нового `UploadClass` в `UBCLLibrary.cpp` / `UIOLibrary.cpp`
2. **Docs/Components/[ComponentName].md** — таблицы свойств и методов, диаграммы, примеры C++/XML
3. **API-Overview.md** — при изменении публичного API ключевых классов (`UMatrixSource`, `UStatistic*`, `UNoiseGen*`, `UModel`)
4. **Usage-Examples.md** — при появлении новых типовых сценариев или путей к конфигам
5. **Architecture.md** / **Diagrams/** — при изменении потоков данных между подсистемами
6. Перезапустить аудит: `Scripts/doc-audit/run-all.sh` и сверить [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md)

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

*Источники: [Component-Gap-Report.md](../../../Docs/Audit/Component-Gap-Report.md), [Code-Inventory.json](../../../Docs/Audit/Code-Inventory.json); шаблон — [Nmsdk-PulseLib/Docs/Documentation-Status.md](../../Nmsdk-PulseLib/Docs/Documentation-Status.md).*
