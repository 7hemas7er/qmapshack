/**********************************************************************************************
    Copyright (C) 2018 Oliver Eichler oliver.eichler@gmx.de

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

#ifndef CRTOPENSKYRECORD_H
#define CRTOPENSKYRECORD_H

#include "gis/trk/CTrackData.h"
#include "realtime/IRtRecord.h"
#include "realtime/opensky/CRtOpenSky.h"

class CRtOpenSkyRecord : public IRtRecord
{
    Q_OBJECT
public:
    CRtOpenSkyRecord(QObject * parent);
    virtual ~CRtOpenSkyRecord() = default;

    void reset() override;
    bool setFile(const QString& filename) override;
    bool writeEntry(const CRtOpenSky::aircraft_t &aircraft);
    void draw(QPainter& p, const QPolygonF& viewport, QList<QRectF>& blockedAreas, CRtDraw * rt) override;

    const QVector<CTrackData::trkpt_t>& geTrack() const
    {
        return track;
    }

protected:
    using IRtRecord::writeEntry;
    bool readEntry(QByteArray& data) override;

    QVector<CTrackData::trkpt_t> track;
};

#endif //CRTOPENSKYRECORD_H
