#ifndef UNITS_H
#define UNITS_H

#include <QString>

enum VelocityUnit {
    VELOCITY_UNKNOWN = 0,
    VELOCITY_MS,
    VELOCITY_KMH,
    VELOCITY_KTS,
    VELOCITY_FPM
};

enum DistanceUnit {
    DISTANCE_UNKNOWN = 0,
    DISTANCE_M,
    DISTANCE_FT
};
enum PressureUnit {
    PRESSURE_UNKNOWN = 0,
    PRESSURE_PA,
    PRESSURE_HPA,
    PRESSURE_INCHES_HG
};

class Units {
public:
    Units();
    static double convertSpeed(VelocityUnit from, VelocityUnit to, double value);
    static double convertDistance(DistanceUnit from, DistanceUnit to, double value);
    static double convertPressure(PressureUnit from, PressureUnit to, double value);
    static QString unitName(VelocityUnit unit);
    static QString unitName(DistanceUnit unit);
    static QString unitName(PressureUnit unit);
    static VelocityUnit velocityUnitForName(QString name);
    static DistanceUnit distanceUnitForName(QString name);
    static PressureUnit pressureUnitForName(QString name);
};

#endif // UNITS_H
