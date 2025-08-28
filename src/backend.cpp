#include "backend.h"

#include <QDebug>
#include <QRandomGenerator>

Backend::Backend(QObject *parent) : QObject(parent) {}

void Backend::addBalance(int amount) {
    m_balance += amount;
    emit balanceChanged();
}

void Backend::subtractBalance(int amount) {
    if (m_balance >= amount) {
        m_balance -= amount;
        emit balanceChanged();
    } else {
        qDebug() << "INSUFFICIENT FUNDS";
    }
}

QStringList Backend::spinSlots() {
    static const QStringList symbols = { "1", "2", "3", "4", "5" };
    QStringList result;
    for (int ii = 0; ii < 3; ii++) {
        int idx = QRandomGenerator::global()->bounded(symbols.size());
        result << symbols[idx];
    }
    if (result[0] == result[1] && result[1] == result[2]) {
        addBalance(300);
    } else if (result[0] == result[1] || result[1] == result[2] || result[0] == result[2]) {
        addBalance(100);
    } else {
        subtractBalance(100);
    }
    return result;
}