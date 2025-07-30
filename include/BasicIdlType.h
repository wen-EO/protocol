#ifndef ULINX_BASICIDLTYPE_H
#define ULINX_BASICIDLTYPE_H

#include <QString>
#include <QFile>
#include <QStringList>
#include <QVector>
#include <QMap>
#include <unordered_map>

struct DataMember
{
    QString DataNote;
    QString DataType;
    QString DataName;
};

struct StructInfo
{
    QString              StructName;
    QStringList          StructNote;
    QList<DataMember>    StructDataMember;
};

typedef QVector<StructInfo> _STRUCT_VECTOR_T;
//typedef std::unordered_map<QString,StructInfo> _STRUCT_MAP_T;

#endif // BASICIDLTYPE_H
