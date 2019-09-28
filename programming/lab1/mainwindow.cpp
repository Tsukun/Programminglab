#include "mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    {
        //создание текстовой области
        textEdit = new QPlainTextEdit;
        //установим его в качестве центрального виджета
        /*и нам уже не надо думать о его размерах, поведении при
    растяжении/сжатии формы и т.д. */
        setCentralWidget(textEdit);
        /*когда логически обособленные части вынесены в отдельный
    функции, код смотрится чище*/
        createActions();
        createMenus();
        createToolBars();
        createStatusBar();
        readSettings();
        // при изменении текста в документе, открытом в объекте
        // textEdit, высылается сигнал
        // соединим его со слотом главного окна
        connect(textEdit->document(),
                SIGNAL(contentsChanged()),this,
                SLOT(documentWasModified()));
        // изначально никакой файл не открыт
        setCurrentFile("");

    }


}
void MainWindow::closeEvent(QCloseEvent *event)
{
    // здесь перехвачено событие "закрытие окна"
    // чтобы пользователь не потерял данные, дадим ему
    // возможность отменить закрытие
    // либо сохранить данные (если есть несохраненные)
    if (maybeSave()) {
        writeSettings();
        /*пускаем событие дальше (оно попадет в метод базового
класса и приложение будет закрыто)*/
        event->accept();
    }
    else {
        event->ignore();//игнорируем событие (приложение закрыто
        // не будет)
    }
}

void MainWindow::newFile()
{
    /* здесь также нужно узнать, не хочет ли пользователь
сохранить
текущий документ перед созданием нового */
    if (maybeSave()) {//если можно сохранить, очищаем поле
        // текста
        textEdit->clear();
        setCurrentFile("");//для нового документа файл еще не
        // выбран
    }
    //иначе ничего не выполняем, пользователь продолжит
    // работу с текущим документом
}
void MainWindow::open()
{
    if (maybeSave()) { /*вызов диалогового окна выбора файла
(изучите параметры функции getOpenFileName
самостоятельно)*/
        QString fileName =
                QFileDialog::getOpenFileName(this,tr("Открыть файл"));
        if (!fileName.isEmpty())//пользователь может и не выбрать файл
                    loadFile(fileName);//если выбрал - открыть его
    }
}
bool MainWindow::save()
{
    if (isUntitled ) {/*если документ еще не был связан с
файлом,
пользователь должен его выбрать или создать новый*/
        return saveAs();
    } else {//иначе просто сохранить в соответствующий файл
        return saveFile(curFile);
    }
}
bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Сохранить как"), curFile);
    if (fileName.isEmpty())
        return false;//файл не выбран
    return saveFile(fileName);
}
void MainWindow::about()
{
    //для простого редактора не будем создавать отдельное окно
    //хватит и простого сообщения
    //tr() нужно для правильного вывода текста на различных языках
    QMessageBox::about(this, tr("О программе"),
                       tr("<b>Приложение</b> демонстрирует, как "
                          "создавать современные <B><I><font color= red>графические пользовательские интерфейсы</I></B> для программ, с основными элементами главного окна приложения: меню, панелью инструментов, строкой состояния."));
    //можно поэкспериментировать с html тэгами для изменения шрифта, размера, цвета
}
void MainWindow::documentWasModified()
{
    //если документ был действительно изменен, это будет учтено в приложении
    setWindowModified(textEdit->document()->isModified());
}


