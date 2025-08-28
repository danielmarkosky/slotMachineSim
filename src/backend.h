#pragma once

#include <QObject>
#include <QString>

class Backend : public QObject {
    Q_OBJECT
    Q_PROPERTY(int balance READ balance NOTIFY balanceChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    int balance() const { return m_balance; }
    Q_INVOKABLE void addBalance(int amount);
    Q_INVOKABLE void subtractBalance(int amount);
    Q_INVOKABLE QStringList spinSlots();

signals:
    void balanceChanged();

private:
    int m_balance = 1000;
};