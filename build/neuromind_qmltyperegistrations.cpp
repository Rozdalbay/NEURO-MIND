/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <NeuralNetworkItem.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_NeuroMind()
{
    qmlRegisterTypesAndRevisions<NeuralNetworkItem>("NeuroMind", 1);
    qmlRegisterAnonymousType<QQuickItem, 254>("NeuroMind", 1);
    qmlRegisterModule("NeuroMind", 1, 0);
}

static const QQmlModuleRegistration registration("NeuroMind", qml_register_types_NeuroMind);
