#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QIcon>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon(QLatin1String(":/Image/logo.ico")));


    // 注册矢量图标库
    QFontDatabase::addApplicationFont(QLatin1String(":/Font/fontawesome-webfont.ttf"));
    QFontDatabase::addApplicationFont(QLatin1String(":/Font/STXIHEI.TTF"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}