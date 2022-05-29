#include "simpletexteditor.h"

#include <QIcon>
#include <QFile>
#include <QDebug>
#include <QStatusBar>
#include <QTextStream>
#include <QTextList>
#include <QApplication>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QColorDialog>
#include <QActionGroup>
#include <QTextBlockFormat>
#include <QTextListFormat>

SimpleTextEditor::SimpleTextEditor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Simple Text Editor"));
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);
    QStatusBar *statusbar = statusBar();
    statusbar->showMessage("欢迎 Welcome");

    // 创建 动作 菜单 工具栏
    CreateActions();
    CreateMenus();
    CreateToolBars();
    // 创建 文本编辑 字体项 工具栏
    CreateFontToolBar();
    // 创建 排版 工具栏 对齐方式和排序方式
    CreateTypesettingToolbar();
}

SimpleTextEditor::~SimpleTextEditor()
{
}

void SimpleTextEditor::CreateActions()
{
    // 文件菜单项
    // 打开
    //创建打开文件动作同时指定图标、名称和父窗口
    openFileAction = new QAction(QIcon(":/open"),tr("打开"),this);
    // 为 打开文件动作 设置组合快捷键
    openFileAction->setShortcut(tr("Ctrl+O"));
    // 设置 状态栏显示 光标移动到这里时 状态栏显示同时
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(OpenFile()));

    // 新建
    newFileAction = new QAction(QIcon(":/new"),tr("新建"),this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction,SIGNAL(triggered()),this,SLOT(NewFile()));

    // 打印
    printFileAction = new QAction(QIcon(":/printText"),tr("打印文本"),this);
    printFileAction->setStatusTip(tr("打印一个文本"));
    connect(printFileAction,SIGNAL(triggered()),this,SLOT(PrintFile()));

    // 退出
    exitAction = new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出 程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    // 编辑菜单项
    // 复制
    copyAction = new QAction(QIcon(":/copy"),tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));

    // 剪切
    cutAction = new QAction(QIcon(":/cut"),tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));

    // 粘贴
    pasteAction = new QAction(QIcon(":/paste"),tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+P"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));

    // 撤销
    undoAction = new QAction(QIcon(":/undo"),tr("撤销"),this);
    undoAction->setShortcut(tr("Ctrl+Z"));
    undoAction->setStatusTip(tr("撤销"));
    connect(undoAction,SIGNAL(triggered()),showWidget->text,SLOT(undo()));

    // 重做
    redoAction = new QAction(QIcon(":/redo"),tr("重做"),this);
    redoAction->setShortcut(tr("Ctrl+Y"));
    redoAction->setStatusTip(tr("重做"));
    connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));

    // 关于
    // 也可不指定图标，通常只在菜单中出现，不在工具栏上显示
    aboutAction = new QAction(tr("关于"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(QApplication::aboutQt()));

    //排序：左对齐、右对齐、居中和两端对齐
    actGrp =new QActionGroup(this);
    leftAction =new QAction(QIcon(":/left"),"左对齐",actGrp);
    leftAction->setCheckable(true);
    rightAction =new QAction(QIcon(":/right"),"右对齐",actGrp);
    rightAction->setCheckable(true);
    centerAction =new QAction(QIcon(":/center"),"居中",actGrp);
    centerAction->setCheckable(true);
    justifyAction =new QAction(QIcon(":/justify"),"两端对齐",actGrp);
    justifyAction->setCheckable(true);
    connect(actGrp,SIGNAL(triggered(QAction*)),this,SLOT(SetAlignment (QAction*)));

}

void SimpleTextEditor::CreateMenus()
{
    // 文件菜单
    // menuBar() 获取主窗口的菜单栏指针
    // addMenu() 向菜单栏中插入一个新菜单
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction); // 插入菜单项
    fileMenu->addAction(newFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // 编辑菜单项
    editMenu = menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(copyAction); // 插入菜单项
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    fileMenu->addSeparator();
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    fileMenu->addSeparator();
    editMenu->addAction(aboutAction);
}

