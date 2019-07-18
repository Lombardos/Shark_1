#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QQmlEngine>
#include <QTimer>
#include <QQmlApplicationEngine>
//#include "Connection/ModbusObj.h" // sleep of Robin

#define VER_MAJOR 1
#define VER_MINOR 1
#define VER_MICRO 1

class Common  : public QObject {
    Q_OBJECT

public:
    explicit Common();
    ~Common();

    enum OnOffState {
        OFF,
        ON,
        UNDEFINE
    };
    Q_ENUM(OnOffState)

    static Common *getInstance();

    Q_PROPERTY(QString errorText READ errorText WRITE setErrorText NOTIFY errorTextChanged)
    Q_PROPERTY(int currentTab READ currentTab WRITE setCurrentTab NOTIFY currentTabChanged)

    Q_PROPERTY(int winWidth READ winWidth WRITE setWinWidth NOTIFY winWidthChanged)
    Q_PROPERTY(int winHeight READ winHeight WRITE setWinHeight NOTIFY winHeightChanged)

    Q_PROPERTY(int viewIndex READ viewIndex WRITE setViewIndex NOTIFY viewIndexChanged)

    Q_PROPERTY(int swipeIndex READ swipeIndex WRITE setSwipeIndex NOTIFY swipeIndexChanged)

    Q_PROPERTY(QString appVersion READ appVersion NOTIFY appVersionChanged)

    Q_INVOKABLE void setCurrentPage(QString page, int viewIndex);

    QString errorText() const;

    int winWidth() const { return m_winWidth; }
    int winHeight() const { return m_winHeight; }

    int viewIndex() const { return m_ViewIndex; }

    int swipeIndex() const { return m_SwipeIndex; }

    QString appVersion() const { return m_AppVersion; }

    int currentTab() const;

    void setWinWidth(int value);
    void setWinHeight(int value);

    void setViewIndex(int index);

    void setSwipeIndex(int index);

    void setAppEngine(QQmlApplicationEngine *engine);

signals:
    void errorTextChanged();

    void winWidthChanged(int);
    void winHeightChanged(int);

    void viewIndexChanged(int);

    void swipeIndexChanged(int);

    void currentTabChanged();

    void appVersionChanged(QString);

public slots:
    void setErrorText(QString value);
    void setCurrentTab(int value);

private:
    QString m_ErrorText;
    int m_winWidth, m_winHeight;
    int m_ViewIndex;
    int m_SwipeIndex;
//    ModbusObj *modbusObj; // sleep of Robin
    int m_CurrentTab;
    QString m_AppVersion;
    QQmlApplicationEngine *m_AppEngine;
    static Common *m_pInstance;
};

#endif // COMMON_H
