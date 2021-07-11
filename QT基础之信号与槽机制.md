[TOC]



QT提供了信号与槽机制用于完成界面操作的响应，信号与槽机制是完成任意两个QT对象之间的通信机制。

**信号（Signal）** 就是在特定情况下被发射的事件，例如PushButton 最常见的信号就是鼠标单击时发射的 clicked() 信号，一个 ComboBox 最常见的信号是选择的列表项变化时发射的 CurrentIndexChanged() 信号。GUI 程序设计的主要内容就是对界面上各组件的信号的响应，只需要知道什么情况下发射哪些信号，合理地去响应和处理这些信号就可以了。

**槽（Slot）** 就是对信号响应的函数。槽就是一个函数，与一般的C++函数是一样的，可以定义在类的任何部分（public、private 或 protected），可以具有任何参数，也可以被直接调用。槽函数与一般的函数不同的是：槽函数可以与一个信号关联，当信号被发射时，关联的槽函数被自动执行。



## 信号与槽机制的连接方式

- **基本格式**

```cpp
connect(Object1,SIGNAL(signal1),Object2,SLOT(slot2));
```

- **一个信号可以和另一个信号相连**

```cpp
connect(Object1,SIGNAL(signal1),Object2,SIGNAL(signal2));
```

Object1的信号1发送可以触发Object2的信号2发送



- **同一个信号可以和多个槽相连**

```cpp
connect(Object1,SIGNAL(signal1),Object2,SLOT(slot2));
connect(Object1,SIGNAL(signal1),Object3,SLOT(slot3));
```

- **同一个槽可以响应多个信号**

```cpp
connect(Object2,SIGNAL(signal2),Object1,SLOT(slot1));
connect(Object3,SIGNAL(signal3),Object1,SLOT(slot1));
```

SIGNAL（） 和 SLOT（）是Qt定义的两个宏，它们返回其参数的C语言风格的字符串（const char*）。因此，下面关联的信号和槽的两个语句是等同的：

```
connect(buttoon, SIGNAL(clicked（）), this, SLOT(showArea（）));
connect(buttoon, "clicked（）", this, "showArea（）");
```

## 信号与槽机制的优点

- **类型安全**

关联的信号与槽的签名必须是等同的，也就是信号的参数类型和参数个数与接收该信号的槽的参数类型和参数个数相同。不过槽的参数个数可以少于信号的参数个数，但是缺少的参数必须是信号参数的最后一个或多个。

- **松耦合**

信号和槽机制减弱了QT对象的耦合度。激发信号的对象无须知道是哪些对象的哪些槽需要对其相应，也不关心信号有没有被接收到。同样的槽也不知道哪些信号关联了自己。一旦关联信号和槽，QT就保证了适合的槽得到了调用。

一个类若要支持信号和槽，就必须从QObject或QObject的之类继承。信号和槽不支持对模板的使用。

## 信号与槽机制的效率

信号与槽机制增强了对象间通信的灵活性，这也损失了一些性能主要原因如下，但是相比之下这点性能损失是值得的

- 需要定位接收信号的对象
- 安全地遍历所有的关联（一个信号对多个槽）
- 编组与解组传递的参数
- 在多线程时，信号可能需要排队






希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！
