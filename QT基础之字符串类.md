[TOC]

标准C++提供了两种字符串：一种是C语言风格的以`"\0"`字符结尾的字符数组；另一类是字符串类`String`。QT字符串类`QString`的功能更强大。`QString`类保存16位Unicode值。



## 操作字符串

（1）`QString`提供一个二元的`"+"`操作符用于组合两个字符串，提供一个`"+="`操作符用于追加一个字符串到另一个字符串的末尾。

```cpp
QString str1 = "Welcome ";
str1 = str1 + "to you!";
QString str2 = "Hello ";
str2 += "World!";
```

**`QString str1 = "Welcome "`** 将一个`const char*`类型的ASCII字符串 `"Welcome"`传递个`QString`,它被解释为一个典型的以`"\0"`结尾的C类型的字符串，这就导致会调用`QString`的构造函数来初始化字符串。

（2）`QString::append()`函数具有同`"+="`操作符相同的功能，在一个字符串的末尾追加另一个字符串

```cpp
QString str1 = "Welcome ";
QString str2 = "to ";
str1.append(str2);
str1.append("you!");
```

```cpp
// QT助手
QString &QString::append(const QString &str)
Appends the string str onto the end of this string.
Example:
 QString x = "free";
 QString y = "dom";

 x.append(y);
 // x == "freedom"
This is the same as using the insert() function:
 x.insert(x.size(), y);
The append() function is typically very fast (constant time), because QString preallocates extra space at the end of the string data so it can grow without reallocating the entire string each time.
```



（3）`QString::sprintf()`函数可用于组合字符串，其支持的格式定义符同C++库中的函数`sprintf()`定义一样。

```cpp
QString str;
str.sprintf("%s","Welcome ");
str.sprintf("%s","to you!");
str.sprintf("%s %s","Welcome ","to you!");
```

```cpp
// QT助手
QString &QString::sprintf(const char *cformat, ...)
This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.
Use asprintf(), arg() or QTextStream instead.
```



（4）`QString::arg()`函数是QT提供的另一种方便的字符串组合方式。相对于`QString::sprintf()`函数，`QString::argue()`函数是类型安全，完全支持Unicode，并且允许改变`"%n"`参数的顺序。

```cpp
QString str;
str = QString("%1 is %2 years old.").arg("Xiaoming").arg(24); // Xiaoming is 24 years old
```

```cpp
// QT助手
QString QString::arg(const QString &a, int fieldWidth = 0, QChar fillChar = QLatin1Char(' ')) const
Returns a copy of this string with the lowest numbered place marker replaced by string a, i.e., %1, %2, ..., %99.
fieldWidth specifies the minimum amount of space that argument a shall occupy. If a requires less space than fieldWidth, it is padded to fieldWidth with character fillChar. A positive fieldWidth produces right-aligned text. A negative fieldWidth produces left-aligned text.
This example shows how we might create a status string for reporting progress while processing a list of files:
 QString i;           // current file's number
 QString total;       // number of files to process
 QString fileName;    // current file's name

 QString status = QString("Processing file %1 of %2: %3")
                 .arg(i).arg(total).arg(fileName);
First, arg(i) replaces %1. Then arg(total) replaces %2. Finally, arg(fileName) replaces %3.
One advantage of using arg() over asprintf() is that the order of the numbered place markers can change, if the application's strings are translated into other languages, but each arg() will still replace the lowest numbered unreplaced place marker, no matter where it appears. Also, if place marker %i appears more than once in the string, the arg() replaces all of them.
If there is no unreplaced place marker remaining, a warning message is output and the result is undefined. Place marker numbers must be in the range 1 to 99.
```



（5）其他字符串组合方法

- `insert()`函数： 在原字符串特定的位置插入另一个字符串。
- `prepend()`函数：在原字符串的开头插入另一个字符串。
- `replace()`函数：用指定的字符串代替原字符串中的某些字符

（6）移除字符串两端的空白（空白字符包括回车符`"\n"`、换行字符`"\r"`、制表符`"\t"`、空格字符`" "`等）

- `QString::trimmed()`函数：移除字符串两端的空白字符

```cpp
// QT助手
QString QString::trimmed() const
Returns a string that has whitespace removed from the start and the end.
Whitespace means any character for which QChar::isSpace() returns true. This includes the ASCII characters '\t', '\n', '\v', '\f', '\r', and ' '.
Example:
 QString str = "  lots\t of\nwhitespace\r\n ";
 str = str.trimmed();
 // str == "lots\t of\nwhitespace"
Unlike simplified(), trimmed() leaves internal whitespace alone.
```



- `QString::simplified()`函数：移除字符串两端的空白字符，使用单个空格字符`" "`代替出现的空白字符

```cpp
// QT助手
QString QString::simplified() const
Returns a string that has whitespace removed from the start and the end, and that has each sequence of internal whitespace replaced with a single space.
Whitespace means any character for which QChar::isSpace() returns true. This includes the ASCII characters '\t', '\n', '\v', '\f', '\r', and ' '.
Example:
 QString str = "  lots\t of\nwhitespace\r\n ";
 str = str.simplified();
 // str == "lots of whitespace";
```