void SimpleTextEditor::CreateToolBars()
{
    // 文件 工具栏
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(openFileAction);
    fileToolBar->addAction(newFileAction);
    fileToolBar->addAction(printFileAction);

    // 编辑 工具栏
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(copyAction);
    editToolBar->addAction(cutAction);
    editToolBar->addAction(pasteAction);

    // undo redo 工具栏
    doToolBar = addToolBar(tr("UndoRedo"));
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);
}

void SimpleTextEditor::NewFile()
{
    SimpleTextEditor *newsimpleTextEditor = new SimpleTextEditor();
    newsimpleTextEditor->show();
}

void SimpleTextEditor::OpenFile()
{
    fileName = QFileDialog::getOpenFileName(this,tr("Open file dialog"),tr("D:\\"));// 可以限制下文件类型
    if(!fileName.isEmpty()){
        // 判断当前中心部件是否已有文件打开
        if(showWidget->text->document()->isEmpty()){
            LoadFile(fileName); // 加载文件
        } else {
            // 新建加载
            SimpleTextEditor *newsimpleTextEditor = new SimpleTextEditor();
            newsimpleTextEditor->show();
            newsimpleTextEditor->LoadFile(fileName);
        }
    }
}

void SimpleTextEditor::PrintFile()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec()){
        // 获取 QTextEdit 对象的文档
        QTextDocument *doc = showWidget->text->document();
        doc->print(&printer);
    }
}
// 设置字体
void SimpleTextEditor::SetFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    SetTextCharFormat(fmt);
}
// 设置字号
void SimpleTextEditor::SetSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
// 设置文字加粗
void SimpleTextEditor::SetBoldBtn()
{
    QTextCharFormat fmt;
    if(boldBtn->isChecked()){
        fmt.setFontWeight(QFont::Bold);
    } else {
        fmt.setFontWeight(QFont::Normal);
    }
    showWidget->text->mergeCurrentCharFormat(fmt);
}
// 设置文字斜体
void SimpleTextEditor::SetItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
// 设置文字下划线
void SimpleTextEditor::SetUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
// 设置文字颜色
void SimpleTextEditor::SetColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
    if(color.isValid()){ // 可用
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void SimpleTextEditor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    // 字体
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    // 字号
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    // 是否 加粗
    boldBtn->setChecked(fmt.font().bold());
    // 是否 斜体
    italicBtn->setChecked(fmt.font().italic());
    // 是否 下划线
    underlineBtn->setChecked(fmt.font().underline());
}

void SimpleTextEditor::SetAlignment(QAction *act)
{
    // 通过 setAlignment 设置当前段落对齐方式
    if(act==leftAction) {  // 左对齐
        showWidget->text->setAlignment(Qt::AlignLeft);
    }
    if(act==rightAction) { // 右对齐
        showWidget->text->setAlignment(Qt::AlignRight);
    }
    if(act==centerAction) { // 居中对齐
        showWidget->text->setAlignment(Qt::AlignCenter);
    }
    if(act==justifyAction) { // 两端对齐
        showWidget->text->setAlignment(Qt::AlignJustify);
    }
}

void SimpleTextEditor::SetList(int index)
{
    //获得编辑框的QTextCursor对象指针
    QTextCursor cursor=showWidget->text->textCursor();
    if(index!=0) { // 不是选择 Standard
        QTextListFormat::Style style=QTextListFormat::ListDisc;
        switch(index) {  //设置style属性值
        case 1:{
            style=QTextListFormat::ListDisc;
            break;
        }
        case 2: {
            style=QTextListFormat::ListCircle;
            break;
        }
        case 3:{
            style=QTextListFormat::ListSquare;
            break;
        }
        case 4:{
            style=QTextListFormat::ListDecimal;
            break;
        }
        case 5:{
            style=QTextListFormat::ListLowerAlpha;
            break;
        }
        case 6:{
            style=QTextListFormat::ListUpperAlpha;
            break;
        }
        case 7:{
            style=QTextListFormat::ListLowerRoman;
            break;
        }
        case 8:{
            style=QTextListFormat::ListUpperRoman;
            break;
        }
        default:
            break;
        }
        /* 设置缩进值 */
        // beginEditBlock 和 endEditBlock 成对出现
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt=cursor.blockFormat();
        QTextListFormat listFmt;
        if(cursor.currentList()) { // 存在
            listFmt = cursor.currentList()->format(); // 列表的格式
        } else {
            // 如果没有  则列表缩进值 + 1
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0); //
            cursor.setBlockFormat(blockFmt); // 设置块格式
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    } else {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(0); // 设置格式对象的对象索引；
        cursor.mergeBlockFormat(bfmt); // 合并当前块格式
    }
}

