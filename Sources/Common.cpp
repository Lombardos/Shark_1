#include "Common.h"

Common *Common::m_pInstance = nullptr;

//================//
// PUBLIC METHODS //
//================//


/* Sleep by Robin
Common::Common()
    : m_ErrorText(QString(""))
    , m_ViewIndex(0)
    , m_SwipeIndex(0)
    , modbusObj(ModbusObj::getInstance())
    , m_CurrentTab(0)
    , m_AppVersion(QString::number(VER_MAJOR) + "." + QString::number(VER_MINOR) + "." + QString::number(VER_MICRO))
    , m_AppEngine(nullptr)
{
    connect(modbusObj, &ModbusObj::errorTextChanged, this, &Common::setErrorText);
}
*/


Common::~Common()
{}


/* Sleep by Robin
Common *Common::getInstance()
{
    if (m_pInstance == nullptr)
        m_pInstance = new Common();
    return m_pInstance;
}
*/

QString Common::errorText() const
{
    return m_ErrorText;
}

void Common::setAppEngine(QQmlApplicationEngine *engine)
{
    m_AppEngine = engine;
}

void Common::setCurrentPage(QString page, int viewIndex)
{
    if (m_AppEngine == nullptr)
        return;

    QObject* rootObj = m_AppEngine->rootObjects().first();
    if (rootObj == nullptr)
        return;

    QObject* pageObj = rootObj->findChild<QObject*>(page, Qt::FindChildrenRecursively);
    if (pageObj != nullptr)
    {
        m_CurrentTab = pageObj->property("pageIndex").toInt();
        QObject* listObj = pageObj->findChild<QObject*>("servicePagesList", Qt::FindChildrenRecursively);
        if (listObj != nullptr)
        {
            listObj->setProperty("currentIndex", viewIndex);
        }
        emit currentTabChanged();
    }
}

int Common::currentTab() const
{
    return m_CurrentTab;
}

void Common::setWinWidth(int value)
{
    m_winWidth = value;
    emit winWidthChanged(m_winWidth);
}

void Common::setWinHeight(int value)
{
    m_winHeight = value;
    emit winHeightChanged(m_winHeight);
}

void Common::setViewIndex(int index)
{
    if (m_ViewIndex != index)
    {
        m_ViewIndex = index;
        emit viewIndexChanged(m_ViewIndex);
    }
}

void Common::setSwipeIndex(int index)
{
    if (m_SwipeIndex != index)
    {
        m_SwipeIndex = index;
        emit swipeIndexChanged(m_SwipeIndex);
    }
}

//==============//
// PUBLIC SLOTS //
//==============//

void Common::setErrorText(QString value)
{
    m_ErrorText = value;
    emit errorTextChanged();
}

void Common::setCurrentTab(int value)
{
    m_CurrentTab = value;
    emit currentTabChanged();
}

//=====================================//
// QML SIGLETON TYPE PROVIDER FUNCTION //
//=====================================//
/*  Sleep by Robin
QObject *common_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return Common::getInstance();
}
*/
