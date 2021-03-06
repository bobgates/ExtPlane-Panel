#ifndef PANELITEMFACTORY_H
#define PANELITEMFACTORY_H

#include "panelitems/panelitem.h"
#include <QString>
#include <QStringList>
#include "panelitems/airspeedindicator.h"
#include "panelitems/compass.h"
#include "panelitems/variometer.h"
#include "panelitems/altimeter.h"
#include "panelitems/di.h"
#include "panelitems/hsi_ks55.h"
#include "panelitems/attitudeindicator.h"
#include "panelitems/turnbank.h"
#include "panelitems/button.h"
#include "panelitems/engine_rpm.h"


#include "extplaneconnection.h"

class PanelItemFactory
{
public:
    PanelItemFactory(ExtPlaneConnection *conn);
    PanelItem *itemForName(QString name, QObject *parentObject);
    QStringList itemNames();
private:
    ExtPlaneConnection *connection;
};

#endif // PANELITEMFACTORY_H
