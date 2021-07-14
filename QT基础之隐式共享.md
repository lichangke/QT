[TOC]



更多参见
[QT基础与实例应用目录](https://blog.csdn.net/leacock1991/article/details/118662440)



隐式共享又称为`copy on write`回写复制。当两个对象共享同一份数据（浅拷贝实现数据块的共享）时，如果数据不变就不进行数据的复制，而当某个对象需要改变数据时则执行深拷贝。

- 深拷贝 ： 即就是生成对象的一个完整的复制品；

- 浅拷贝：只是一个引用复制(比如仅仅复制指向共享数据的指针)。

隐式共享可以降低对内存和CPU资源的使用，提高程序的运行效率。使用隐式共享能使得在函数中(eg. 参数、返回值)使用值传递更有效率。 QString采用隐式共享技术，将深拷贝和浅拷贝很好地结合了起来。



```cpp
    QString str1 = "ubuntu";
    QString str2 = str1; //  发生一次浅拷贝 str1 str2指向同一个数据结构，引用计数器值为2
    qDebug() << "str1 = " << str1;  // str1 =  "ubuntu"
    qDebug() << "str2 = " << str2;  // str2 =  "ubuntu"

    // 对 QString对象str2修改导致一次深拷贝，str2指向一个新的与str1指向不同的数据结构其引用计数值为1，str1指向的数据结构引用计数器值减1后为1
    str2[2] = 'm';
    str2[0] = 'o';
    qDebug() << "str1 = " << str1;  // str1 =  "ubuntu"
    qDebug() << "str2 = " << str2;  // str2 =  "obmntu"

    // str2赋值给str1，str1原指向的数据结构的引用数修改为0，也就是没有对象使用这个数据结构会从内存中释放
    // 操作结束后，str1 str2  指向同一个数据结构，引用计数器值为2
    str1 = str2;
    qDebug() << "str1 = " << str1;  // str1 =  "obmntu"
    qDebug() << "str2 = " << str2;  // str2 =  "obmntu"
```



QT中支持隐式共享的类还包括：

- 所有的容器类
- `QByteArray、 QBrush、QDir、 QBitmap、QPen、QImage、QCursor、QFont、QVariant`等



参见：

[0016：Qt中的隐式共享](https://blog.csdn.net/newboy686/article/details/90183904)

[Qt 中的隐式共享以及如何写一个隐式共享类](https://zhuanlan.zhihu.com/p/45354267)




希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！

