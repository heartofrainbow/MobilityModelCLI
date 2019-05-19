/*• 作者：武尚玮 微信：heartofrainbow
 * */
#include <iostream>
#include "mobilitymodel.h"
using  namespace std;

int main() {
//    mobilitymodel("rwp",5,0,100,0,100,0,100,0,20,2.0);
//    参数：模型类型，节点数目，XMIN,XMAX,YMIN,YMAX,ZMIN,ZMAX,VMIN,VMAX,interval
    //最后一个参数interval可省略，如果省略则默认为2.0秒。这个参数在不同模型中有不同的意义。
    //在随机走动模型中表示节点更新速度和方向的时间间隔，在随机方向移动模型中表示节点更新运动方向的时间间隔，
    //在随机路点移动模型中表示节点运动到目标地点后停留的时间，在高斯-马尔科夫模型则没有此参数。
    mobilitymodel("gm",6,0,0,0,0,0,1,0,100,15,3.14,1.57,0.5);
    //参数：模型类型(gm)，节点数目，XMIN,XMAX,YMIN,YMAX,ZMIN,ZMAX,VMIN,VMAX,VMEAN,DMEAN,DMEAN,alpha

    return 0;
}