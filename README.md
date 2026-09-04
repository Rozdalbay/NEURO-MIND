# NEURO//MIND

NEURO//MIND — настольная демонстрация простой нейронной сети с интерактивной
визуализацией. Приложение написано на C++20 и Qt Quick/QML.

Это не фреймворк машинного обучения и не языковая модель. В текущей версии
используется собственная небольшая симуляция: нейроны передают сигналы по
взвешенным связям, их активность затухает, а веса связей со временем меняются.

## Что реализовано

- генерация демонстрационной сети из 60 нейронов;
- распространение и затухание активности;
- простая пластичность связей и удаление ослабевших синапсов;
- случайное появление новых нейронов с ограничением размера сети;
- интерактивная визуализация сети с масштабированием и выбором нейронов;
- создание, активация и удаление записей памяти;
- постепенное ослабление памяти;
- шесть вычисляемых показателей состояния: happiness, sadness, fear, anger,
  curiosity и calm;
- Dream Mode со случайной стимуляцией сети и воспроизведением воспоминаний;
- изменение скорости симуляции, сброс и журнал событий;
- сохранение и загрузка состояния в JSON-файл `brain_save.json`.

Математика проекта носит демонстрационный характер и не моделирует работу
биологического мозга с научной точностью.

## Требования

- CMake 3.20 или новее;
- компилятор с поддержкой C++20;
- Qt 6.5 или новее с библиотеками:
  - Core;
  - Gui;
  - Quick;
  - Quick Controls 2;
  - QML-модуль Qt Quick Effects.

Компилятор и Qt SDK в репозиторий не входят. Установите их системно или через
официальный Qt Online Installer. Компилятор должен соответствовать выбранной
сборке Qt: комплект `mingw_64` работает с поставляемой вместе с ним версией
MinGW, а комплект `msvc*_64` — с соответствующим MSVC.

## Сборка

### Вариант 1: Qt Creator

Это самый простой способ собрать проект на Windows, Linux или macOS.

1. Установите Qt 6.5 или новее и Qt Creator.
2. В установщике Qt выберите один настольный 64-битный комплект: MinGW или
   MSVC на Windows, GCC/Clang на Linux либо Clang на macOS.
3. Откройте корневой `CMakeLists.txt` через **File → Open File or Project**.
4. Выберите установленный Desktop Kit. Не смешивайте Qt для MinGW с MSVC и
   наоборот.
5. Нажмите **Configure Project**, затем **Build** и **Run**.

Qt Creator сам передаёт CMake путь к выбранной установке Qt и запускает
приложение с нужными библиотеками.

### Вариант 2: Windows и MinGW из комплекта Qt

В Qt Online Installer установите:

- Qt 6.5+ → MinGW 64-bit;
- Developer and Designer Tools → CMake;
- Developer and Designer Tools → Ninja;
- версию MinGW, предложенную для выбранной версии Qt.

Названия каталогов зависят от версии. В примере ниже замените три пути на
реальные пути своей установки. Команды выполняются в PowerShell из корня
репозитория:

```powershell
$qtRoot = "C:\Qt\6.8.3\mingw_64"
$cmakeBin = "C:\Qt\Tools\CMake_64\bin"
$ninjaBin = "C:\Qt\Tools\Ninja"
$mingwBin = "C:\Qt\Tools\mingw1310_64\bin"
$env:Path = "$cmakeBin;$ninjaBin;$mingwBin;$env:Path"

cmake -S . -B build -G Ninja `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_PREFIX_PATH="$qtRoot"
cmake --build build --parallel
```

Запуск:

```powershell
.\build\Neuromind.exe
```

Для переноса программы на компьютер без Qt скопируйте исполняемый файл в
отдельный каталог и запустите `windeployqt`. Параметр `--qmldir` нужен, чтобы
утилита обнаружила используемые QML-модули:

```powershell
New-Item -ItemType Directory -Force package | Out-Null
Copy-Item .\build\Neuromind.exe .\package\
& "$qtRoot\bin\windeployqt.exe" --release --qmldir .\qml .\package\Neuromind.exe
```

После этого содержимое `package` можно переносить целиком.

### Вариант 3: Windows и MSVC

Установите Visual Studio 2022 с workload **Desktop development with C++**, а в
Qt Online Installer выберите 64-битный комплект Qt для MSVC 2022. Откройте
**x64 Native Tools Command Prompt for VS 2022**, перейдите в корень проекта и
выполните:

```bat
cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="C:/Qt/6.8.3/msvc2022_64"
cmake --build build --config Release --parallel
```

Запуск:

```bat
build\Release\Neuromind.exe
```

Развёртывание библиотек для отдельной поставки:

```bat
C:\Qt\6.8.3\msvc2022_64\bin\windeployqt.exe --release --qmldir qml build\Release\Neuromind.exe
```

### Вариант 4: Linux

Установите CMake, Ninja или Make, C++-компилятор и development-пакеты Qt 6 для
Qt Quick, Quick Controls 2 и Qt Quick Effects. Названия пакетов зависят от
дистрибутива. После установки выполните из корня репозитория:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
./build/Neuromind
```

