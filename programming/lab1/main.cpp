#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
QTextCodec* codec;
#if defined(Q_OS_WIN)
codec = QTextCodec::codecForName("CP1251");//кодровка Windows
#elif defined(Q_OS_UNIX)
codec = QTextCodec::codecForName("UTF-8");//кодровка UNIX
#endif//можно добавить варианты и для других ОС
QTextCodec::setCodecForLocale(codec);
QApplication app(argc, argv);
MainWindow mainWin;//объект созданного класса
mainWin.show();//после вызова метода окно появится на экране
return app.exec();//начать цикл обработки сообщений
}
