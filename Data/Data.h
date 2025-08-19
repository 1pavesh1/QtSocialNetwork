#ifndef DATA_H
#define DATA_H

#include <QDataStream>
#include <QDebug>

class Data
{
public:
    explicit Data() = default;
    virtual ~Data() = default;

    virtual void serialize(QDataStream &out) const = 0;
    virtual void deserialize(QDataStream &in) = 0;
};

inline QDataStream &operator<<(QDataStream &out, const Data &dataType)
{
    dataType.serialize(out);
    return out;
}

inline QDataStream &operator>>(QDataStream &in, Data &dataType)
{
    dataType.deserialize(in);
    return in;
}

#endif // DATA_H
