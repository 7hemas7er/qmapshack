/**********************************************************************************************
    Copyright (C) 2014 Oliver Eichler oliver.eichler@gmx.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************************/

#ifndef IDEVICE_H
#define IDEVICE_H

#include <QDir>
#include <QTreeWidgetItem>

class CGisDraw;

class IDevice : public QTreeWidgetItem
{
public:
    IDevice(const QString& path, const QString& key, QTreeWidget * parent);
    virtual ~IDevice();

    const QString& getKey() const
    {
        return key;
    }

    void drawItem(QPainter& p, const QPolygonF &viewport, QList<QRectF>& blockedAreas, CGisDraw * gis);
    void drawLabel(QPainter& p, const QPolygonF &viewport, QList<QRectF>& blockedAreas, const QFontMetricsF& fm, CGisDraw * gis);
    void drawItem(QPainter& p, const QRectF& viewport, CGisDraw * gis);

protected:
    QDir dir;
    QString key;
};

#endif //IDEVICE_H