void SimpleTextEditor::ShowCursorPositionChanged()
{
    if(showWidget->text->alignment()==Qt::AlignLeft) {
        leftAction->setChecked(true);
    }
    if(showWidget->text->alignment()==Qt::AlignRight) {
        rightAction->setChecked(true);
    }
    if(showWidget->text->alignment()==Qt::AlignCenter) {
        centerAction->setChecked(true);
    }
    if(showWidget->text->alignment()==Qt::AlignJustify) {
        justifyAction->setChecked(true);
    }
    QTextListFormat listFmt;
    QTextCursor cursor=showWidget->text->textCursor();
    QString text = "Standard";
    if(cursor.currentList()) { // 存在
        listFmt = cursor.currentList()->format(); // 列表的格式
        QTextListFormat::Style style = listFmt.style();
        switch(style) {  //设置style属性值
        case QTextListFormat::ListDisc:{
            text = "QTextListFormat::ListDisc";
            break;
        }
        case QTextListFormat::ListCircle: {
            text = "QTextListFormat::ListCircle";
            break;
        }
        case QTextListFormat::ListSquare:{
            text = "QTextListFormat::ListSquare";
            break;
        }
        case QTextListFormat::ListDecimal:{
            text = "QTextListFormat::ListDecimal";
            break;
        }
        case QTextListFormat::ListLowerAlpha:{
            text = "QTextListFormat::ListLowerAlpha";
            break;
        }
        case QTextListFormat::ListUpperAlpha:{
            text = "QTextListFormat::ListUpperAlpha";
            break;
        }
        case QTextListFormat::ListLowerRoman:{
            text = "QTextListFormat::ListLowerRoman";
            break;
        }
        case QTextListFormat::ListUpperRoman:{
            text = "QTextListFormat::ListUpperRoman";
            break;
        }
        default:
            text = "Standard";
            break;
        }
    }
    listComboBox->setCurrentIndex(listComboBox->findText(text));
}

void SimpleTextEditor::LoadFile(QString fileName)
{
    qDebug() << tr("Load file : ") << fileName;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textStream(&file);
        // 注打开文本需要为 UTF-8
        textStream.setCodec("UTF-8");//设置文件流编码方式, 否则可能会乱码
        while(!textStream.atEnd()){
            showWidget->text->append(textStream.readLine());
        }
        qDebug() << tr("Read file end");
    }
}

void SimpleTextEditor::CreateFontToolBar()
{
    // 设置 字体
    fontLabel1 =new QLabel(tr("字体:"));
    fontComboBox =new QFontComboBox;
    // 调用 QFontComboBox 的 setFontFilters 接口可过滤只在下拉列表框中显示某一类字体
    // 默认情况下为 QFontComboBox::AllFonts 列出所有字体。
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts); // ScalableFonts 显示可缩放字体

    // 设置 字号
    fontLabel2 =new QLabel(tr("字号:"));
    sizeComboBox =new QComboBox;
    QFontDatabase db; // QFontDatabase 表示系统所有可用的格式信息，主要是字体和字号
    // standardSizes 返回可用标准字号列表
    foreach(int size,db.standardSizes()){
        sizeComboBox->addItem(QString::number(size));
    }
    // 设置 加粗
    boldBtn =new QToolButton;
    boldBtn->setIcon(QIcon(":/bold"));
    boldBtn->setCheckable(true);

    // 设置 斜体
    italicBtn =new QToolButton;
    italicBtn->setIcon(QIcon(":/italic"));
    italicBtn->setCheckable(true);

    // 设置 下划线
    underlineBtn =new QToolButton;
    underlineBtn->setIcon(QIcon(":/underline"));
    underlineBtn->setCheckable(true);

    // 设置 颜色
    colorBtn =new QToolButton;
    colorBtn->setIcon(QIcon(":/color"));
    colorBtn->setCheckable(true);

    // 事件关联
    // 设置 字体
    connect(fontComboBox,SIGNAL(activated(QString)),
        this,SLOT(SetFontComboBox(QString)));
    // 设置 字号
    connect(sizeComboBox,SIGNAL(activated(QString)),
        this,SLOT(SetSizeSpinBox(QString)));
    // 设置 加粗
    connect(boldBtn,SIGNAL(clicked()),this,SLOT(SetBoldBtn()));
    // 设置 斜体
    connect(italicBtn,SIGNAL(clicked()),this,SLOT(SetItalicBtn()));
    // 设置 下划线
    connect(underlineBtn,SIGNAL(clicked()),this,SLOT(SetUnderlineBtn()));
    // 设置 颜色
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(SetColorBtn()));
    // 根据光标处字体格式 变化刷新 工具上的显示
    // 注意 currentCharFormatChanged 信号的参数
    connect(showWidget->text,SIGNAL(currentCharFormatChanged(const QTextCharFormat &)),this,SLOT(ShowCurrentFormatChanged(const QTextCharFormat&)));

    // 字体 工具条
    fontToolBar =addToolBar("Font");
    fontToolBar->addWidget(fontLabel1); // 设置 字体
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2); // 设置 字号
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn); // 设置 加粗
    fontToolBar->addWidget(italicBtn); // 设置 斜体
    fontToolBar->addWidget(underlineBtn); // 设置 下划线
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);   // 设置 颜色
}

