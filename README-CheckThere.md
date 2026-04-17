# Check Exclusions There

Program will check if Antivirus Exclusions is set at some specified folders for NIT

Программа проверяет, установлены ли на определённые папки исключения антивируса.

## Назначение

Программа проверяет, установлены ли исключения антивируса на следующие папки:

- `%SystemRoot%` (ключ реестра `SystemRoot`)
- `C:\pub1` (ключ реестра `pub1`)
- `C:\Util` (ключ реестра `util`)
- `C:\.BIN` (ключ реестра `dotbun`)
- `C:\inetpub` (ключ реестра `wwwroot`)
- `%USERPROFILE%\Documents` или перемещённый (ключ реестра `MyDocuments`)
- `%USERPROFILE%\Desktop` или перемещённый (ключ реестра `MyDesktop`)
- `%USERPROFILE%\Downloads` или перемещённый (ключ реестра `MyDownloads`)

Если исключения установлены, соответствующие ключи в реестре Windows устанавливаются значением *1*.

Исключения проверяются в нодах:

- `HKEY_LOCAL_MACHINE\SOFTWARE\New Internet Technologies\Polices\Exclusions`
- `HKEY_CURRENT_USER\SOFTWARE\New Internet Technologies\Polices\Exclusions`

Затем указанные ключи используются при проверках на установку программ корпорации New Internet Technologies, Inc.

## Алгоритм работы

Утилита выполняет следующие функции:

1. Создаёт ветви реестра:

```
HKLM\SOFTWARRE\New Internet Technologies
```

```
HKLM\SOFTWARE\New Internet Technologies\Polices
```

```
HKLM\SOFTWARE\New Internet Technologies\Polices\Exclusions
```

```
HKCU\SOFTWARE\New Internet Technologies
```

```
HKCU\Software\New Internet Technologies\Polices
```

```
HKCU\Software\New Internet Technologies\Polices\Exclusions
```

2. Создаёт ключи реестра с нулевым значением в ветке `Exclusions`:

**HKLM**
```
SystemRoot
pub1
util
dotbin
wwwroot
```

**HKCU**

```
MyDocuments
MyDownloads
MyDesktop

```

(список не окончательный), и оставляет этим ключам значение по-умолчанию: (*0*).

3. Копирует в эти каталоги програму `CheckExclusionsHere`.
4. Запускат эту программу (если она присутствует в каталоге, и антивирус её не блокирует), и проверяет код возврата.
5. Если программа  возвращает исходный код 1, или она не обнаруживается в каталоге (см. п. 4), соответствующий пункт в реестре помечается как 1, и выводится сообщение на консоль.
6. Повторяются пункты **3-5**, до тех пор, пока не будут обработаны все каталоги.
7. Если все каталоги добавлены в исключения, программа возвращает код завершения *0*, в противном случае —*1*.
8. Код завершения *1* можно будет передать в другую программу, которая, например, порекомендует установить необходимые исключения антивируса.
9. Назначенные ключи реестра можно использовать для того, чтобы определить, насколько безопасно можно загружать и запускать программы двойного назначения из указанных каталогов.