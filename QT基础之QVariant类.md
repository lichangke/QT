[TOC]



更多参见
[QT基础与实例应用目录](https://blog.csdn.net/leacock1991/article/details/118662440)



QVariant类类似于C++的联合数据类型，既可以保存很多QT类型的值，包括QColor、QBrush、QFont、QPen、QRect、QString和QSize等，也可以存放QT容器类型值

GitHub链接 ：[GitHub](https://github.com/lichangke/QT/tree/main/CodeDemo/CH2/CH206/myVariant)

```cpp
    QVariant v{709};
    qDebug()<<v.toInt(); // 709

    QVariant w{"Hello World"};
    qDebug()<<w; // QVariant(QString, "Hello World")
    qDebug()<<w.toString(); // "Hello World"

    QMap<QString,QVariant>map{{"int",709},{"double",3.14}};
    map["string"] = "Hello World";
    map.insert("color",QColor(255,0,0));
    // 调用相应的转换函数
    qDebug()<<map["int"]<<map["int"].toInt(); // QVariant(int, 709) 709
    qDebug()<<map["double"]<<map["double"].toDouble(); // QVariant(double, 3.14) 3.14
    qDebug()<<map["string"]<<map["string"].toString(); // QVariant(QString, "Hello World") "Hello World"
    qDebug()<<map["color"]<<map["color"].value<QColor>(); // QVariant(QColor, QColor(ARGB 1, 1, 0, 0)) QColor(ARGB 1, 1, 0, 0)

    QStringList sl;
    sl << "A" << "B" << "C" << "D";
    QVariant vt{sl};

    if(vt.type()==QVariant::StringList) {
        auto list = vt.toStringList();
        for (int i=0;i<list.size();++i ) {
            qDebug()<<list.at(i);
        }
    }

```

[C++的各种初始化方式](https://stephan14.github.io/2019/08/10/various-initialization-methods-for-C++/)

`qDebug()<<map["color"]<<map["color"].value<QColor>();` `QVariant`变量中保存了一个`QColor`对象，并使用模板`QVariant::value()`还原为`QColor`。 `QVariant`是`QtCOre`模块的类，没有为`QtGui`模块中的数据类型，比如`QColor`、`QImage`、`QPixmap`等提供转换函数，需要使用`QVariant::value()`或者`QVariantValue()`

`QVariant::type()`函数返回存储在`QVariant`变量中的值得数据类型。`QVariant::StringList`是一个`QVariant::type()`枚举类型的变量。

这个枚举可以查看源码`qvariant.h`

```cpp
    enum Type {
        Invalid = QMetaType::UnknownType,
        Bool = QMetaType::Bool,
        Int = QMetaType::Int,
        UInt = QMetaType::UInt,
        LongLong = QMetaType::LongLong,
        ULongLong = QMetaType::ULongLong,
        Double = QMetaType::Double,
        Char = QMetaType::QChar,
        Map = QMetaType::QVariantMap,
        List = QMetaType::QVariantList,
        String = QMetaType::QString,
        StringList = QMetaType::QStringList,
        ByteArray = QMetaType::QByteArray,
        BitArray = QMetaType::QBitArray,
        Date = QMetaType::QDate,
        Time = QMetaType::QTime,
        DateTime = QMetaType::QDateTime,
        Url = QMetaType::QUrl,
        Locale = QMetaType::QLocale,
        Rect = QMetaType::QRect,
        RectF = QMetaType::QRectF,
        Size = QMetaType::QSize,
        SizeF = QMetaType::QSizeF,
        Line = QMetaType::QLine,
        LineF = QMetaType::QLineF,
        Point = QMetaType::QPoint,
        PointF = QMetaType::QPointF,
        RegExp = QMetaType::QRegExp,
        RegularExpression = QMetaType::QRegularExpression,
        Hash = QMetaType::QVariantHash,
        EasingCurve = QMetaType::QEasingCurve,
        Uuid = QMetaType::QUuid,
#if QT_CONFIG(itemmodel)
        ModelIndex = QMetaType::QModelIndex,
        PersistentModelIndex = QMetaType::QPersistentModelIndex,
#endif
        LastCoreType = QMetaType::LastCoreType,

        Font = QMetaType::QFont,
        Pixmap = QMetaType::QPixmap,
        Brush = QMetaType::QBrush,
        Color = QMetaType::QColor,
        Palette = QMetaType::QPalette,
        Image = QMetaType::QImage,
        Polygon = QMetaType::QPolygon,
        Region = QMetaType::QRegion,
        Bitmap = QMetaType::QBitmap,
        Cursor = QMetaType::QCursor,
        KeySequence = QMetaType::QKeySequence,
        Pen = QMetaType::QPen,
        TextLength = QMetaType::QTextLength,
        TextFormat = QMetaType::QTextFormat,
        Matrix = QMetaType::QMatrix,
        Transform = QMetaType::QTransform,
        Matrix4x4 = QMetaType::QMatrix4x4,
        Vector2D = QMetaType::QVector2D,
        Vector3D = QMetaType::QVector3D,
        Vector4D = QMetaType::QVector4D,
        Quaternion = QMetaType::QQuaternion,
        PolygonF = QMetaType::QPolygonF,
        Icon = QMetaType::QIcon,
        LastGuiType = QMetaType::LastGuiType,

        SizePolicy = QMetaType::QSizePolicy,

        UserType = QMetaType::User,
        LastType = 0xffffffff // need this so that gcc >= 3.4 allocates 32 bits for Type
    };
```







希望我的文章对于大家有帮助，由于个人能力的局限性，文中可能存在一些问题，欢迎指正、补充！

