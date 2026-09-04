/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <ApplicationController.h>
#include <Logger.h>
#include <SimulationClock.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_NeuroMind()
{
    qmlRegisterTypesAndRevisions<ApplicationController>("NeuroMind", 1);
    qmlRegisterTypesAndRevisions<Logger>("NeuroMind", 1);
    qmlRegisterTypesAndRevisions<SimulationClock>("NeuroMind", 1);
    qmlRegisterModule("NeuroMind", 1, 0);
}

static const QQmlModuleRegistration registration("NeuroMind", qml_register_types_NeuroMind);