void MainWindow::createActions()
{
newAct = new QAction(QIcon(":/images/new.png"),
tr("&Новый"), this);
newAct->setShortcuts(QKeySequence::New);
newAct->setStatusTip(tr("Создать новый файл"));
//но QAction сам по себе ничего не делает, а лишь вызывает нужные методы
//так повышается гибкость, уровень абстракции и модульность
connect(newAct, SIGNAL(triggered()), this,
SLOT(newFile()));
openAct = new QAction(QIcon(":/images/open.png"),
tr("&Открыть..."), this);
openAct->setShortcuts(QKeySequence::Open);
openAct->setStatusTip(tr("Открыть существующий файл"));
connect(openAct, SIGNAL(triggered()), this,
SLOT(open()));
saveAct = new QAction(QIcon(":/images/save.png"),
tr("&Сохранить"), this);
saveAct->setShortcuts(QKeySequence::Save);
saveAct->setStatusTip(tr("Сохранить документ"));
connect(saveAct, SIGNAL(triggered()), this,
SLOT(save()));
saveAsAct = new QAction(tr("Сохранить &как..."), this);
saveAsAct->setShortcuts(QKeySequence::SaveAs);
saveAsAct->setStatusTip(tr("Сохранить документ под новым именем"));
connect(saveAsAct, SIGNAL(triggered()), this,
SLOT(saveAs()));
exitAct = new QAction(tr("&Выход"), this);
exitAct->setShortcuts(QKeySequence::Quit);
exitAct->setStatusTip(tr("Выйти из приложения"));
connect(exitAct, SIGNAL(triggered()), this,
SLOT(close()));
cutAct = new QAction(QIcon(":/images/cut.png"),
tr("Выре&зать"), this);
cutAct->setShortcuts(QKeySequence::Cut);
cutAct->setStatusTip(tr("Вырезать выделенный фрагмент и поместить в буффер"));
connect(cutAct, SIGNAL(triggered()), textEdit,
SLOT(cut()));
copyAct = new QAction(QIcon(":/images/copy.png"),
tr("&Копировать"), this);
copyAct->setShortcuts(QKeySequence::Copy);
copyAct->setStatusTip(tr("Копировать выделенный фрагмент и поместить в буффер"));
connect(copyAct, SIGNAL(triggered()), textEdit,
SLOT(copy()));
pasteAct = new QAction(QIcon(":/images/paste.png"),
tr("&Вставить"), this);
pasteAct->setShortcuts(QKeySequence::Paste);
pasteAct->setStatusTip(tr("Вставить фрагмент из буффера"));
connect(pasteAct, SIGNAL(triggered()), textEdit,
SLOT(paste()));
aboutAct = new QAction(tr("&О программе"), this);
connect(aboutAct, SIGNAL(triggered()), this,
SLOT(about()));
aboutQtAct = new QAction(tr("О &Qt"), this);
//qApp - указатель на приложение
//aboutQt - слот для вывода сообщения с кратким описанием Qt
connect(aboutQtAct, SIGNAL(triggered()), qApp,
SLOT(aboutQt()));
//действия "Копировать" и "Вырезать" доступны (разрешены) не всегда
cutAct->setEnabled(false);
copyAct->setEnabled(false);
//они разрешены, только если выделен фрагмент текста в textEdit
//если такой фрагмент есть - textEdit сам сообщит об этом
connect(textEdit, SIGNAL(copyAvailable(bool)),
cutAct, SLOT(setEnabled(bool)));
connect(textEdit, SIGNAL(copyAvailable(bool)),
copyAct, SLOT(setEnabled(bool)));
//сигнал copyAvailable(bool) несет, как видно, логическую переменну,
//слоты setEnabled(bool) и setEnabled(bool) ее принимают и реагируеют на нее
}

