#ifndef UICONTROL_H
#define UICONTROL_H

#include <QObject>

class UiControlPrivate;

class UiControl : public QObject
{
    Q_OBJECT
public:
    explicit UiControl(QObject *parent = 0);
    ~UiControl();
    void show();

private:
    Q_DECLARE_PRIVATE(UiControl)
    UiControlPrivate * const d_ptr;

public slots:
    void BottonClick(QString);
};

#endif // UICONTROL_H
