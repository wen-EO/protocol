#ifndef HWIDGETDEFINE_H
#define HWIDGETDEFINE_H


#include <QIcon>
#include<QString>
typedef struct HWIDGET_PLU_INFO
{
    QString  pluId;                        //编号
    QString  pluName;                      //名称
    QString  pluCategory;                  //类型(主显协议、设备协议、备显协议)
    QString  pluCreateUser;                //创建人
    QString  pluCreateTime;                //创建时间
    QString  pluDescription;               //描述
    QString  pluVersion;                   //版本号

    QIcon    pluIcon;                      //插件图标
    QString  pluType;                      //插件分类
    void    *pluClass;                     //插件界面对象(pulgin)
}hWidget_plu_info;

typedef struct CATEGORY_INFO
{
    QString  categoryId;                   //编号
    QString  categoryName;                 //名称
    QString  categoryDescription;          //描述
}category_info;

enum ItemDataUserRoleCategory {
    // Reserved
    CategoryId = Qt::UserRole+1,
    CategoryName = Qt::UserRole+2,
    CategoryDescription = Qt::UserRole+3
};

enum ItemDataUserRoleProtocol {
    // Reserved
    ProtocolId = Qt::UserRole+1,
    ProtocolName = Qt::UserRole+2,
    ProtocolChnName = Qt::UserRole+3,
    ProtocolCategory = Qt::UserRole+4,
    ProtocolVersion = Qt::UserRole+5,
    ProtocolCreateUser = Qt::UserRole+6,
    ProtocolCreateTime = Qt::UserRole+7,
    ProtocolDescription = Qt::UserRole+8
};

enum ItemDataUserRoleDataType {
    // Reserved
    DataTypeId = Qt::UserRole+1,
    DataTypeProtocolId = Qt::UserRole+2,
    DataTypeName = Qt::UserRole+3,
    DataTypeSigned = Qt::UserRole+4,
    DataTypeSystemDataType = Qt::UserRole+5
};

enum ItemDataUserRoleStruct {
    // Reserved
    StructId = Qt::UserRole+1,
    StructName = Qt::UserRole+2,
    StructDescription = Qt::UserRole+3,
    StructMark = Qt::UserRole+4
};

enum ItemDataUserRoleStructDetail {
    // Reserved
    StructDetailId = Qt::UserRole+1,
    StructDetailProtocolId = Qt::UserRole+2,
    StructDetailStructId = Qt::UserRole+3,
    StructDetailDataTypeId = Qt::UserRole+4,
    StructDetailDataTypeName = Qt::UserRole+5,
    StructDetailBit = Qt::UserRole+6,
    StructDetailName = Qt::UserRole+7,
    StructDetailDescription = Qt::UserRole+8,
    StructDetailRange = Qt::UserRole+9,
    StructDetailDefaultValue = Qt::UserRole+10,
    StructDetailQuantization = Qt::UserRole+11
};

#endif // HWIDGETDEFINE_H
