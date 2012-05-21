/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QEVDEVMOUSEMANAGER_H
#define QEVDEVMOUSEMANAGER_H

#include "qevdevmousehandler.h"

#include <QtPlatformSupport/private/qdevicediscovery_p.h>

#include <QObject>
#include <QHash>
#include <QSocketNotifier>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QEvdevMouseManager : public QObject
{
    Q_OBJECT
public:
    explicit QEvdevMouseManager(const QString &key, const QString &specification);
    ~QEvdevMouseManager();

public slots:
    void handleMouseEvent(int x, int y, Qt::MouseButtons buttons);

private slots:
    void addMouse(const QString &deviceNode = QString());
    void removeMouse(const QString &deviceNode);

private:
    QString m_spec;
    QHash<QString,QEvdevMouseHandler*> m_mice;
    QDeviceDiscovery *m_deviceDiscovery;
    int m_x;
    int m_y;
    int m_xoffset;
    int m_yoffset;
};

QT_END_HEADER

QT_END_NAMESPACE

#endif // QEVDEVMOUSEMANAGER_H
