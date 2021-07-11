[TOC]

# Main.cpp

使用QT Creator 新建工程(基类选择 QDialog 为例)后会生成一个默认的main.cpp文件

```cpp
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
```



**#include "dialog.h"**

包含程序中要完成功能的Dialog类的定义，在Dialog类中封装完成所需要的功能。

**#include <QApplication>**

每个使用QT图形化应用程序中都必须使用一个QApplication对象。QApplication管理各种各样的图形化应用程序的广泛资源、基本设置、控制流以及事件处理等。

**int main(int argc, char *argv[])**

应用程序的如空，几乎在所有使用QT的情况下，main()函数只需要在将控制转交给QT库之前执行初始化，然后QT库通过事件向程序告知用户的行为。所有QT程序中都必须有且只有一个main()函数。`argc` 命令行变量的数量，` *argv[]` 命令行变量的数组。

**QApplication a(argc, argv)**

a是 程序的 QApplication  对象。QApplication  对象必须在任何QT窗口系统部件被使用之前创建。

**w.show();**

创建的窗口部件必须调用show()函数使其可见，默认它是不可见的。

**return a.exec();**

程序进入消息循环，等待可能的输入进行响应。main()函数在此将控制权转交给QT。在 exec() 中QT接收并处理用户和系统的事件并且将它们传递给适当的窗口部件。



希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！
