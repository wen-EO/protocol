#ifndef PROJECTBUILD_H
#define PROJECTBUILD_H

#include "hwidgetdefine.h"
#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QScrollArea>
#include <QModelIndex>
#include <QStandardItemModel>
#include "exportfile.h"

// 前向声明TreeModel类（避免头文件循环包含）
class TreeModel;

namespace Ui {
// Ui命名空间下的ProjectBuild类，由Qt Designer生成
class ProjectBuild;
}

/**
 * @class ProjectBuild
 * @brief 项目构建相关的主窗口类
 * @details 继承自QWidget，负责项目中协议、数据类型、结构体等的管理与编辑
 */
class ProjectBuild : public QWidget
{
    Q_OBJECT  // Qt元对象系统宏，支持信号与槽机制

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针，默认为nullptr
     */
    explicit ProjectBuild(QWidget *parent = 0);

    /**
     * @brief 析构函数
     */
    ~ProjectBuild();

protected:
    /**
     * @brief 重绘事件处理函数
     * @param event 绘图事件对象
     * @details 用于自定义窗口绘制逻辑
     */
    void paintEvent(QPaintEvent *);

private slots:
    // treeView相关槽函数（响应树视图的交互事件）
    void on_treeView_clicked(const QModelIndex &index);  // 树视图点击事件
    void on_treeView_customContextMenuRequested(const QPoint &pos);  // 树视图右键菜单请求
    void on_treeView_showEditTypeContextMenu();  // 显示编辑类型的右键菜单
    void on_treeView_showDeleteTypeContextMenu();  // 显示删除类型的右键菜单
    void on_treeView_showImportXMLContextMenu();  // 显示导入XML的右键菜单
    void on_treeView_showEditProtocolContextMenu();  // 显示编辑协议的右键菜单
    void on_treeView_showDeleteProtocolContextMenu();  // 显示删除协议的右键菜单
    void on_treeView_showExportProtocolContextMenu();  // 显示导出协议的右键菜单
    void on_treeView_showExportXMLContextMenu();  // 显示导出XML的右键菜单

    // 数据类型相关按钮点击事件
    void on_btn_AddDataType_clicked();  // "添加数据类型"按钮点击
    void on_btn_EditDataType_clicked();  // "编辑数据类型"按钮点击
    void on_btn_DeleteDataType_clicked();  // "删除数据类型"按钮点击

    // listView相关槽函数
    void on_listView_clicked(const QModelIndex &index);  // 列表视图点击事件

    // 另一组数据类型相关按钮点击事件（可能对应不同区域的操作）
    void on_btn_AddDataType_2_clicked();
    void on_btn_EditDataType_2_clicked();
    void on_btn_DeleteDataType_2_clicked();

    // 导入相关按钮点击事件
    void on_btn_Import_clicked();  // "导入"按钮点击

    // 协议与结构体相关按钮点击事件
    void on_btn_CreateProtocol_clicked();  // "创建协议"按钮点击
    void on_btn_CreateStruct_clicked();  // "创建结构体"按钮点击
    void on_btn_DeleteStruct_clicked();  // "删除结构体"按钮点击
    void on_btnCreateType_clicked();  // "创建类型"按钮点击
    void on_btn_ExportProtocol_clicked();//导出按钮被点击

    /**
     * @brief 获取分类信息的槽函数
     * @param id 分类ID
     * @param name 分类名称
     * @param description 分类描述
     */
    void getCategoryInfo(QString id, QString name, QString description);



private:
    /**
     * @brief 初始化函数
     * @details 用于窗口初始化设置，如控件初始化、信号槽连接等
     */
    void init();

    // 模型初始化相关函数
    void set_treeView_model();  // 初始化树视图的数据模型
    void set_dataType_model();  // 初始化数据类型的数据模型

    // 列表初始化相关函数
    void init_PortocolList();  // 初始化协议列表
    void init_dataTypeList(QString prototcolId);  // 根据协议ID初始化数据类型列表
    void init_structList(QString prototcolId);  // 根据协议ID初始化结构体列表
    void init_structDetailList(QString structId);  // 根据结构体ID初始化结构体详情列表

    /**
     * @brief 导出XML文件
     * @param filepath 导出文件路径
     */
    void exportXml(QString filepath);

    /**
     * @brief 导出协议文件
     * @param pathExport 导出路径
     */
    void exportProtocol(QString pathExport);

    // 成员变量
    int index;  // 通用索引变量（用途需结合实现判断）
    int m_index_struct;  // 结构体相关索引

    ExportFile *ac;  // 导出文件操作对象指针

private:
    Ui::ProjectBuild *ui;  // UI界面对象指针（关联Qt Designer设计的界面）

    // 数据模型指针
    TreeModel* m_model=nullptr;  // 主树视图模型
    TreeModel* m_model_dataType=nullptr;  // 数据类型树模型
    QStandardItemModel *m_listModel = nullptr;  // 标准列表模型
    QStandardItem *item = nullptr;  // 标准列表项（可能用于临时存储）

    TreeModel* m_model_struct=nullptr;  // 结构体树模型
    TreeModel* m_model_struct_dataType=nullptr;  // 结构体数据类型树模型

    // 窗口交互相关变量
    QWidget *m_movewgt=nullptr;  // 可移动窗口指针
    QPoint last;  // 记录上次鼠标位置（用于窗口拖动）
    bool isSelected=false;  // 是否选中状态标记
    QList<QMainWindow*> mainwndlst;  // 主窗口列表
    QList<QScrollArea*> mainarealst;  // 滚动区域列表
    int plgIndex=0;  // 插件索引

    // 分类相关信息
    QString categoryId;  // 分类ID
    QString categoryName;  // 分类名称
    QString categoryDescription;  // 分类描述

    // 当前插件相关信息
    QString currentPlgId;  // 当前插件ID
    QString currentPlgName;  // 当前插件名称
    QIcon currentPlgIcon;  // 当前插件图标
    QString currentPlgCategory;  // 当前插件分类
    QString currentPlgType;  // 当前插件类型
    QString currentPlgVersion;  // 当前插件版本

    // 协议相关信息
    QString m_protocol_id;  // 当前协议ID

    // 其他标识信息
    QString m_category_entity_id;  // 分类实体ID
    int m_listRow;  // 列表行数

public:
    std::list<hWidget_plu_info *> m_wndList;  // 插件窗口信息列表（存储插件相关窗口数据）
};

#endif // PROJECTBUILD_H
