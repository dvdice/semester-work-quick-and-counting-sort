# Quick Sort и сортировка подсчетом

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`


- _Алгоритмы сортировки Quick Sort и сортиросвки подсчетом_
- _Сортировки используются в абсолютном большинстве проектов, но у каждой сортировки есть свои спицифики. Например применение сортировки подсчётом целесообразно лишь тогда, когда сортируемые числа имеют (или их можно отобразить в) диапазон возможных значений, который достаточно мал по сравнению с сортируемым множеством._
- _Сложность быстрой сортировки O(nlogn), в худшем случае O(n^2), а сортировки подсчетом O(n^2)_

## Команда "MightyPoot"

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Валитов Дамир   | 100        |  _MightyPoot_               |

**Девиз команды**
> _no pasa nada_

## Структура проекта

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

1. С++ компилятор c поддержкой стандарта C++14 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 4 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/dvdice/semester-work-quick-and-counting-sort.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-quick-and-counting-sort

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

_Опишите формат хранения (JSON, XML, CSV, YAML и т.д.) и процесс генерации тестовых данных._

_Разрешается использовать собственный формат хранения данных._

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py --samples 1000 <output> [args ...]
```

- `--samples` - количество генерируемых элементов;
- `<output>` - выходной файл и т.д.

Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):

```csv
id, full_name
0, "Ramil Safin"
1, "Bulat Abbyasov"
...
```

**Примечание**. Для удобства запуска контрольных тестов рекомендуется организовывать данные в директориях, например:

```shell
dataset/data/
  add/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  search/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ...
```

По названию директории `/dataset/data/add` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

**Примечание**. Во избежание "захламления" репозитория большим объёмом данных рекомендуется указать ссылку на архив с
набором данных, который при необходимости можно скачать по ссылке. Наборы данных должны находиться в папке семестровой
работы на [Google Drive](https://drive.google.com/drive/folders/17-qridbMXFnz3E-6UjOj0WD1H0jWtpz3?usp=sharing).

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `random_search_benchmark` | поиск элементов по случайному индексу   | _время_         |
| `add_benchmark`           | добавление элементов в структуру данных | _время, память_ |
| ...                       | ...                                     | ...             |

##### Примеры запуска

```shell
./benchmark <input> <output> --trials 50
```

- `<input>` - входной файл с набором данных в формате CSV;
- `<output>` - выходной файл с результатами контрольного теста;
- `--trials` - количество прогонов на наборе данных и т.д.

Добавление 10000 случайных элементов в структуру данных (повторить операцию 50 раз и вычислить среднее время работы и
потребляемую память):

```
./add_benchmark.exe ../dataset/data/add/10000.csv metrics.txt --trials 50
``` 

где `<input> = ../dataset/data/add/10000.csv` и `<output> = metrics.txt`.

**Примечание**. Файл с метриками не обязателен, можете выводить данные в стандартный поток вывода (т.е. консоль).

## Источники
https://ru.wikipedia.org/wiki/Сортировка_подсчётом
https://ru.wikipedia.org/wiki/Быстрая_сортировка
https://brilliant.org/wiki/counting-sort/

_**Это не плагиат, это уважение чужого труда и помощь своим сокурсникам более подробно разобраться в теме.**_
