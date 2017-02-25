#include "uicontrol.h"

#include <QQuickView>
#include <QTranslator>
#include <QGuiApplication>
#include <QQuickItem>
#include <QQmlContext>

/*!
 * \brief The UiControlPrivate class
 */
class UiControlPrivate
{
public:
    Q_DECLARE_PUBLIC(UiControl)
    explicit UiControlPrivate(UiControl *q);
    ~UiControlPrivate();
    void show() { mView->show(); }
    bool loadTranslator(QString&);
    void init();

private:
    UiControl* const q_ptr;
    QQuickView* mView;
    QTranslator* mTranslator;

    void connect();
};

/******************************************************************************/
/*!
 * \brief UiControlPrivate::UiControlPrivate
 * \param q
 */
UiControlPrivate::UiControlPrivate(UiControl *q)
    : q_ptr(q)
    , mView(new QQuickView)
    , mTranslator(new QTranslator(q))
{
}

/******************************************************************************/
/*!
 * \brief UiControlPrivate::~UiControlPrivate
 */
UiControlPrivate::~UiControlPrivate()
{
    delete mView;
}

/******************************************************************************/
/*!
 * \brief UiControlPrivate::loadTranslator
 * \param(in) locale : qmlから発行される切り替えロケール文字
 * \return true:正常終了 / false:異常終了
 */
bool UiControlPrivate::loadTranslator(QString& locale)
{
    QString qmfile;
    bool isRet;

    if (locale == QString("ja_JP"))
        qmfile = qApp->applicationName() + QString("_ja_JP");
    else if (locale == QString("zh_CN"))
        qmfile = qApp->applicationName() + QString("_zh_CN");
    else
        qmfile = qApp->applicationName() + QString("_en_US");

    isRet = mTranslator->load(qmfile,":/i18n");
    if (!isRet)
        qDebug() << "Translator load error:" << qmfile;

    qApp->installTranslator(mTranslator);
    ///@todo : あれ？？？ QMLの表示言語がかわらない？？？

    return isRet;
}

/******************************************************************************/
/*!
 * \brief UiControlPrivate::init
 */
void UiControlPrivate::init()
{
    /// QML側へ UiControl classをセットする
    mView->rootContext()->setContextProperty("UiControl", q_ptr);
    /// QMLファイルを設定
    mView->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    /// signal /slot接続
    connect();
}

/******************************************************************************/
/*!
 * \brief UiControlPrivate::connect
 */
void UiControlPrivate::connect()
{
    Q_Q(UiControl);

    QObject* pObj = mView->rootObject()->findChild<QObject*>("qml_item");
    q->connect(pObj, SIGNAL(qmlBottonClick(QString)),q, SLOT(BottonClick(QString)) );
}


/******************************************************************************/
/*!
 * \brief UiControl::UiControl
 * \param parent
 */
UiControl::UiControl(QObject *parent)
    : QObject(parent)
    , d_ptr(new UiControlPrivate(this))
{
    Q_D(UiControl);

    d->init();
}

/******************************************************************************/
/*!
 * \brief UiControl::~UiControl
 */
UiControl::~UiControl()
{
    delete d_ptr;
}

/******************************************************************************/
/*!
 * \brief UiControl::show
 *          QML GUIの表示
 */
void UiControl::show()
{
    Q_D(UiControl);

    d->show();
}

/******************************************************************************/
/*!
 * \brief UiControl::BottonClick
 *          QML側からのボタンクリック[slot]
 * \param(in) locale : qmlから発行される切り替えロケール文字
 */
void UiControl::BottonClick(QString locale)
{
    Q_D(UiControl);

    d->loadTranslator(locale);
}