Если Qt установлен не в системный каталог, передайте его префикс явно:

```sh
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH=/opt/Qt/6.8.3/gcc_64
cmake --build build --parallel
```

### Debug-сборка

Для Ninja, Makefiles и других одноконфигурационных генераторов тип сборки
задаётся во время конфигурации:

```sh
cmake -S . -B build-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug --parallel
```

Для Visual Studio он выбирается во время сборки:

```bat
cmake --build build --config Debug --parallel
```

### Чистая пересборка

В каталоге `build` находятся только сгенерированные файлы. Для чистой сборки
полностью удалите этот каталог, затем снова выполните команды конфигурации и
сборки. Исходники при этом не затрагиваются.

### Частые ошибки

- **`cmake` не найден** — добавьте каталог CMake в `PATH` либо запускайте CMake
  по полному пути.
- **`Could not find Qt6Config.cmake`** — исправьте `CMAKE_PREFIX_PATH`. Он должен
  указывать на корень конкретного комплекта, например `.../6.8.3/mingw_64`, а
  не на общий каталог `C:\Qt`.
- **CMake нашёл Qt, но не компилятор** — добавьте совместимый компилятор в
  `PATH` или запускайте сборку из среды разработчика Visual Studio.
- **Ошибки линковки после смены MinGW/MSVC** — удалите старый каталог `build` и
  сконфигурируйте проект заново с одним согласованным комплектом.
- **`module "QtQuick.Effects" is not installed`** — добавьте QML-модуль Qt Quick
  Effects для установленной версии Qt.
- **Приложение запускается из Qt Creator, но не отдельно** — выполните
  `windeployqt` и запускайте файл из подготовленного каталога вместе с
  библиотеками и QML-плагинами.

Все пути и номера версий в примерах условные; используйте фактически
установленную версию Qt.

## Использование

После стартовой анимации приложение создаёт демонстрационную сеть и запускает
симуляцию. Основные разделы интерфейса:

- **Dashboard** — активность, число нейронов/синапсов и последние записи памяти;
- **Neural Network** — граф сети, выбор узлов, масштабирование и случайная
  стимуляция;
- **Memory** — создание записей с категорией, интенсивностью и числом связанных
  нейронов;
- **Emotions** — текущие вычисляемые показатели состояния;
- **Dream Mode** — наблюдение за фоновой случайной активностью;
- **Settings** — скорость симуляции, сохранение, загрузка и создание новой сети;
- **System Log** — внутренний журнал событий.

Кнопки **SAVE BRAIN** и **LOAD BRAIN** работают с файлом `brain_save.json` в
текущем рабочем каталоге процесса. Формат сохранения включает нейроны, синапсы,
память, показатели состояния и следующие идентификаторы объектов.

## Структура проекта

```text
.
├── CMakeLists.txt
├── qml/
│   ├── Main.qml
│   ├── MainWindow.qml
│   ├── StartupScreen.qml
│   ├── brain/
│   ├── components/
│   ├── dashboard/
│   ├── dream/
│   ├── emotions/
│   ├── memory/
│   └── settings/
└── src/
    ├── main.cpp
    ├── app/ApplicationController.*
    ├── core/Logger.*
    ├── core/SimulationClock.*
    └── visualization/NeuralNetworkItem.*
```

`ApplicationController` хранит состояние симуляции и предоставляет его QML.
`SimulationClock` формирует такты с регулируемой скоростью. `Logger` ведёт
ограниченный журнал, а `NeuralNetworkItem` отрисовывает сеть через scene graph
Qt Quick.

## Ограничения текущей версии

- автоматических тестов пока нет;
- параметры симуляции заданы константами в исходном коде;
- путь к JSON-сохранению задаётся интерфейсом жёстко и не выбирается через
  системный диалог;
- интеграции с Ollama, Qwen или другой языковой моделью нет;
- готовые бинарные сборки и сторонние toolchain/SDK намеренно не хранятся в Git.

## Лицензия

Проект распространяется по лицензии MIT. Полный текст находится в файле
[LICENSE](LICENSE).
