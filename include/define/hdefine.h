#ifndef HDEFINE_H
#define HDEFINE_H
namespace HDefine {

enum{
    H_UI_Title = 1,                       //插件为工具插件,用与插入titlebar.
    H_UI_PRO  = 2,                       //插件为工程插件,用与插入工程.
    H_UI_FUNCTION  = 3                   //插件为功能栏插件,用户左边功能选择区域.
};


typedef struct NodeInfo
{
    QString _ip;
    QString _hostName;
    QString _nodeName;
    QString _nodeStatus;
    NodeInfo()
    {
        _ip = "10.0.0.1";
        _hostName = "admin";
        _nodeName = "";
        _nodeStatus = "0";//0正常;-1异常;1未知
    }

}HNodeInfo;

}

#endif // HDEFINE_H
