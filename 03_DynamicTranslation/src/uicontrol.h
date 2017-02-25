#ifndef UICONTROL_H
#define UICONTROL_H

#include <QObject>

class UiControlPrivate;

class UiControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qtr READ qtr NOTIFY languageChanged)
public:
    explicit UiControl(QObject *parent = 0);
    ~UiControl();
    void show();
    QString qtr(){return QString();}

private:
    Q_DECLARE_PRIVATE(UiControl)
    UiControlPrivate * const d_ptr;

signals:
    void languageChanged();

public slots:
    void BottonClick(QString);
};

#endif // UICONTROL_H
