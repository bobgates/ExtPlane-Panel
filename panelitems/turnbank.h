/*
 *  turnbank.h
 *  extplane-panel
 *
 *  Created by bobgates on 2011/07/10.
 *  Copyright 2011 DaffeySoft. All rights reserved.
 *
 */

#ifndef TURNBANK_H
#define TURNBANK_H

#include <QLabel>
#include "../widgets/distanceunitcombobox.h"
#include "../extplaneclient.h"
#include "panelitem.h"
#include "../units.h"
#include "widgets/numberinputlineedit.h"

class TurnAndBank : public PanelItem
{
    Q_OBJECT
public:
    TurnAndBank(QObject *parent, ExtPlaneConnection *conn);
    virtual void storeSettings(QSettings &settings);
    virtual void loadSettings(QSettings &settings);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QString typeName();
    static QString typeNameStatic();
    virtual void createSettings(QGridLayout *layout);
    void setLabel(QString text);
    void setBars(float thick, float thin);
    public slots:
    void refChanged(QString name, double alt);
    void setUnit(DistanceUnit un);
    void setRange1(float v);
    void setRange2(float v);
    void setThickBars(float v);
    void setThinBars(float v);
    void setNumbersScale(float v);
    void setNumbers(float div);
private:
    void createCard(void);
    void createFrame(void);
    void createGlass(void);
    void createBall(void);
    
    float value2Angle1(float value);
    float value2Angle2(float value);
    ExtPlaneClient _client;
    DistanceUnit units;
    PressureUnit baroUnits;
    float _range1, _range2, _value;
    float _thickBars, _thinBars, _numbers;
    float _numbersScale;
    float _baroPressure;
    
    static const float maxRoll=70;
    static const float maxOffbalance=7.5;
    
    float _slipValue;
    float _rollValue;
    QString _label;
    QString _rollRef;
    QString _slipRef;
    QPixmap _card;
    QPixmap _frame;
    QPixmap _glass;
    QPixmap _ball;
    QPixmap _bezel;
    
};

#endif // TURNBANK_H