## 查询字符串

（1）`QString::startsWith()`函数判断一个字符串是否以某个字符串开头。第一个参数指定一个字符串，第二个参数指定是否大小写敏感（默认大小写敏感）

```cpp
    QString str = "Welcome to you! ";
    str.startsWith("Welcome", Qt::CaseSensitive); // 返回 true
    str.startsWith("you", Qt::CaseSensitive); // 返回 false
```



```cpp
// QT助手
bool QString::startsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
Returns true if the string starts with s; otherwise returns false.
If cs is Qt::CaseSensitive (default), the search is case sensitive; otherwise the search is case insensitive.
 QString str = "Bananas";
 str.startsWith("Ban");     // returns true
 str.startsWith("Car");     // returns false
```



（2）`QString::endsWith()`函数 判断一个字符串是否以某个字符串结尾

```cpp
// QT助手
bool QString::endsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
Returns true if the string ends with s; otherwise returns false.
If cs is Qt::CaseSensitive (default), the search is case sensitive; otherwise the search is case insensitive.
 QString str = "Bananas";
 str.endsWith("anas");         // returns true
 str.endsWith("pple");         // returns false
```

（3）`QString::contains()`函数 判断指定的字符串是否出现过

```cpp
// QT助手
bool QString::contains(const QString &str, Qt::CaseSensitivity cs = ...) const
Returns true if this string contains an occurrence of the string str; otherwise returns false.
If cs is Qt::CaseSensitive (default), the search is case sensitive; otherwise the search is case insensitive.
Example:
 QString str = "Peter Pan";
 str.contains("peter", Qt::CaseInsensitive);    // returns true
```

（4）比较字符串

操作符`< 、<=、 ==、>=`

函数**`localeAwareCompare(const QString &s1, const QString &s2)`**,静态函数s1小于s2返回负整数，等于返回0，大于返回正整数。比较是基于本地字符集的，平台相关

```cpp
// QT助手
[static] int QString::localeAwareCompare(const QString &s1, const QString &s2)
Compares s1 with s2 and returns an integer less than, equal to, or greater than zero if s1 is less than, equal to, or greater than s2.
The comparison is performed in a locale- and also platform-dependent manner. Use this function to present sorted lists of strings to the user.
On macOS and iOS this function compares according the "Order for sorted lists" setting in the International preferences panel.
```

函数**`compare(const QString &s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)`**

```cpp
// QT助手
[static] int QString::compare(const QString &s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)
Compares s1 with s2 and returns an integer less than, equal to, or greater than zero if s1 is less than, equal to, or greater than s2.
If cs is Qt::CaseSensitive, the comparison is case sensitive; otherwise the comparison is case insensitive.
Case sensitive comparison is based exclusively on the numeric Unicode values of the characters and is very fast, but is not what a human would expect. Consider sorting user-visible strings with localeAwareCompare().
 int x = QString::compare("aUtO", "AuTo", Qt::CaseInsensitive);  // x == 0
 int y = QString::compare("auto", "Car", Qt::CaseSensitive);     // y > 0
 int z = QString::compare("auto", "Car", Qt::CaseInsensitive);   // z < 0
```

## 字符串转换

**转换为数值类型**

`QString::toInt()`、`QString::toDouble()`、`QString::toFloat()`、`QString::toLong()`、`QString::toLongLong()`等

```cpp
// QT助手
int QString::toInt(bool *ok = nullptr, int base = 10) const
Returns the string converted to an int using base base, which is 10 by default and must be between 2 and 36, or 0. Returns 0 if the conversion fails.
If ok is not nullptr, failure is reported by setting *ok to false, and success by setting *ok to true.
If base is 0, the C language convention is used: If the string begins with "0x", base 16 is used; if the string begins with "0", base 8 is used; otherwise, base 10 is used.
The string conversion will always happen in the 'C' locale. For locale dependent conversion use QLocale::toInt()
Example:
 QString str = "FF";
 bool ok;
 int hex = str.toInt(&ok, 16);       // hex == 255, ok == true
 int dec = str.toInt(&ok, 10);       // dec == 0, ok == false
This function ignores leading and trailing whitespace.
```

**转换为其他字符集**

`QString`提供的字符集编码集转换函数将会返回一个`const char*`类型版本的`QByteArray`,即构造函数`QByteArray(const char*)`构造的`QByteArray`对象

```cpp
// QT助手
QByteArray QString::toAscii() const
This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.
Returns an 8-bit representation of the string as a QByteArray.
This function does the same as toLatin1().
Note that, despite the name, this function does not necessarily return an US-ASCII (ANSI X3.4-1986) string and its result may not be US-ASCII compatible.
See also fromAscii(), toLatin1(), toUtf8(), toLocal8Bit(), and QTextCodec.
```





希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！
