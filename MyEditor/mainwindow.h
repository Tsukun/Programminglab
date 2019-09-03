#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT // показывает, что класс будет использовать
    // особенности класса QObject, такие как сигналы
    // и слоты
public: MainWindow(QWidget *parent = nullptr);
protected:
    // переопределяем функцию (реакция на закрытие окна)
    // базового класса
    void closeEvent(QCloseEvent *event);
private slots: //слоты для соединения графического
    // интерфейса и логики работы
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();
private:
    /*в этом примере создание элементов интерфейса не стали
доверять редактору */
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    // функции чтения/записи настроек приложения
    void readSettings();
    void writeSettings();
    // функции для работы с файлами
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    /* описание всех элементов интерфейса и вспомогательных
членов класса (отказ от применения визуального редактора
позволяет избежать соблазна не давать элементам
осмысленных имен!)*/
    QPlainTextEdit *textEdit;
    QString curFile; // имя ткущего файла
    bool isUntitled; // флаг показывает, ввел ли пользовтель
    // имя файла, или используется по
    // умолчанию
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif // MAINWINDOW_H