void SimpleTextEditor::SetTextCharFormat(QTextCharFormat format)
{
    // 获取 编辑框中的光标
    QTextCursor cursor = showWidget->text->textCursor();

    if(!cursor.hasSelection()){ // 判断是否有选择 区域
        // 没有 就选取所在词作为选取 由前后 空格或， . 等标点符号区分词
        cursor.select(QTextCursor::WordUnderCursor);
        /*
        enum SelectionType {
            WordUnderCursor, // 选择光标下的单词。 如果光标不在可选字符的字符串中，则不选择文本。
            LineUnderCursor,	// 选择光标下的文本行。
            BlockUnderCursor, // 选择光标下的文本块。
            Document 		 // 选择整个文档。
        };
        */

    }
    cursor.mergeCharFormat(format); // 将格式应用到光标所在区域
    showWidget->text->mergeCurrentCharFormat(format); // 将格式应用到cursor选区内所有字符上
}

void SimpleTextEditor::CreateTypesettingToolbar()
{
    listLabel = new QLabel(tr("排序"));
    listComboBox = new QComboBox;
    // 排序方式 列表 参见 QT帮助手册
    listComboBox->addItem("Standard"); // 不设置
    listComboBox->addItem("QTextListFormat::ListDisc"); // 一个实心圆圈
    listComboBox->addItem("QTextListFormat::ListCircle"); // 一个空心圆圈
    listComboBox->addItem("QTextListFormat::ListSquare"); // 一个实心正方形
    listComboBox->addItem("QTextListFormat::ListDecimal"); // 按升序排列的十进制值
    listComboBox->addItem("QTextListFormat::ListLowerAlpha"); // 按降序的拉丁字母
    listComboBox->addItem("QTextListFormat::ListUpperAlpha"); // 按升序的拉丁字母
    listComboBox->addItem("QTextListFormat::ListLowerRoman"); // 按降序的罗马字母
    listComboBox->addItem("QTextListFormat::ListUpperRoman"); // 按升序的罗马字母

    // 事件关联
    // 设置列表
    connect(listComboBox,SIGNAL(activated(int)),this,SLOT(SetList(int)));
    // 光标位置发生变化 刷新 排版工具栏的显示, 例如 是否使能对齐按钮
    connect(showWidget->text,SIGNAL(cursorPositionChanged()),
          this,SLOT(ShowCursorPositionChanged()));
    // 是否使能 undo redo 按钮
    connect(showWidget->text->document(),SIGNAL(undoAvailable(bool)),
          redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text->document(),SIGNAL(redoAvailable(bool)),
          redoAction,SLOT(setEnabled(bool)));

    // 排版工具条
    // 排列方式
    listToolBar =addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    // 对齐方式
    listToolBar->addActions(actGrp->actions());

}

