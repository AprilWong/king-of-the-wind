# 风力贴图生成器
[English](./English_README.md)

## 需求

通过指定二维贴图上某几个点的风力信息，通过该风力贴图生成程序计算得到整个二维贴图的风的信息，生成的风力贴图用于风力系统模块（已有初步解决方案）中的某些计算

## 风的模型

- 方向
- 强度

## 输入

- 某些点的气压值
    - 指定二维贴图上某一点的气压值
    - 气压值的大小间接反映了风的方向

- 区域强度
    - 修改某一区域的强度值
    - 强度影响气压图上等压线的密集程度
    - 区域强度图可以直接输出
## 输出

- 气压变化
    - 风向（vector2）
- 区域强度

## 核心功能
- 输入某两个点的气压值和基础气压值，生成整张图的气压值
- 由气压值计算出风向
- 可视化风向以及风的强度

## 任意点气压值的计算
### 计算方法

U' = U + Σ ((U<sub>i</sub> - U) / d)

### 理论依据

气压的变化来自于温度，理想气体等压面和等温面是同一平面，热传导功率和距离成反比，和温度差成正比，如果将气体看作理想气体的话，任意点的气压值即满足U' = U + Σ ((U<sub>i</sub> - U) / d)的关系。


## 风的强度的计算
理论情况下，风的强度与气压图中等压线的密度有关，但是为了美术能更加直观地进行贴图的创建，因此我们只从气压图中得到风的方向，而由美术另外指定一张风的强度贴图。

## 计算结果的储存
最终生成的结果储存在一张二维贴图中，由A通道储存风的强度，RG通道储存风在某点处的矢量方向。
    
## 参考资料
- [https://www.geogebra.org/material/show/id/3051](https://www.geogebra.org/material/show/id/3051)
- [http://www.falstad.com/vector/](http://www.falstad.com/vector/)
- [https://help.scilab.org/champ](https://help.scilab.org/champ)
- [http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf](http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf)
- [https://www.cg.inf.ethz.ch/teaching/scivis_common/Literature/HelmanHesselink91.pdf](http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf)
- [http://repository.cmu.edu/cgi/viewcontent.cgi?article=1394&context=psychology](http://repository.cmu.edu/cgi/viewcontent.cgi?article=1394&context=psychology)
- [http://www-users.cs.umn.edu/~interran/francesca06.pdf](http://www-users.cs.umn.edu/~interran/francesca06.pdf)
- [http://www3.nd.edu/~cwang11/research/vis13-tutorial-weiskopf.pdf](http://www3.nd.edu/~cwang11/research/vis13-tutorial-weiskopf.pdf)

## 参考实例
- [https://www.windyty.com](https://www.windyty.com)

## 修订记录
2016.7.12 创建

----

最近更新: 2016.7.13

增加任意点气压值的计算方法及其理论依据