void MainWindow::createMenus()
{ //создание пунка меню верхнего уровня
fileMenu = menuBar()->addMenu(tr("&Файл")); //menuBar является членом класса QMainWindow
fileMenu->addAction(newAct);// действия сами превратятся в пункты меню нижнего уровня
fileMenu->addAction(openAct);
fileMenu->addAction(saveAct);
fileMenu->addAction(saveAsAct);
fileMenu->addSeparator();
fileMenu->addAction(exitAct);
editMenu = menuBar()->addMenu(tr("&Правка"));
editMenu->addAction(cutAct);
editMenu->addAction(copyAct);
editMenu->addAction(pasteAct);
menuBar()->addSeparator();//разделитель
helpMenu = menuBar()->addMenu(tr("&Помощь"));
helpMenu->addAction(aboutAct);
helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{ //панель инструментов создается аналогично меню
fileToolBar = addToolBar(tr("Файл"));
fileToolBar->addAction(newAct);
fileToolBar->addAction(openAct);
fileToolBar->addAction(saveAct);
editToolBar = addToolBar(tr("Правка"));
editToolBar->addAction(cutAct);
editToolBar->addAction(copyAct);
editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBar()
{ //начально сообщение о готовности работы
statusBar()->showMessage(tr("Готово"));
}
void MainWindow::readSettings() {//чтение из реестра
QSettings settings("QtProgramming", "MyEditor");//пусть к настройкам
bool max= settings.value("ismaximized", 0).toInt();
if(max) {//окно нужно развернуть
this->setWindowState(Qt::WindowMaximized);
}
else {//иначе нужно использовать предыдущий размер и положение
QSize size = settings.value("size", QSize(400,
400)).toSize();
QPoint pos = settings.value("position", QPoint(200,
200)).toPoint();
resize(size);//изменить размер
move(pos);//переместить окно
}
}
void MainWindow::writeSettings() { //сохранение позиции и размера в реестре
QSettings settings("QtProgramming", "MyEditor");
if(this->windowState()==Qt::WindowMaximized) {
//если окно занимает весь экран, то нет смысла сохранять позицию и размер
settings.setValue("ismaximized", 1);
}
else {
settings.setValue("ismaximized", 0);
settings.setValue("position ", pos());
settings.setValue("size", size());
}
}

bool MainWindow::maybeSave()
{
//если были изменения, вывод окна с тремя вариантами выбора
if (textEdit->document()->isModified()) {
int ret = QMessageBox::warning(this, tr("Редактор"),
tr("Документ был изменен.\n Хотите сохранить изменения?"),tr("Да"),tr("Нет"),tr("Отмена"));
if (ret == 0) return save();
else if (ret == 2) return false;
}
return true;
//все функции, связанные с сохранением, возвращают true/false,
//так как в каждой из них может произойти отказ пользователя от сохранения
}
void MainWindow::loadFile(const QString &fileName)
{
QFile file(fileName);//объект для чтения/записи файлов
if (!file.open(QFile::ReadOnly | QFile::Text)) {
QMessageBox::warning(this, tr("Редактор"),
tr("Не удалось прочитать файл %1:\n%2.").arg(fileName).arg(file.errorString()),
QMessageBox::Ok);
return;
}
QTextStream in(&file);//текстовый поток для чтения
/*директивы препроцессов часто используют в Qt, чтобы
учесть
особенности операционных систем, например, в мобильных
устройствах с сенсорным экраном не нужен значок курсора*/
#ifndef QT_NO_CURSOR
QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
textEdit->setPlainText(in.readAll());//все содержимое файла
#ifndef QT_NO_CURSOR
QApplication::restoreOverrideCursor();
#endif
setCurrentFile(fileName);//имя текущего файла поменялось
statusBar()->showMessage(tr("Файл загружен"),
2000);//сообщение на 2 секунды
}
//аналогично происходит запись файла
bool MainWindow::saveFile(const QString &fileName)
{
QFile file(fileName);
if (!file.open(QFile::WriteOnly | QFile::Text)) {
QMessageBox::warning(this, tr("Редактор"),
tr("Не удалось записать файл%1:\n%2.").arg(fileName).arg(file.errorString()),
QMessageBox::Ok);
return false;
}
QTextStream out(&file);//поток для записи
#ifndef QT_NO_CURSOR
QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
out << textEdit->toPlainText();
#ifndef QT_NO_CURSOR
QApplication::restoreOverrideCursor();
#endif
setCurrentFile(fileName);
statusBar()->showMessage(tr("Файл сохранен"), 2000);
return true;
}
void MainWindow::setCurrentFile(const QString &fileName)
{
static int sequenceNumber = 1;//счетчик безымянных файлов
if(fileName.isEmpty()) {
curFile = tr("Безымяный%1.txt").arg(sequenceNumber++);
isUntitled = true;
}
else {
curFile = fileName;
isUntitled = false;
}
//физически документ в текстовой области изменился, ведь открыт новый файл,
//но логически - нет, сам документ еще не менялся, его только что открыли
textEdit->document()->setModified(false);
setWindowModified(false);
setWindowFilePath(curFile);//установит имя файла как заголовок окна
}

//sdasd
