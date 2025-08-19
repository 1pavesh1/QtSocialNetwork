/****************************************************************************
** Meta object code from reading C++ file 'AddPostWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AddPostWindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddPostWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13AddPostWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto AddPostWindow::qt_create_metaobjectdata<qt_meta_tag_ZN13AddPostWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AddPostWindow",
        "closeSignal",
        "",
        "DurationChanged",
        "duration",
        "PositionChanged",
        "on_deleteFileInputButton_clicked",
        "on_addPostButton_clicked",
        "on_addMediaButton_clicked",
        "on_timeAudioSlider_valueChanged",
        "value",
        "on_playAudioButton_clicked",
        "on_volumeAudioButton_clicked",
        "on_volumeAudioSlider_valueChanged",
        "on_playVideoButton_clicked",
        "on_volumeVideoButton_clicked",
        "on_timeVideoSlider_valueChanged",
        "on_volumeVideoSlider_valueChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'closeSignal'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'DurationChanged'
        QtMocHelpers::SlotData<void(const qint32 &)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'PositionChanged'
        QtMocHelpers::SlotData<void(const qint32 &)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'on_deleteFileInputButton_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_addPostButton_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_addMediaButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_timeAudioSlider_valueChanged'
        QtMocHelpers::SlotData<void(qint32)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'on_playAudioButton_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumeAudioButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumeAudioSlider_valueChanged'
        QtMocHelpers::SlotData<void(qint32)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'on_playVideoButton_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumeVideoButton_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_timeVideoSlider_valueChanged'
        QtMocHelpers::SlotData<void(qint32)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'on_volumeVideoSlider_valueChanged'
        QtMocHelpers::SlotData<void(qint32)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AddPostWindow, qt_meta_tag_ZN13AddPostWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AddPostWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddPostWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddPostWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AddPostWindowE_t>.metaTypes,
    nullptr
} };

void AddPostWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AddPostWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->closeSignal(); break;
        case 1: _t->DurationChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 2: _t->PositionChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 3: _t->on_deleteFileInputButton_clicked(); break;
        case 4: _t->on_addPostButton_clicked(); break;
        case 5: _t->on_addMediaButton_clicked(); break;
        case 6: _t->on_timeAudioSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 7: _t->on_playAudioButton_clicked(); break;
        case 8: _t->on_volumeAudioButton_clicked(); break;
        case 9: _t->on_volumeAudioSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 10: _t->on_playVideoButton_clicked(); break;
        case 11: _t->on_volumeVideoButton_clicked(); break;
        case 12: _t->on_timeVideoSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 13: _t->on_volumeVideoSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AddPostWindow::*)()>(_a, &AddPostWindow::closeSignal, 0))
            return;
    }
}

const QMetaObject *AddPostWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddPostWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddPostWindowE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddPostWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void AddPostWindow::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
