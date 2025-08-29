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
    static const QMap<int, QString> symbolMap = {
        {0, "qrc:/images/bell.png"},
        {1, "qrc:/images/cherry.png"},
        {2, "qrc:/images/gem.png"},
        {3, "qrc:/images/lemon.png"},
        {4, "qrc:/images/seven.png"}
    };

    const int spinCost = 100;
    if (m_balance < spinCost) { // TODO: fix
        qDebug() << "INSUFFICIENT FUNDS";
        return {};
    }

    subtractBalance(spinCost);

    QVector<int> resultIds;
    for (int ii = 0; ii < 3; ii++) {
        int idx = QRandomGenerator::global()->bounded(symbolMap.size());
        resultIds << idx;
    }
    if (resultIds[0] == resultIds[1] && resultIds[1] == resultIds[2]) {
        addBalance(300);
    } else if (resultIds[0] == resultIds[1] || resultIds[1] == resultIds[2] || resultIds[0] == resultIds[2]) {
        addBalance(100);
    }
    QStringList result;
    for (int id : resultIds) {
        result << symbolMap.value(id);
    }
    return result;
}
