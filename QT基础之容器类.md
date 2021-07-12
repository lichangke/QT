[TOC]





QT提供了一组通用的基于模板的容器类。存储在QT容器类中数据必须是可赋值的数据类型，也就是说，这种数据类型必须提供一个默认的构造函数、一个复制构造函数和一个赋值操作运算符。这样的数据类型包含了通常使用的大多数数据类型，包括基本数据类型(如int和double等)和QT的一些数据类型(如QString、QDate和QTime等)，但QT的<font color="red">`QObject`</font>及其他的子类(如<font color="red">`QWidget QDialog`</font>等)不能够存储在容器中，可以存储<font color="red">`QObject`</font>及其他的子类的指针

```cpp
QList<QToolBar> list; // 无法通过编译
QList<QToolBar*> list; // 通过编译
```

QT容器类是可以嵌套的

```cpp
QHash<QString,QList<double>>
```



## QList类、QLinkedList类和QVector类



### QList类

`QList<T>`是最常用的容器类，它存储给定数据类型`T`的一列数值。继承自`QList` 的子类有 `QByteArrayList, QItemSelection, QQueue, and QStringList`等。

`QList<T>`维护了一个指针数组，该数组存储的指针指向`QList<T>`存储的列表项的内容。因此，`QList<T>`支持基于下标的快速访问。

对于不同数据类型，`QList<T>`采取不同的存储策略。

（1）如果`T`是一个指针或者指针大小的基本类型（占用字节数相同），`QList<T>`会将数值直接存储在它的数组中

（2）如果`QList<T>`存储对象的指针，则该指针指向实际存储的对象



### QLinkedList类

`QLinkedList<T>`是一个链式列表，以非连续的内存存储数据，不能使用下标只能使用迭代器访问数据项

### QVector类

`QVector<T>`在相邻的内存中存储给定数据类型`T`的一组数值。在`QVector`的前部或中部位置进行插入操作的速度很慢，因为会存在大量的数据搬移操作。`QLinkedList<T>`既可以使用下标访问数据项，也可以使用迭代器访问数据项。

### STL风格迭代器遍历容器

|          容器类          |            只读迭代器            |         读写迭代器         |
| :----------------------: | :------------------------------: | :------------------------: |
|  `QList<T>`,`QQueue<T>`  |    `QList<T>::const_iterator`    |    `QList<T>::iterator`    |
|     `QLinkedList<T>`     | `QLinkedList<T>::const_iterator` | `QLinkedList<T>::iterator` |
| `QVector<T>`,`QStack<T>` |    QVector<T>::const_iterator    |   `QVector<T>::iterator`   |

GitHub链接： [GitHub ](https://github.com/lichangke/QT/tree/main/CodeDemo/CH2/CH203/STL_Iterator)

```cpp
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<int> list;
    for(int j=0; j<10; j++){
        list.append(j);
    }

    QList<int>::iterator i;
    for(i=list.begin();i!=list.end();++i){
        qDebug() << (*i);
        *i = (*i) * 10;
    }

    QList<int>::const_iterator ci;
    for(ci = list.constBegin();ci!=list.constEnd();++ci){
        qDebug() << (*ci);
    }

    return a.exec();
}
```



## QMap类和QHash类

`QMap`类和`QHash`类具有很多类似的功能，但也有差别：

- `QHash`有比`QMap`更快的查找速度
- `QHash`以任意顺序存储数据项，而`QMap`总是按照键 `Key`的顺序存储数据
- `QHash`的键类型 `Key`必须提供`operator==()`和一个全局的`qHash(Key)`函数，而`QMap`的键类型 `Key`必须提供`operator<=()`函数



### QMap类

`QMap<Key,T>`提供一个从类型为`Key`的键到类型为`T`的值得映射。

### QHash类

`QHash<Key,T>`具有与`QMap`几乎完全相同的API。`QHash`维护一张哈希表，其大小与`QHash`数据项数目相适应

### STL风格迭代器遍历容器

|               容器类                |                          只读迭代器                          |        读写迭代器        |
| :---------------------------------: | :----------------------------------------------------------: | :----------------------: |
|  `QMap<Key,T>`，`QMultiMap<Key,T>`  |                `QMap<Key,T>::const_iterator`                 | `QMap<Key,T>::iterator`  |
| `QHash<Key,T>`，`QMultiHash<Key,T>` | `QHash<Key,T>`，`QMultiHash<Key,T>``QHash<Key,T>::const_iterator` | `QHash<Key,T>::iterator` |

GitHub链接： [GitHub](https://github.com/lichangke/QT/tree/main/CodeDemo/CH2/CH205/STL_Iterator)

```cpp
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMap<QString,QString> map;
    map.insert("abc","123");
    map.insert("def","456");
    map.insert("hij","789");

    QMap<QString,QString>::const_iterator ci;
    for(ci=map.constBegin();ci!=map.constEnd();ci++){
        qDebug() << "Key = " << ci.key() << ", Value = " << ci.value();
    }

    QMap<QString,QString>::iterator i;
    i = map.find("abc");
    if(i!=map.end()){
        i.value() = "000";
    }
    qDebug() << "------------";
    QMap<QString,QString>::const_iterator ci2;
    for(ci2=map.constBegin();ci2!=map.constEnd();ci2++){
        qDebug() << "Key = " << ci2.key() << ", Value = " << ci2.value();
    }

    return a.exec();
}
```





希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！

